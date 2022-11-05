#include "simbolo.h"
#include "estados.h"

class Transition {

	public:
		Transition(State, Symbol, State);
		~Transition();
		State getOriginState() const;
		Symbol getSymbol() const ;
		State getDestinationState() const;

	private:
		State originState_;
		Symbol symbol_;
		State destinationState_;
};