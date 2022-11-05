#include "automata.h"

#include <assert.h>

//Automata::Automata() {}

Automata::Automata(Alphabet paramAlphabet, State paramInitialState) : 
									alphabet_(paramAlphabet), automataIntialState_(paramInitialState) {
										if (paramInitialState.isFinalState()) 
											finalStateSet_.insert(paramInitialState);
}

Automata::~Automata() {}

bool Automata::acceptChain(Chain paramChain) {
	//assert(alphabet_.okChain(paramChain));
	if (!(alphabet_.okChain(paramChain))) return false;
	State actualState(automataIntialState_);
	for (size_t i = 0; i < paramChain.Size(); i++) {
		if (trFunction_.isTransition(actualState,paramChain.Position(i)))
			actualState = trFunction_.getState(actualState,paramChain.Position(i)); 
	}
	return (finalStateSet_.count(actualState) == 0);
}

void Automata::addTransition(State paramState, Symbol paramSymbol, 
														int nextStateId) {
	State auxState(getState(nextStateId));
	Transition auxTransition(paramState,paramSymbol,auxState);
	trFunction_.addTransition(auxTransition);
}

State Automata::getState(int stateIdentifyer) {
	for (std::set<State>::iterator it = stateSet_.begin();
      it != stateSet_.end(); ++it) {
				if (it->getIdentifier() == stateIdentifyer) return *it;
	}
}

void Automata::addState(State paramState) {
	stateSet_.insert(paramState);
	if (paramState.isFinalState())  finalStateSet_.insert(paramState);
}

