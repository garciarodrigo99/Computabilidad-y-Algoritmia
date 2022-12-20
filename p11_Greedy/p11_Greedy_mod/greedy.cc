/**
 * @file greedy.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Fichero de implementación de la clase GreedyMoneyChange.
 * Se define la clase GreedyMoneyChange con sus métodos y atributos
 * @version 2.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#include "greedy.h"

#include <assert.h>
#include <iostream>
#include <list>

GreedyMoneyChange::GreedyMoneyChange() {}

GreedyMoneyChange::~GreedyMoneyChange() {}

Amount GreedyMoneyChange::returnChangeAmount(int amount, char option) const {
  std::list<int> solution;
  Amount amountSolution;
  int sum = 0;

  // Opcion billete
  if (option == 'b') {
    std::set<int>::reverse_iterator it = Coin::coinSet.rbegin();
    while ((amount - sum) > *Note::noteSet.begin()) {
      int v = biggestElementLessThanSum(Note::noteSet, (amount - sum),it);
      if (v == -1)
        EXIT_FAILURE;
      // solution.push_back(v);
      amountSolution.insert(new Note(v));
      sum = sum + v;
    }
  }

  std::set<int>::reverse_iterator it = Coin::coinSet.rbegin();
  while (sum != amount) {
    int v = biggestElementLessThanSum(Coin::coinSet, (amount - sum), it);
    if (v == -1)
      EXIT_FAILURE;
    // solution.push_back(v);
    amountSolution.insert(new Coin(v));
    sum = sum + v;
  }
  return amountSolution;
}

/**
 * @brief
 *
 * @return int - Numero de elementos del alfabeto
 */
int GreedyMoneyChange::biggestElementLessThanSum(std::set<int> _set,
                                                 int amount, std::set<int>::reverse_iterator& itParam) const {
  int solution = *itParam;
  for (std::set<int>::reverse_iterator iterator = itParam; iterator != _set.rend(); iterator++) {
    itParam = iterator;
    solution = *iterator;
    if (*itParam <= amount)
      return solution;
  }
  return -1;
}