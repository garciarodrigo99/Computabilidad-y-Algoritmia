/**
 * @file automata.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Automata.
 * Se define la clase Automata con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "automata.h"

#include <fstream>
#include <assert.h>
#include <string>

//Automata::Automata() {}

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

  std::vector<std::vector<std::string>> statesInformation;  // Parte del fichero descripcion estados

  getline(archivo, linea);
  statesInformation.push_back(SplitChain(linea));
  // Identificador y si es estado final
  assert(std::stoi(SplitChain(linea).at(0)) == initialState);

  State automataIntialState_(std::stoi(SplitChain(linea).at(0)));
  if (std::stoi(SplitChain(linea).at(1)) == 1)
    automataIntialState_.setFinalState();

  addState(initialState);

  for (int iteratorLine = 1; iteratorLine < nStates; iteratorLine++) {
    getline(archivo, linea);
    statesInformation.push_back(SplitChain(linea));
    // Identificador y si es estado final
    State auxState(std::stoi(SplitChain(linea).at(0)));
    if (std::stoi(SplitChain(linea).at(1)) == 1)
      auxState.setFinalState();
    // Insertar estado en conjunto
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
      addTransition(
          originId, Symbol(statesInformation.at(iteratorStates).at(positions)),
          destinationId);
      positions += 2;
    }
  }
}

/**
 * @brief Construct a new Automata:: Automata object
 *
 * @param paramAlphabet
 * @param paramInitialState
 */
Automata::Automata(Alphabet paramAlphabet, State paramInitialState)
    : alphabet_(paramAlphabet), automataIntialState_(paramInitialState) {
  stateSet_.insert(paramInitialState);
  if (paramInitialState.isFinalState())
    finalStateSet_.insert(paramInitialState);
}

/**
 * @brief Destroy the Automata:: Automata object
 *
 */
Automata::~Automata() {}

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
      if (trFunction_.isTransition(*stateIterator,
                                   paramChain.Position(chainIterator)))
        transitionSet = (trFunction_.getStatesSet(
            *stateIterator, paramChain.Position(chainIterator)));
      nextStates.insert(transitionSet.begin(), transitionSet.end());
    }
    actualStates = nextStates;
  }
  return containsFinalState(actualStates);
}

bool Automata::containsFinalState(std::set<State> paramStatesSet) {
  for (std::set<State>::iterator it = paramStatesSet.begin();
       it != paramStatesSet.end(); it++) {
    if (finalStateSet_.count(*it) > 0)
      return true;
  }
  return false;
}

void Automata::addTransition(int actualStateId, Symbol paramSymbol,
                             int nextStateId) {
  assert(isState(actualStateId));
  assert(isState(nextStateId));
  assert(alphabet_.inSymbol(paramSymbol));
  State originState(getState(actualStateId));
  State destinationState(getState(nextStateId));
  Transition auxTransition(actualStateId, paramSymbol, nextStateId);
  trFunction_.addTransition(auxTransition);
}

bool Automata::isState(int stateIdentifyer) {
  for (std::set<State>::iterator it = stateSet_.begin();
      it != stateSet_.end(); it++) {
        if (it->getIdentifier() == stateIdentifyer) return true;
  }
  return false;
}

State Automata::getState(int stateIdentifyer) {
  for (std::set<State>::iterator it = stateSet_.begin(); it != stateSet_.end();
       ++it) {
    if (it->getIdentifier() == stateIdentifyer)
      return *it;
  }
  return 0; // Evitar warning
}

void Automata::addState(State paramState) {
  stateSet_.insert(paramState);
  if (paramState.isFinalState())
    finalStateSet_.insert(paramState);
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
  if (paramFTransition.automataIntialState_.isFinalState())
    os << "((" << paramFTransition.automataIntialState_ << ")) ";
  else
    os << "(" << paramFTransition.automataIntialState_ << ") ";

  for (std::set<State>::iterator it = ++paramFTransition.stateSet_.begin();
       it != paramFTransition.stateSet_.end(); ++it) {
    if (it->isFinalState())
      os << "((" << *it << ")) ";
    else
      os << "(" << *it << ") ";
  }
  std::endl(os);
  os << paramFTransition.trFunction_ << "\n";
  return os;
}

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