/**
 * @file grammar.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Cabecera de la clase grammar.
 * Se define la clase grammar con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "cadena.h"
#include "productionRule.h"
#include "simbolo.h"

#include <iostream>
#include <set>

#pragma once

class Grammar {

public:
  // Constructores y destructores
  Grammar();
  Grammar(std::string);
  Grammar(Grammar &); // Copia
  ~Grammar();

  // Operaciones
  bool acceptChain(Chain);
  void addNonTerminalSymbol(Symbol);
  void addProductionRule(ProductionRule);
  void addTerminalSymbol(Symbol);
  bool isRegular();
  void setStartSymbol(std::string);
  void writeFile(std::string);

  // Sobrecarga de operadores
  void operator=(const Grammar &);
  friend std::ostream &operator<<(std::ostream &, Grammar &);

private:
  int getNProductions(Symbol);

private:
  // Alphabet alphabet_;
  std::set<Symbol> terminalSymbol_;
  std::set<Symbol> nonTerminalSymbol_;
  std::string startSymbolId_;
  std::vector<ProductionRule> productionRules_;
};

std::vector<std::string> SplitChainGrammar(std::string str, char pattern = ' ');