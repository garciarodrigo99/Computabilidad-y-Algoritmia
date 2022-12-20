/**
 * @file greedy.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Cabecera de la clase Amount.
 * Se define la clase Amount con sus métodos y atributos
 * @version 2.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#include "cash.h"
#include "coin.h"
#include "note.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <set>

#pragma once

class Amount {
public:
  // Constructores y destructores
  Amount();
  ~Amount();

  int getSize();

  // Operaciones
  void insert(Cash *);

  // Sobrecarga de operadores
  friend std::ostream &operator<<(std::ostream &, Amount);
  void operator=(const Amount);

  // private:
  std::list<Cash *> uniqueCash();
  int countCash(Cash *);
  Cash * mostFrequent();

  private:
    bool findElement(Cash *, std::list<Cash *>);

private:
  std::list<Cash *> amount_;
};