#include "transitionFunction.h"

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