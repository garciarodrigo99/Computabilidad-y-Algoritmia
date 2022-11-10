#include "simbolo.h"
#include "cadena.h"
#include "productionRule.h"

#include <iostream>
#include <set>

#pragma once

class Grammar {

public:
  // Constructores y destructores
  //Grammar(Alphabet, State, int);
  Grammar(std::string);
  ~Grammar();

  // Operaciones
  bool acceptChain(Chain);
  void addProductionRule(Symbol, std::vector<Symbol>);

  // Sobrecarga de operadores
  friend std::ostream &operator<<(std::ostream &, Grammar &);

  // Metodos privados
private:
  Symbol getSymbol(int);

private:
  //Alphabet alphabet_;
  std::set<Symbol> terminalSymbol;
  std::set<Symbol> nonTerminalSymbol;
  std::string startSymbol;
  std::set<ProductionRule> productionRules_;
};

std::vector<std::string> SplitChainGrammar(std::string str, char pattern = ' ');