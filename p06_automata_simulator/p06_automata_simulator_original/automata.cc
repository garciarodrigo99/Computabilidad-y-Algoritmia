/**
 * @file automata.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Automata.
 * Se define la clase Automata con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "automata.h"

#include <assert.h>

// Automata::Automata() {}

/**
 * @brief Construct a new Automata:: Automata object
 *
 * @param paramAlphabet
 * @param paramInitialState
 */
Automata::Automata(Alphabet paramAlphabet, State paramInitialState)
    : alphabet_(paramAlphabet), automataIntialState_(paramInitialState) {
  stateSet_.insert(paramInitialState);
  if (paramInitialState.isFinalState())
    finalStateSet_.insert(paramInitialState);
}

/**
 * @brief Destroy the Automata:: Automata object
 *
 */
Automata::~Automata() {}

bool Automata::acceptChainNFA(Chain paramChain) {
  // assert(alphabet_.okChain(paramChain));
  if (!(alphabet_.okChain(paramChain)))
    return false;

  std::set<State> actualStates;
  actualStates.insert(automataIntialState_);
  for (int chainIterator = 0; chainIterator < paramChain.Size();
       chainIterator++) {
    std::set<State> nextStates;
    for (std::set<State>::iterator stateIterator = actualStates.begin();
         stateIterator != actualStates.end(); stateIterator++) {
      std::set<State> transitionSet;
      if (trFunction_.isTransition(*stateIterator,
                                   paramChain.Position(chainIterator)))
        transitionSet = (trFunction_.getStatesSet(
            *stateIterator, paramChain.Position(chainIterator)));
      nextStates.insert(transitionSet.begin(), transitionSet.end());
    }
    actualStates = nextStates;
  }
  return containsFinalState(actualStates);
}

bool Automata::containsFinalState(std::set<State> paramStatesSet) {
  std::cout << "Numero de ultimos estados: " << paramStatesSet.size()
            << std::endl;
  for (std::set<State>::iterator it = paramStatesSet.begin();
       it != paramStatesSet.end(); it++) {
    if (finalStateSet_.count(*it) > 0)
      return true;
  }
  return false;
}

void Automata::addTransition(int actualStateId, Symbol paramSymbol,
                             int nextStateId) {
  State originState(getState(actualStateId));
  State destinationState(getState(nextStateId));
  Transition auxTransition(actualStateId, paramSymbol, nextStateId);
  trFunction_.addTransition(auxTransition);
}

State Automata::getState(int stateIdentifyer) {
  for (std::set<State>::iterator it = stateSet_.begin(); it != stateSet_.end();
       ++it) {
    if (it->getIdentifier() == stateIdentifyer)
      return *it;
  }
  return 0; // Evitar warning
}

void Automata::addState(State paramState) {
  stateSet_.insert(paramState);
  if (paramState.isFinalState())
    finalStateSet_.insert(paramState);
}

/**
 * @brief Sobrecarga del operador de escritura
 *
 * @param os
 * @param paramFTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Automata &paramFTransition) {
  os << "Alfabeto: " << paramFTransition.alphabet_ << "\n";

  os << ">";
  if (paramFTransition.automataIntialState_.isFinalState())
    os << "((" << paramFTransition.automataIntialState_ << ")) ";
  else
    os << "(" << paramFTransition.automataIntialState_ << ") ";

  for (std::set<State>::iterator it = ++paramFTransition.stateSet_.begin();
       it != paramFTransition.stateSet_.end(); ++it) {
    if (it->isFinalState())
      os << "((" << *it << ")) ";
    else
      os << "(" << *it << ") ";
  }
  std::endl(os);
  os << paramFTransition.trFunction_ << "\n";
  return os;
}