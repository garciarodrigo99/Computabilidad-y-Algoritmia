/**
 * @file automata.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase Automata.
 * Se define la clase Automata con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include "alfabeto.h"
#include "cadena.h"
#include "estados.h"
#include "transitionFunction.h"

#include <set>

class Automata {

public:
  // Constructores y destructores
  Automata();
  Automata(Alphabet, State);
  Automata(std::string);
  ~Automata();

  // Operaciones
  bool acceptChainNFA(Chain);
  void addState(State);
  void addTransition(int, Symbol, int);

  // Sobrecarga de operadores
  friend std::ostream &operator<<(std::ostream &, Automata &);

  // Metodos privados
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
