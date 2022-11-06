#include "transicion.h"

#include <set>
#include <iostream>

class TransitionFunction {

	public:
    TransitionFunction();
    ~TransitionFunction();

		int getSize();
		State getState(State, Symbol);

		void addTransition(Transition);
		bool isTransition(State, Symbol);
		void print();

		friend std::ostream &operator<<(std::ostream &, TransitionFunction &); 

	private:
    std::set<Transition> transitionSet_;
};