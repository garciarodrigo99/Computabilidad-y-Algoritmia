/**
 * @file automata.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Fichero de implementación de la clase Automata.
 * Se define la clase Automata con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "automata.h"

#include <assert.h>
#include <fstream>
#include <map>
#include <string>

Automata::Automata(std::string fileName) {
  std::ifstream archivo(fileName.c_str());
  std::string linea;

  // Simbolos alfabeto
  getline(archivo, linea);
  for (size_t i = 0; i < SplitChain(linea).size(); i++)
    alphabet_.AddSymbol(SplitChain(linea).at(i));

  // Simbolos numero estados automata
  getline(archivo, linea);
  int nStates = linea.at(0) - 48;

  // Estado arranque
  getline(archivo, linea);
  int initialState = linea.at(0) - 48;
  std::vector<std::vector<std::string>>
      statesInformation; // Parte del fichero descripcion estados

  getline(archivo, linea);
  statesInformation.push_back(SplitChain(linea));
  // Identificador y si es estado final
  assert(std::stoi(SplitChain(linea).at(0)) == initialState);
  State automataIntialState_(std::stoi(SplitChain(linea).at(0)));
  State aux(automataIntialState_.getIdentifier());
  stateSet_.insert(aux);
  if (std::stoi(SplitChain(linea).at(1)) == 1)
    finalStateSet_.insert(aux.getIdentifier());

  for (int iteratorLine = 1; iteratorLine < nStates; iteratorLine++) {
    getline(archivo, linea);
    statesInformation.push_back(SplitChain(linea));
    // Identificador y si es estado final
    State auxState(std::stoi(SplitChain(linea).at(0)));
    // Insertar estado en conjunto

    if (std::stoi(SplitChain(linea).at(1)) == 1)
      addState(auxState, 1);
    else
      addState(auxState);
  }

  for (size_t iteratorStates = 0; iteratorStates < statesInformation.size();
       iteratorStates++) {
    int nTransitions = std::stoi(statesInformation.at(iteratorStates).at(2));
    int positions = 3;
    for (int i = 0; i < nTransitions; i++) {

      int originId = std::stoi(statesInformation.at(iteratorStates).at(0));
      int destinationId =
          std::stoi(statesInformation.at(iteratorStates).at(positions + 1));
      addTransition(originId,
                    Symbol(statesInformation.at(iteratorStates).at(positions)),
                    destinationId);
      positions += 2;
    }
  }
  // archivo.close();
}

/**
 * @brief Construct a new Automata:: Automata object
 *
 * @param paramAlphabet
 * @param paramInitialState
 */
Automata::Automata(Alphabet paramAlphabet, State paramInitialState,
                   int finalState)
    : alphabet_(paramAlphabet),
      automataIntialState_(paramInitialState.getIdentifier()) {
  stateSet_.insert(paramInitialState);
  if (finalState == 1)
    finalStateSet_.insert(paramInitialState.getIdentifier());
}

/**
 * @brief Destroy the Automata:: Automata object
 *
 */
Automata::~Automata() {}

/**
 * @brief Metodo para analizar si una cadena es aceptada o rechazada por
 * cualquier automata
 *
 * @param paramChain Cadena a analizar
 * @return true - La cadena es aceptada.
 * @return false - La cadena es rechazada.
 */
bool Automata::acceptChain(Chain paramChain) {
  // assert(alphabet_.okChain(paramChain));
  if (!(alphabet_.okChain(paramChain)))
    return false;

  std::set<State> actualStates;
  actualStates.insert(automataIntialState_);
  for (int chainIterator = 0; chainIterator < paramChain.Size();
       chainIterator++) {
    std::set<State> nextStates;
    for (std::set<State>::iterator stateIterator = actualStates.begin();
         stateIterator != actualStates.end(); stateIterator++) {
      std::set<State> transitionSet;
      if (isTransition(*stateIterator, paramChain.Position(chainIterator)))
        transitionSet =
            (getStatesSet(*stateIterator, paramChain.Position(chainIterator)));
      nextStates.insert(transitionSet.begin(), transitionSet.end());
    }
    actualStates = nextStates;
  }
  return containsFinalState(actualStates);
}

