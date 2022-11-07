/**
 * @file transicion.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Transition.
 * Se define la clase Transition con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "transicion.h"

/**
 * @brief Construct a new Transition:: Transition object
 *
 * @param paramOriginState Estado origen
 * @param paramSymbol Simbolo
 * @param paramDestinationState Estado destino
 */
Transition::Transition(State paramOriginState, Symbol paramSymbol,
                       State paramDestinationState)
    : originState_(paramOriginState), symbol_(paramSymbol),
      destinationState_(paramDestinationState) {}

/**
 * @brief Destroy the Transition:: Transition object
 *
 */
Transition::~Transition() {}

/**
 * @brief Getter estado destino
 *
 * @return State
 */
State Transition::getDestinationState() const { return destinationState_; }

/**
 * @brief Getter estado origen
 *
 * @return State
 */
State Transition::getOriginState() const { return originState_; }

/**
 * @brief Getter simbolo
 *
 * @return Symbol
 */
Symbol Transition::getSymbol() const { return symbol_; }

/**
 * @brief Sobrecarga operador '<' para poder trabajar clase std::set
 *
 * @param paramAlphabet Transicion candidato a entrar en std::set
 * @return True - La transicion no se encuentra en el conjunto
 * @return false - La transicion se encuentra en el conjunto
 * @see std::set
 */
bool Transition::operator<(const Transition paramTransition) const {
  bool sameInitialState = (originState_ == paramTransition.getOriginState());
  bool sameSymbol = (symbol_ == paramTransition.symbol_);
  bool sameFinalState =
      (destinationState_ == paramTransition.destinationState_);
  return (!(sameInitialState && sameSymbol && sameFinalState));
}

/**
 * @brief
 *
 * @param os
 * @param paramTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Transition &paramTransition) {
  os << "(" << paramTransition.originState_ << ",";
  os << paramTransition.symbol_ << ") -> ";
  os << paramTransition.destinationState_;
  return os;
}

/**
 * @brief
 *
 * @param os
 * @param paramTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Transition &paramTransition) {
  os << "(" << paramTransition.originState_ << ",";
  os << paramTransition.symbol_ << ") -> ";
  os << paramTransition.destinationState_;
  return os;
}