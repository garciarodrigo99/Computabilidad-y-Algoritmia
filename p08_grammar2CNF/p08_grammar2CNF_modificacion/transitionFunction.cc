/**
 * @file transicion.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Fichero de implementación de la clase Transition.
 * Se define la clase Transition con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 */

#include "transitionFunction.h"

#include <assert.h>
#include <iostream>

/**
 * @brief Construct a new Transition Function:: Transition Function object
 * Constructor por defecto
 */
TransitionFunction::TransitionFunction() {}

/**
 * @brief Destroy the Transition Function:: Transition Function object
 *
 */
TransitionFunction::~TransitionFunction() {}

/**
 * @brief Numero de transiciones del objeto
 *
 * @return int
 */
int TransitionFunction::getSize() { return transitionSet_.size(); }

/**
 * @brief Añadir transicion a la funcion de transicion
 *
 * @param paramTransition Transicion a añadir
 */
void TransitionFunction::addTransition(Transition paramTransition) {
  transitionSet_.insert(paramTransition);
}

/**
 * @brief Metodo que comprueba si para un estado y simbolo dado existe
 * alguna transicion
 *
 * @param paramState Estado
 * @param paramSymbol Simbolo
 * @return true - Existe transicion.
 * @return false - No transicion.
 */
bool TransitionFunction::isTransition(State paramState, Symbol paramSymbol) {
  for (std::set<Transition>::iterator it = transitionSet_.begin();
       it != transitionSet_.end(); ++it) {
    if ((it->getOriginState() == paramState) &&
        (it->getSymbol() == paramSymbol))
      return true;
  }
  return false;
}

/**
 * @brief Sobrecarga del operador de escritura
 *
 * @param os
 * @param paramFTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os,
                         TransitionFunction &paramFTransition) {
  for (std::set<Transition>::reverse_iterator it =
           paramFTransition.transitionSet_.rbegin();
       it != paramFTransition.transitionSet_.rend(); ++it)
    os << *it << "\n";
  return os;
}