#include "transitionFunction.h"
#include "alfabeto.h"
#include "cadena.h"
#include "estados.h"

#include <set>

class Automata {

	public:
		Automata(/* args */);
		Automata(Alphabet, State);
		~Automata();
		bool acceptChain(Chain);
		
	private:


	private:
		Alphabet alphabet_;
		std::set<State> stateSet_;
		State automataIntialState_;
		std::set<State> finalStateSet_;
		TransitionFunction trFunction_;
};
