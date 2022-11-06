#include "transitionFunction.h"

#include <iostream>
#include <assert.h>

TransitionFunction::TransitionFunction(/* args */) {}

TransitionFunction::~TransitionFunction() {}

int TransitionFunction::getSize() { return transitionSet_.size(); }

State TransitionFunction::getState(State paramState, Symbol paramSymbol) {
	assert(isTransition(paramState,paramSymbol));
	for (std::set<Transition>::iterator it = transitionSet_.begin();
		it != transitionSet_.end(); ++it) {
			if ((it->getOriginState().getIdentifier() == paramState.getIdentifier())
					&& (it->getSymbol().isEqual(paramSymbol))) {
						return it->getDestinationState();
			}
	}
	return 0; // Evitar warning
}

void TransitionFunction::addTransition(Transition paramTransition) {
	transitionSet_.insert(paramTransition);
}

// Metodo que comprueba si para un estado y simbolo dado existe transicion
bool TransitionFunction::isTransition(State paramState, Symbol paramSymbol) {
	for (std::set<Transition>::iterator it = transitionSet_.begin();
			it != transitionSet_.end(); ++it) {
				if ((it->getOriginState().getIdentifier() == paramState.getIdentifier())
						&& (it->getSymbol().isEqual(paramSymbol))) {
							return true;
				}
				
	}
	return false;
}

void TransitionFunction::print() {
	for (std::set<Transition>::iterator it = transitionSet_.begin();
			it != transitionSet_.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, 
												TransitionFunction &paramFTransition) {
	for (std::set<Transition>::reverse_iterator it = paramFTransition.transitionSet_.rbegin();
			it != paramFTransition.transitionSet_.rend(); ++it) {
				os << *it << "\n";
				
	}
	return os;
}