/**
 * @file cash.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Cabecera y fichero de implementación de la clase padre Cash.
 * Se define la clase Cash con sus métodos y atributos
 * Se hace de esta manera ya que al trabajar con herencia y no utilizar espacio
 * de nombres se ha de desarrollar todo en un mismo fichero .h
 * @version 2.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 */

#pragma once
#include <iostream>
#include <set>
#include <string>

// static std::set<int> const coinSet({200,100,50,20,10,5,2,1});
// static std::set<int> const noteSet({50000,20000,10000,5000,2000,1000,500});

class Cash {
public:
  // Constructores y destructores
  // Cash();
  // virtual ~Cash() = 0;
  virtual void print(std::ostream &) const = 0;
  virtual operator int(void) const = 0;
  friend std::ostream &operator<<(std::ostream &, const Cash &);
};

inline std::ostream &operator<<(std::ostream &os, const Cash &myCash) {
  myCash.print(os); // delegate the work to a polymorphic member function.
  return os;
}