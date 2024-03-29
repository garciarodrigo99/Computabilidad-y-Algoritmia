/**
 * @file productionRule.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase productionRule.
 * Se define la clase productionRule con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 */

#include "cadena.h"
#include "simbolo.h"

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
  Chain getChain() const;
  Chain getChain();
  Symbol getNonFinalSymbol() const;
  Symbol getNonFinalSymbol();
  int getType(std::set<Symbol>);

  // Sobrecarga de operadores
  bool operator<(const ProductionRule) const;
  void operator=(const ProductionRule);
  bool operator==(const ProductionRule) const;
  friend std::ostream &operator<<(std::ostream &, ProductionRule &);
  friend std::ostream &operator<<(std::ostream &, const ProductionRule &);
  
private:
  Symbol nonTerminalSymbol_;
  Chain chain_;
};