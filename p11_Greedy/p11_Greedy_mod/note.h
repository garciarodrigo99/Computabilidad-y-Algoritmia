/**
 * @file note.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Cabecera y fichero de implementación de la clase hija de Cash, Note.
 * Se define la clase Cash con sus métodos y atributos
 * Se hace de esta manera ya que al trabajar con herencia y no utilizar espacio
 * de nombres se ha de desarrollar todo en un mismo fichero .h
 * @version 2.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 */

#pragma once
#include "cash.h"

#include "assert.h"
#include <iostream>
#include <set>
#include <string>

// static std::set<int> const noteSet({50000,20000,10000,5000,2000,1000,500});

class Note : public Cash {
public:
  // Constructores y destructores
  Note(int amount) {
    assert(noteSet.count(amount) != 0);
    amount_ = amount;
  }

  ~Note() {}

  void print(std::ostream &) const {
    int printAmount = amount_ / 100;
    std::cout << printAmount << "€";
  }
  friend std::ostream &operator<<(std::ostream &, const Note &);
  operator int(void) const { return amount_; }
  static std::set<int> const noteSet;

private:
  int amount_;
};

inline std::ostream &operator<<(std::ostream &os, const Note &myCash) {
  myCash.print(os); // delegate the work to a polymorphic member function.
  return os;
}

inline std::set<int> const Note::noteSet({50000, 20000, 10000, 5000, 2000, 1000,
                                          500});