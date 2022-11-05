#include "transicion.h"

Transition::Transition(State paramOriginState, Symbol paramSymbol, 
											State paramDestinationState) : 
											originState_(paramOriginState),
											symbol_(paramSymbol), 
											destinationState_(paramDestinationState) {}

Transition::~Transition() {}

