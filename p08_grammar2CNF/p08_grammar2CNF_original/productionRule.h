/**
 * @file productionRule.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Cabecera de la clase productionRule.
 * Se define la clase productionRule con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "simbolo.h"
#include "cadena.h"

#include <iostream>
#include <set>
#include <vector>

class ProductionRule {

public:
  // Constructores y destructor
  ProductionRule(Symbol, Chain);
  ProductionRule(Symbol, Symbol);
  ~ProductionRule();

  // Getters y setters
  Symbol getNonFinalSymbol() const;
  // std::vector<Symbol> getSymbolVector() const;
  Chain getChain();
  int getType(std::set<Symbol>);

  // Sobrecarga de operadores
  bool operator<(const ProductionRule) const;
  bool operator==(const ProductionRule) const;
  void operator=(const ProductionRule);
  friend std::ostream &operator<<(std::ostream &, ProductionRule &);
  friend std::ostream &operator<<(std::ostream &, const ProductionRule &);

private:
  Symbol nonTerminalSymbol_;
  Chain chain_;
  int type;
};