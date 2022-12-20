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

#include "cash.h"
#include "coin.h"
#include "note.h"
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

private:
  std::list<Cash *> amount_;
};