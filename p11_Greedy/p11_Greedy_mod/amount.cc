/**
 * @file amount.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Fichero de implementación de la clase Amount.
 * Se define la clase Amount con sus métodos y atributos
 * @version 2.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#include "amount.h"
#include <iostream>
#include <list>
#include <set>
#include <vector>

Amount::Amount() {}

Amount::~Amount() {}

void Amount::insert(Cash *cash) { amount_.push_back(cash); }

int Amount::getSize() { return amount_.size(); }

/**
 * @brief Metodo que cuenta los elementos unicos de una cantidad a devolver
 * 
 * @return std::list<Cash *> 
 */
std::list<Cash *> Amount::uniqueCash() {
  std::list<Cash *> cashList;
  for (auto i : amount_) {
    if (!findElement(i,cashList))
      cashList.push_back(i);
  }
  return cashList;
}

bool Amount::findElement(Cash * elemento, std::list<Cash *> lista) {
  bool comparison = false;
  for (auto j : lista) {
    if (*j == *elemento) {
      comparison = true;
      break;
    }
  }
  return comparison;
}

int Amount::countCash(Cash *elemento) {
  int sum = 0;
  if (!findElement(elemento,amount_))
    return 0;
    
  for (auto i : amount_) {
    if (*i == *elemento)
      sum++;
  }
  return sum;
}

Cash * Amount::mostFrequent() {
  int sum = 0;
  Cash* mostFrequent;
  for (auto i : uniqueCash()) {
    int elementCount = countCash(i);
    if (elementCount > sum) {
      sum = elementCount;
      mostFrequent = i;
    }
  }
  return mostFrequent;
}

void Amount::operator=(const Amount paramChain) {
  for (auto i : paramChain.amount_)
    amount_.push_back(i);
}

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
  // os << "\nTotal monedas o billetes: " << amount.amount_.size() << std::endl;
  return os;
}