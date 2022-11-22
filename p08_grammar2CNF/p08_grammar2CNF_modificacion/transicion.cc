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
  if (originState_.getIdentifier() !=
      paramTransition.originState_.getIdentifier())
    return (originState_.getIdentifier() <
            paramTransition.originState_.getIdentifier());
  if (!(symbol_ == paramTransition.getSymbol()))
    return (symbol_ < paramTransition.getSymbol());
  if (destinationState_.getIdentifier() !=
      paramTransition.destinationState_.getIdentifier())
    return (destinationState_.getIdentifier() <
            paramTransition.destinationState_.getIdentifier());
  return false;
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