/**
 * @brief Metodo para añadir un estado al automata
 *
 * @param paramState Estado a añadir
 */
void Automata::addState(State paramState, int finalState) {
  stateSet_.insert(paramState);
  if (finalState == 1)
    finalStateSet_.insert(paramState.getIdentifier());
}

/**
 * @brief Metodo que añade transiciones al automata. Se comprueba que ambos
 * estados pertenecen al conjunto de estados del automata y que el simbolo
 * pertenece al Alfabeto
 *
 * @param actualStateId Estado origen
 * @param paramSymbol Simbolo
 * @param nextStateId Estado destino
 */
void Automata::addTransition(int actualStateId, Symbol paramSymbol,
                             int nextStateId) {
  assert(isState(actualStateId));
  assert(isState(nextStateId));
  assert(alphabet_.inSymbol(paramSymbol));
  State originState(getState(actualStateId));
  State destinationState(getState(nextStateId));
  Transition auxTransition(actualStateId, paramSymbol, nextStateId);
  trFunction_.insert(auxTransition);
}

/**
 * @brief Metodo que recibe el conjunto de estados en los que se encuentra el
 * automata al leer el ultimo simbolo de una cadena, y comprueba si alguno de
 * estos estados es de aceptacion.
 *
 * @param paramStatesSet Conjunto de estados
 * @return true - Alguno de los ultimos estados es de aceptacion.
 * @return false - Ninguno de los ultimos estados es de aceptacion.
 */
bool Automata::containsFinalState(std::set<State> paramStatesSet) {
  for (std::set<State>::iterator it = paramStatesSet.begin();
       it != paramStatesSet.end(); it++) {
    if (isFinalState(*it))
      return true;
  }
  return false;
}

bool Automata::isDFA() {
  for (auto state : stateSet_) {
    for (auto symbol : alphabet_.getSymbols()) {
      if (getStatesSet(state, symbol).size() != 1)
        return false;
    }
  }
  return true;
}

Grammar Automata::convertToGrammar() {
  assert(isDFA());
  Grammar dfaGrammar;
  // Crear simbolos terminales
  for (auto alphabetSymbol : alphabet_.getSymbols()) {
    dfaGrammar.addTerminalSymbol(alphabetSymbol);
  }
  // Crear simbolos no terminales
  std::map<int, std::string> mapStateNonTerminalSymbol;
  for (auto states : stateSet_) {
    char nonTerminalSymbolId = (char)(states.getIdentifier() + 65);
    std::string string_id;
    string_id.push_back(nonTerminalSymbolId);
    dfaGrammar.addNonTerminalSymbol(string_id);
    if (isFinalState(states)) {
      Chain emptychain;
      Symbol nonTerminalSymbol(string_id);
      ProductionRule auxProdRule(nonTerminalSymbol, emptychain);
      dfaGrammar.addProductionRule(auxProdRule);
    }
    mapStateNonTerminalSymbol.insert({states.getIdentifier(), string_id});
  }
  if (auto search = mapStateNonTerminalSymbol.find(automataIntialState_);
      search != mapStateNonTerminalSymbol.end())
    dfaGrammar.setStartSymbol(search->second);

  for (auto transition : trFunction_) {
    std::vector<Symbol> auxVectorSymbol;
    auxVectorSymbol.push_back(transition.getSymbol());
    if (auto search = mapStateNonTerminalSymbol.find(
            transition.getDestinationState().getIdentifier());
        search != mapStateNonTerminalSymbol.end()) {
      Symbol auxSymbol(search->second);
      auxVectorSymbol.push_back(auxSymbol);
    }

    if (auto search = mapStateNonTerminalSymbol.find(
            transition.getOriginState().getIdentifier());
        search != mapStateNonTerminalSymbol.end()) {
      Symbol auxSymbol(search->second);
      ProductionRule auxProdRule(auxSymbol, auxVectorSymbol);
      dfaGrammar.addProductionRule(auxProdRule);
    }
  }
  return dfaGrammar;
}

