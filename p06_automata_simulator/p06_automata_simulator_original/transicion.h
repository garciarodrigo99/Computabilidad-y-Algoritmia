#include "estados.h"
#include "simbolo.h"

#include <iostream>

class Transition {

public:
  Transition(State, Symbol, State);
  ~Transition();
  State getOriginState() const;
  Symbol getSymbol() const;
  State getDestinationState() const;

  bool operator<(const Transition) const;
  friend std::ostream &operator<<(std::ostream &, Transition &);
  friend std::ostream &operator<<(std::ostream &, const Transition &);

private:
  State originState_;
  Symbol symbol_;
  State destinationState_;
};