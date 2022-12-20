/**
 * @file note.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Cabecera y fichero de implementación de la clase hija de Cash, Coin.
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

// static std::set<int> const CoinSet({50000,20000,10000,5000,2000,1000,500});

class Coin : public Cash {
public:
  // Constructores y destructores
  Coin(int amount) {
    assert(coinSet.count(amount) != 0);
    amount_ = amount;
  }

  ~Coin() {}

  void print(std::ostream &) const {
    if (amount_ < 100) {
      std::cout << amount_ << "¢";
      return;
    }
    int printAmount = amount_ / 100;
    std::cout << printAmount << "€";
  }
  friend std::ostream &operator<<(std::ostream &, const Coin &);
  static std::set<int> const coinSet;
  operator int(void) const { return amount_; }

private:
  int amount_;
};

inline std::ostream &operator<<(std::ostream &os, const Coin &myCoin) {
  myCoin.print(os); // delegate the work to a polymorphic member function.
  return os;
}

inline std::set<int> const Coin::coinSet({200, 100, 50, 20, 10, 5, 2, 1});