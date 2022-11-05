#include "transicion.h"

#include <set>

class TransitionFunction {

	public:
    TransitionFunction();
    ~TransitionFunction();

		int getSize();
		State getState(State, Symbol);

		bool isTransition(State, Symbol);

	private:
    std::set<Transition> transitionSet_;
};