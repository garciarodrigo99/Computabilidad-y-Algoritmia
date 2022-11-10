/**
 * @file transicion.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase Transition.
 * Se define la clase Transition con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "simbolo.h"

#include <iostream>
#include <vector>

class ProductionRule {

public:
  // Constructores y destructor
  ProductionRule(Symbol, std::vector<Symbol>);
  ~ProductionRule();

  // Getters y setters
  Symbol getNonFinalSymbol() const;
  std::vector<Symbol> getProduction() const;

  // Sobrecarga de operadores
  bool operator<(const ProductionRule) const;
  friend std::ostream &operator<<(std::ostream &, ProductionRule &);
  friend std::ostream &operator<<(std::ostream &, const ProductionRule &);

private:
  Symbol nonFinalSymbol_;
  std::vector<Symbol> production_;
};