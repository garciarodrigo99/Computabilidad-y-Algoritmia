#include "transicion.h"

#include <set>

class TransitionFunction {

	public:
    TransitionFunction();
    ~TransitionFunction();

		int getSize();
		State getState(State, Symbol);

		void addTransition(Transition);
		bool isTransition(State, Symbol);

	private:
    std::set<Transition> transitionSet_;
};