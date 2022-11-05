#include "transicion.h"

Transition::Transition(State paramOriginState, Symbol paramSymbol, 
											State paramDestinationState) : 
											originState_(paramOriginState),
											symbol_(paramSymbol), 
											destinationState_(paramDestinationState) {}

Transition::~Transition() {}

State Transition::getOriginState() const { return originState_; }
Symbol Transition::getSymbol() const { return symbol_; }
State Transition::getDestinationState() const { return destinationState_; }

bool Transition::operator<(const Transition paramTransition)const {
	bool sameInitialState = (originState_ == paramTransition.getOriginState());
	bool sameSymbol = (symbol_ == paramTransition.symbol_);
	bool sameFinalState = (destinationState_ == 
												paramTransition.destinationState_);
	return (sameInitialState && sameSymbol && sameFinalState);
}