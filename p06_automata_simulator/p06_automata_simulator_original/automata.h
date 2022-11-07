#include "alfabeto.h"
#include "cadena.h"
#include "estados.h"
#include "transitionFunction.h"

#include <set>

class Automata {

public:
  Automata(/* args */);
  Automata(Alphabet, State);
  ~Automata();

  bool acceptChain(Chain);
  bool acceptChainNFA(Chain);
  void addTransition(int, Symbol, int);
  void addState(State);
  void print();

private:
  State getState(int);
  bool containsFinalState(std::set<State>);

private:
  Alphabet alphabet_;
  std::set<State> stateSet_;
  State automataIntialState_;
  std::set<State> finalStateSet_;
  TransitionFunction trFunction_;
};