bool Automata::isFinalState(State paramState) {
  if (finalStateSet_.count(paramState.getIdentifier()) > 0)
    return true;
  return false;
}

/**
 * @brief A través de un identificador, devuelve el objeto estado con el
 * identificador dado
 *
 * @param stateIdentifyer Identificador de estado
 * @return State Estado con stateIdentifyer
 */
State Automata::getState(int stateIdentifyer) {
  for (std::set<State>::iterator it = stateSet_.begin(); it != stateSet_.end();
       ++it) {
    if (it->getIdentifier() == stateIdentifyer)
      return *it;
  }
  return 0; // Evitar warning
}

/**
 * @brief Metodo que retorna un conjunto de estados a los que transita el
 * estado paramState dado un simbolo paramSymbol
 *
 * @param paramState Estado origen
 * @param paramSymbol Simbolo
 * @return std::set<State> Conjunto de siguientes estados
 */
std::set<State> Automata::getStatesSet(State paramState, Symbol paramSymbol) {
  assert(isTransition(paramState, paramSymbol));
  std::set<State> auxSet;
  for (std::set<Transition>::iterator it = trFunction_.begin();
       it != trFunction_.end(); ++it) {
    if ((it->getOriginState() == paramState) &&
        (it->getSymbol() == paramSymbol))
      auxSet.insert(it->getDestinationState());
  }
  return auxSet; // Evitar warning
}

/**
 * @brief Comprueba si el identificador parametro se corresponde con algun
 * identificador del conjunto de estados del automata.
 *
 * @param stateIdentifyer Identificador a buscar
 * @return true - El identificador coincide con el identificador de algun
 * estado del conjunto de estados del automata.
 * @return false - El identificador no coincide con el identificador de algun
 * estado del conjunto de estados del automata..
 */
bool Automata::isState(int stateIdentifyer) {
  for (std::set<State>::iterator it = stateSet_.begin(); it != stateSet_.end();
       it++) {
    if (it->getIdentifier() == stateIdentifyer)
      return true;
  }
  return false;
}

/**
 * @brief Metodo que comprueba si para un estado y simbolo dado existe
 * alguna transicion
 *
 * @param paramState Estado
 * @param paramSymbol Simbolo
 * @return true - Existe transicion.
 * @return false - No transicion.
 */
bool Automata::isTransition(State paramState, Symbol paramSymbol) {
  for (std::set<Transition>::iterator it = trFunction_.begin();
       it != trFunction_.end(); ++it) {
    if ((it->getOriginState() == paramState) &&
        (it->getSymbol() == paramSymbol))
      return true;
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de escritura
 *
 * @param os
 * @param paramFTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Automata &paramFTransition) {
  os << "Alfabeto: " << paramFTransition.alphabet_ << "\n";

  os << ">";
  if (paramFTransition.isFinalState(paramFTransition.automataIntialState_))
    os << "((" << paramFTransition.automataIntialState_ << ")) ";
  else
    os << "(" << paramFTransition.automataIntialState_ << ") ";

  for (std::set<State>::iterator it = ++paramFTransition.stateSet_.begin();
       it != paramFTransition.stateSet_.end(); ++it) {
    if (paramFTransition.isFinalState(*it))
      os << "((" << *it << ")) ";
    else
      os << "(" << *it << ") ";
  }
  std::endl(os);
  for (auto tr : paramFTransition.trFunction_)
    os << tr << "\n";

  return os;
}

/**
 * @brief Funcion auxiliar, que dada una cadena, normalmente, devuelve un
 * vector de cadenas que elimina los espacios
 *
 * @param str Cadena a partir
 * @param pattern Caracter a eliminar
 * @return std::vector<std::string> Vector de cadenas
 */
std::vector<std::string> SplitChain(std::string str, char pattern) {

  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  return results;
}