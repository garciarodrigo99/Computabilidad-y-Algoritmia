#include "automata.h"

#include <assert.h>

//Automata::Automata() {}

Automata::Automata(Alphabet paramAlphabet, State paramInitialState) : 
									alphabet_(paramAlphabet), automataIntialState_(paramInitialState){}

Automata::~Automata() {}

bool Automata::acceptChain(Chain paramChain) {
	//assert(alphabet_.okChain(paramChain));
	if (!(alphabet_.okChain(paramChain))) return false;
	State actualState(automataIntialState_);
	
}