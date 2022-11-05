#include "estados.h"

State::State(int paramID, bool paramIS, bool paramFS) : identifier_(paramID),
						initialState_(paramIS), finalState_(paramFS) {}

State::~State() {}

int State::getIdentifier() { return identifier_; }
bool State::isInitialState() { return initialState_; }
bool State::isFinalState() {return finalState_; }