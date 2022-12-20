/**
 * @file greedy.h
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
#include <list>
#include <set>

#include "amount.h"
#include "cash.h"
#include "coin.h"
#include "note.h"

#pragma once

struct GreedyMoneyChange {
  // Constructores y destructores
  GreedyMoneyChange();
  ~GreedyMoneyChange();

  // Operaciones
  std::list<int> returnChange(int) const;
  Amount returnChangeAmount(int) const;
  int biggestElementLessThanSum(std::set<int>, int) const;
};