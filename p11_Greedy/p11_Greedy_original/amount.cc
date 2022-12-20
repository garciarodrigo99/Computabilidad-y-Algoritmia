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

#include "amount.h"
#include <iostream>
#include <list>
#include <set>
#include <vector>

Amount::Amount() {}

Amount::~Amount() {}

void Amount::insert(Cash *cash) { amount_.push_back(cash); }

/**
 * @brief Sobrecarga operador '<<' para escritura del objeto
 *
 * @param os
 * @param paramGreedyMoneyChange
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Amount amount) {

  Cash *element = amount.amount_.front();
  int sum = 0;
  // std::vector<std::pair<int,int>> cuenta;
  // cuenta.push_back(std::pair<int,int>(element,0));
  os << "Solución: ";
  for (auto i : amount.amount_) {
    if (*i != *element) {
      if (sum > 1)
        os << sum << "x";
      element->print(os);
      os << ", ";

      element = i;
      sum = 0;
    }
    sum++;
  }
  if (sum > 1)
    os << sum << "x";
  element->print(os);
  os << "\nTotal monedas o billetes: " << amount.amount_.size() << std::endl;
  return os;
}