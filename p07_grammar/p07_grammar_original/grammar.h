#include "simbolo.h"
#include "cadena.h"
#include "productionRule.h"

#include <iostream>
#include <set>

#pragma once

class Grammar {

public:
  // Constructores y destructores
  Grammar();
  Grammar(std::string);
  Grammar(Grammar&);  // Copia
  ~Grammar();

  // Operaciones
  bool acceptChain(Chain);
  void addNonTerminalSymbol(Symbol);
  void addProductionRule(ProductionRule);
  void addTerminalSymbol(Symbol);
  void setStartSymbol(std::string);
  void writeFile(std::string);

  // Sobrecarga de operadores
  void operator=(const Grammar&);
  friend std::ostream &operator<<(std::ostream &, Grammar &);

private:
  int getNProductions(Symbol);

private:
  //Alphabet alphabet_;
  std::set<Symbol> terminalSymbol_;
  std::set<Symbol> nonTerminalSymbol_;
  std::string startSymbolId_;
  std::vector<ProductionRule> productionRules_;
};

std::vector<std::string> SplitChainGrammar(std::string str, char pattern = ' ');