/**
 * @file Grammar.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Grammar.
 * Se define la clase Grammar con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "grammar.h"

#include <fstream>
#include <assert.h>
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

  // Producciones
  getline(archivo, linea);
  int nProductions = linea.at(0) - 48;
  for (int i = 0; i < nProductions; i++) {
    getline(archivo, linea);
    std::vector<std::string> splittedLine(SplitChainGrammar(linea));
    std::vector<Symbol> auxSymbolVector;
    for (auto symbol : splittedLine.at(2)) {
      std::string auxString;
      auxString.push_back(symbol);
      Symbol auxSymbol(auxString);
      auxSymbolVector.push_back(auxSymbol);
    }
    ProductionRule auxProductionRule(splittedLine.at(0),auxSymbolVector);
    addProductionRule(auxProductionRule);
  }
}

Grammar::Grammar() {}

Grammar::Grammar(Grammar& paramGrammar) : 
  terminalSymbol_(paramGrammar.terminalSymbol_), 
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
  productionRules_.insert(paramProduction);
}

void Grammar::addTerminalSymbol(Symbol paramSymbol) {
  terminalSymbol_.insert(paramSymbol);
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

void Grammar::operator=(const Grammar& paramGrammar) {
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
  for (auto pr : paramGrammar.productionRules_)
    os << pr << "\n";

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