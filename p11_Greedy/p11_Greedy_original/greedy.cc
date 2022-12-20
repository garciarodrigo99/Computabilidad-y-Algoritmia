/**
 * @file alfabeto.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Se define la clase Symbol con sus métodos y atributos
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Fichero de implementación de la clase GreedyMoneyChange.
 * Se define la clase GreedyMoneyChange con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-22
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

/**
 * @brief
 *
 * @return int - Numero de elementos del alfabeto
 */
std::list<int> GreedyMoneyChange::returnChange(int amount) const {
  std::list<int> solution;
  int sum = 0;

  while (sum != amount) {
    int v = biggestElementLessThanSum(Note::noteSet, (amount - sum));
    if (v == -1) {
      int v = biggestElementLessThanSum(Coin::coinSet, (amount - sum));
      if (v == -1)
        EXIT_FAILURE;
      solution.push_back(v);
      sum = sum + v;
    } else {
      solution.push_back(v);
      sum = sum + v;
    }
  }
  return solution;
}

Amount GreedyMoneyChange::returnChangeAmount(int amount) const {
  std::list<int> solution;
  Amount amountSolution;
  int sum = 0;

  while (sum != amount) {
    int v = biggestElementLessThanSum(Note::noteSet, (amount - sum));
    if (v == -1) {
      int v = biggestElementLessThanSum(Coin::coinSet, (amount - sum));
      if (v == -1)
        EXIT_FAILURE;
      solution.push_back(v);
      amountSolution.insert(new Coin(v));
      sum = sum + v;
    } else {
      solution.push_back(v);
      amountSolution.insert(new Note(v));
      sum = sum + v;
    }
  }
  return amountSolution;
}

/**
 * @brief
 *
 * @return int - Numero de elementos del alfabeto
 */
int GreedyMoneyChange::biggestElementLessThanSum(std::set<int> _set,
                                                 int amount) const {
  int solution = -1;
  for (std::set<int>::iterator it = _set.begin(); it != _set.end(); it++) {
    if (*it > amount)
      return solution;
    solution = *it;
  }
  return solution;
}

// /**
//  * @brief "Sobrecarga" de la función begin para que se pueda recorrer el
//  vector
//  * de simbolos en los for de tipo 'auto'
//  *
//  * @return std::vector<Symbol>::const_iterator Iterador a la primera posicion
//  * de la cadena
//  */
// std::set<Symbol>::const_iterator GreedyMoneyChange::begin() const {
//   return GreedyMoneyChange_.begin();
// }

// /**
//  * @brief "Sobrecarga" de la función begin para que se pueda recorrer el
//  vector
//  * de simbolos en los for de tipo 'auto'
//  *
//  * @return std::vector<Symbol>::const_iterator Iterador a la ultima posicion
//  * de la cadena
//  */
// std::set<Symbol>::const_iterator GreedyMoneyChange::end() const { return
// GreedyMoneyChange_.end(); }

// /**
//  * @brief Sobrecarga operador '<' para poder trabajar clase std::set
//  *
//  * @param paramGreedyMoneyChange Alfabeto candidato a entrar en std::set
//  * @return True - El alfabeto no se encuentra en el conjunto
//  * @return false - El alfabeto se encuentra en el conjunto
//  * @see std::set
//  */
// bool GreedyMoneyChange::operator<(const GreedyMoneyChange
// paramGreedyMoneyChange) const {
//   return ((int)GreedyMoneyChange_.size() < paramGreedyMoneyChange.Size());
// }

// /**
//  * @brief Sobrecarga operador '<<' para escritura del objeto
//  *
//  * @param os
//  * @param paramGreedyMoneyChange
//  * @return std::ostream&
//  */
// std::ostream &operator<<(std::ostream &os, GreedyMoneyChange
// &paramGreedyMoneyChange) {
//   os << "{ ";

//   for (std::set<Symbol>::iterator it =
//   paramGreedyMoneyChange.GreedyMoneyChange_.begin();
//        it != paramGreedyMoneyChange.GreedyMoneyChange_.end(); ++it)
//     std::cout << *it << " ";

//   os << "}";
//   return os;
// }