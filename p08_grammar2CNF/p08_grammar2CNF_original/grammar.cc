/**
 * @file Grammar.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Fichero de implementación de la clase Grammar.
 * Se define la clase Grammar con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "grammar.h"

#include <assert.h>
#include <fstream>
#include <string>

Grammar::Grammar(std::string fileName) {
  std::ifstream archivo(fileName.c_str());
  std::string linea;

  // Simbolos terminales
  getline(archivo, linea);
  int nTerminalSymbol = linea.at(0) - 48;
  for (int i = 0; i < nTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea.front());
    terminalSymbol_.insert(auxSymbol);
  }

  // Simbolos no terminales
  getline(archivo, linea);
  int nNonTerminalSymbol = linea.at(0) - 48;
  for (int i = 0; i < nNonTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea.front());
    nonTerminalSymbol_.insert(auxSymbol);
  }

  //@To-Do
  // Asignar simbolo no terminal de arranque
  getline(archivo, linea);
  for (auto symbol : linea) {
    startSymbolId_.push_back(symbol);
  }
  // std::cout << "Simbolo de arranque: " << startSymbolId_ << std::endl;

  // Producciones
  getline(archivo, linea);
  int nProductions = linea.at(0) - 48;
  for (int i = 0; i < nProductions; i++) {
    getline(archivo, linea);
    std::vector<std::string> splittedLine(SplitChainGrammar(linea));
    std::vector<Symbol> auxSymbolVector;
    if ((splittedLine.at(2).size() == 1) &&
        (splittedLine.at(2).at(0) == kEmptyChain)) {
      Symbol emptyChain(kEmptyChain);
      auxSymbolVector.push_back(emptyChain);
    } else {
      for (auto symbol : splittedLine.at(2)) {
        std::string auxString;
        auxString.push_back(symbol);
        Symbol auxSymbol(auxString);
        auxSymbolVector.push_back(auxSymbol);
      }
    }
    ProductionRule auxProductionRule(splittedLine.at(0), auxSymbolVector);
    addProductionRule(auxProductionRule);
  }
}

Grammar::Grammar() {}

Grammar::Grammar(Grammar &paramGrammar)
    : terminalSymbol_(paramGrammar.terminalSymbol_),
      nonTerminalSymbol_(paramGrammar.nonTerminalSymbol_),
      startSymbolId_(paramGrammar.startSymbolId_),
      productionRules_(paramGrammar.productionRules_) {}

/**
 * @brief Destroy the Grammar:: Grammar object
 *
 */
Grammar::~Grammar() {}

/**
 * @brief Metodo para analizar si una cadena es aceptada o rechazada por
 * cualquier Grammar
 *
 * @param paramChain Cadena a analizar
 * @return true - La cadena es aceptada.
 * @return false - La cadena es rechazada.
 */
bool Grammar::acceptChain(Chain paramChain) {
  // // assert(alphabet_.okChain(paramChain));
  // if (!(alphabet_.okChain(paramChain)))
  //   return false;

  // std::set<State> actualStates;
  // actualStates.insert(GrammarIntialState_);
  // for (int chainIterator = 0; chainIterator < paramChain.Size();
  //      chainIterator++) {
  //   std::set<State> nextStates;
  //   for (std::set<State>::iterator stateIterator = actualStates.begin();
  //        stateIterator != actualStates.end(); stateIterator++) {
  //     std::set<State> transitionSet;
  //     if (trFunction_.isTransition(*stateIterator,
  //                                  paramChain.Position(chainIterator)))
  //       transitionSet = (trFunction_.getStatesSet(
  //           *stateIterator, paramChain.Position(chainIterator)));
  //     nextStates.insert(transitionSet.begin(), transitionSet.end());
  //   }
  //   actualStates = nextStates;
  // }
  // return containsFinalState(actualStates);
  return false;
}

void Grammar::addNonTerminalSymbol(Symbol paramSymbol) {
  nonTerminalSymbol_.insert(paramSymbol);
}

void Grammar::setStartSymbol(std::string paramString) {
  startSymbolId_ = paramString;
}

/**
 * @brief Metodo que añade transiciones al Grammar. Se comprueba que ambos
 * estados pertenecen al conjunto de estados del Grammar y que el simbolo
 * pertenece al Alfabeto
 *
 * @param actualStateId Estado origen
 * @param paramSymbol Simbolo
 * @param nextStateId Estado destino
 */
void Grammar::addProductionRule(ProductionRule paramProduction) {
  assert(nonTerminalSymbol_.count(paramProduction.getNonFinalSymbol()) != 0);
  productionRules_.push_back(paramProduction);
}

void Grammar::addTerminalSymbol(Symbol paramSymbol) {
  terminalSymbol_.insert(paramSymbol);
}

void Grammar::writeTypes() {
  bool status = true;
  for (auto pr : productionRules_) {
    std::cout << pr;
    switch (pr.getType(nonTerminalSymbol_)){
      case -1:
        std::cout << " : No regular." << std::endl;
        break;
      case 0:
        std::cout << " : Regular ambos lados." << std::endl;
        break;
      case 1:
        std::cout << " : Regular por la izquierda." << std::endl;
        break;

      case 2:
        std::cout << " : Regular por la derecha." << std::endl;
        break;
      
      default:
        break;
    }
    if (pr.getType(nonTerminalSymbol_) == -1)
      status = false;
  }
}

bool Grammar::isRegular() {
  bool status = true;
  for (auto pr : productionRules_) {
    if (pr.getType(nonTerminalSymbol_) == -1)
      status = false;
  }
  return status;
}

void Grammar::writeFile(std::string outputFile) {
  std::ofstream file(outputFile);
  std::string line;
  file << terminalSymbol_.size() << "\n";
  for (auto symbol : terminalSymbol_)
    file << symbol << "\n";
  file << nonTerminalSymbol_.size() << "\n";
  for (auto symbol : nonTerminalSymbol_)
    file << symbol << "\n";
  file << startSymbolId_ << "\n";
  file << productionRules_.size() << "\n";
  for (auto pr : productionRules_)
    file << pr << "\n";
  file.close();
}

int Grammar::getNProductions(Symbol paramSymbol) {
  assert(nonTerminalSymbol_.count(paramSymbol) != 0);
  int count = 0;
  for (auto production : productionRules_) {
    if (paramSymbol == production.getNonFinalSymbol())
      count++;
  }
  return count;
}

void Grammar::operator=(const Grammar &paramGrammar) {
  terminalSymbol_ = paramGrammar.terminalSymbol_;
  nonTerminalSymbol_ = paramGrammar.nonTerminalSymbol_;
  startSymbolId_ = paramGrammar.startSymbolId_;
  productionRules_ = paramGrammar.productionRules_;
}

/**
 * @brief Sobrecarga del operador de escritura
 *
 * @param os
 * @param paramFTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Grammar &paramGrammar) {
  std::cout << "Simbolo de arranque: " << paramGrammar.startSymbolId_
            << std::endl;

  for (auto symbol : paramGrammar.nonTerminalSymbol_) {
    int productionsNumber = paramGrammar.getNProductions(symbol);
    if (productionsNumber > 0) {
      os << symbol << " -> ";
      int iterator = 0;
      for (auto production : paramGrammar.productionRules_) {
        if (production.getNonFinalSymbol() == symbol) {
          for (auto vectorSymbol : production.getSymbolVector())
            os << vectorSymbol;
          if ((productionsNumber - 1) > iterator)
            os << " | ";
          iterator++;
        }
      }
      os << "\n";
    }
  }
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
std::vector<std::string> SplitChainGrammar(std::string str, char pattern) {

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