/**
 * @file estados.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase State.
 * Se define la clase State con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "estados.h"
#include <iostream>

/**
 * @brief Construct a new State:: State object
 * Por defecto. Se hace para la compilacion del constructor de Automata
 * mediante nombre de fichero
 */
State::State() {}

/**
 * @brief Construct a new State:: State object
 * Construye un estado a partir de su identificador
 * @param paramID
 */
State::State(int paramID) : identifier_(paramID) {}

// /**
//  * @brief Construct a new State:: State object
//  * Construye un estado a partir de su identificador
//  * @param paramID
//  */
// State::State(int paramID, bool paramIS, bool paramFS)
//     : identifier_(paramID), initialState_(paramIS), finalState_(paramFS) {}

/**
 * @brief Destroy the State:: State object
 *
 */
State::~State() {}

/**
 * @brief Getter del identificador del estado
 *
 * @return int
 */
int State::getIdentifier() const { return identifier_; }

/**
 * @brief Sobrecarga operador '<' para poder trabajar clase std::set
 *
 * @param paramAlphabet Estado candidato a entrar en std::set
 * @return True - El estado no se encuentra en el conjunto
 * @return false - El estado se encuentra en el conjunto
 * @see std::set
 */
bool State::operator<(const State paramState) const {
  return (identifier_ < paramState.getIdentifier());
}
/**
 * @brief Sobrecarga para indicar que un estado es igual a otro.
 * ¡No equivalente!
 *
 * @param paramState Estado a igualar el estado objeto
 */
void State::operator=(const State paramState) {
  identifier_ = paramState.identifier_;
}

/**
 * @brief Sobrecarga de operador para indicar si un estado tiene el mismo
 * identificador que otro, no si es equivalente
 *
 * @param paramState Estado a comparar el estado objeto
 * @return True - El estado parametro es igual al estado objeto.
 * @return False - El estado parametro no es igual al estado objeto.
 */
bool State::operator==(const State paramState) const {
  return (identifier_ == paramState.getIdentifier());
}
/**
 * @brief
 *
 * @param os
 * @param paramState
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, State &paramState) {
  os << paramState.identifier_;
  return os;
}

/**
 * @brief
 *
 * @param os
 * @param paramState
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const State &paramState) {
  os << paramState.identifier_;
  return os;
}