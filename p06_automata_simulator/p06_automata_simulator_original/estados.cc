#include "estados.h"
#include <iostream>

State::State(int paramID) : identifier_(paramID), initialState_(false),
							finalState_(false) {}

State::State(int paramID, bool paramIS, bool paramFS) : identifier_(paramID),
						initialState_(paramIS), finalState_(paramFS) {}

State::~State() {}

int State::getIdentifier() const { return identifier_; }

bool State::isInitialState() { return initialState_; }

bool State::isFinalState() {return finalState_; }

bool State::isFinalState() const {return finalState_; }

void State::setFinalState() { finalState_ = true; }

bool State::operator<(const State paramState)const {
	return (identifier_ < paramState.getIdentifier());
}

void State::operator=(const State paramState) {
	identifier_ =	paramState.identifier_;
	initialState_ = paramState.initialState_;
	finalState_ = paramState.finalState_;
}

// Sobrecarga de operador para indicar si un estado tiene el mismo 
// identificador que otro, no si es equivalente
bool State::operator==(const State paramState)const {
	return (identifier_ == paramState.getIdentifier());
}

std::ostream &operator<<(std::ostream &os, State &paramState) {
  os << paramState.identifier_;
  return os;
}

std::ostream &operator<<(std::ostream &os, const State &paramState) {
  os << paramState.identifier_;
  return os;
}