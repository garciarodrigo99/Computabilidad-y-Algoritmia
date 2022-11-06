#include "automata.h"

#include <assert.h>

// Automata::Automata() {}

Automata::Automata(Alphabet paramAlphabet, State paramInitialState)
    : alphabet_(paramAlphabet), automataIntialState_(paramInitialState) {
  stateSet_.insert(paramInitialState);
  if (paramInitialState.isFinalState())
    finalStateSet_.insert(paramInitialState);
}

Automata::~Automata() {}

bool Automata::acceptChain(Chain paramChain) {
  // assert(alphabet_.okChain(paramChain));
  if (!(alphabet_.okChain(paramChain)))
    return false;
  State actualState(automataIntialState_);
  for (int i = 0; i < paramChain.Size(); i++) {
    if (trFunction_.isTransition(actualState, paramChain.Position(i)))
      actualState = trFunction_.getState(actualState, paramChain.Position(i));
    std::cout << "iteracion:" << i << " estado:" << actualState << std::endl;
  }
  return (finalStateSet_.count(actualState) != 0);
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

void Automata::print() {
  std::cout << "Alfabeto: " << alphabet_ << std::endl;
  // std::cout << "Estados: ";
  // for (std::set<State>::iterator it = stateSet_.begin();
  //     it != stateSet_.end(); ++it) {
  // 			std::cout << it->getIdentifier() << " ";
  // }
  // std::endl(std::cout);
  // std::cout << "Estado inicial: " << automataIntialState_.getIdentifier() <<
  // std::endl; std::cout << "Estados de aceptacion: "; for
  // (std::set<State>::iterator it = finalStateSet_.begin();
  //     it != finalStateSet_.end(); ++it) {
  // 			std::cout << it->getIdentifier() << " ";
  // }
  // std::endl(std::cout);
  std::cout << ">";
  if (automataIntialState_.isFinalState())
    std::cout << "((" << automataIntialState_ << ")) ";
  else
    std::cout << "(" << automataIntialState_ << ") ";

  for (std::set<State>::iterator it = ++stateSet_.begin();
       it != stateSet_.end(); ++it) {
    if (it->isFinalState())
      std::cout << "((" << *it << ")) ";
    else
      std::cout << "(" << *it << ") ";
  }
  std::endl(std::cout);
  std::cout << trFunction_ << std::endl;
}