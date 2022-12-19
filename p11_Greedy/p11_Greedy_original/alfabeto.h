/**
 * @file alfabeto.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase GreedyMoneyChange.
 * Se define la clase GreedyMoneyChange con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

//#include "cadena.h"

#include <iostream>
#include <set>
#include <list>
#include "simbolo.h"
#include "coin.h"
#include "note.h"

#pragma once

class GreedyMoneyChange {
public:
  // Constructores y destructores
  GreedyMoneyChange();
  GreedyMoneyChange(const GreedyMoneyChange &); // Copia

  // Getters y setters

  // // Iteradores
  // std::set<Symbol>::const_iterator begin() const;
  // std::set<Symbol>::const_iterator end() const;

  // Operaciones
  std::list<int> returnChange(int) const;
  int biggestElementLessThanSum(std::set<int>,int) const;

  // Sobrecarga de operadores
  bool operator<(const GreedyMoneyChange) const;
  friend std::ostream &operator<<(std::ostream &, GreedyMoneyChange &);

private:
  //std::set<Symbol> GreedyMoneyChange_;
};