#include "transitionFunction.h"
#include "alfabeto.h"
#include "cadena.h"

#include <set>

class Automata {

	public:
		Automata(/* args */);
		~Automata();
	private:
		Alphabet alphabet_;
		std::set<State> stateSet_;
		State automataIntialState_;
		std::set<State> finalStateSet_;
		TransitionFunction trFunction_;
};
