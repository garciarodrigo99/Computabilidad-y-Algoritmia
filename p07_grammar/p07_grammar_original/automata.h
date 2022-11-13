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
#include "transicion.h"
#include "grammar.h"

#include <set>

#pragma once

class Automata {

public:
  // Constructores y destructores
  Automata(Alphabet, State, int);
  Automata(std::string);
  ~Automata();

  // Operaciones
  bool acceptChain(Chain);
  void addState(State, int = 0);
  void addTransition(int, Symbol, int);
  bool isDFA();
  Grammar convertToGrammar();
  // Sobrecarga de operadores
  friend std::ostream &operator<<(std::ostream &, Automata &);

  // Metodos privados
private:
  bool containsFinalState(std::set<State>);
  State getState(int);
  std::set<State> getStatesSet(State, Symbol);
  bool isFinalState(State);
  bool isState(int);
  bool isTransition(State, Symbol);

private:
  Alphabet alphabet_;
  std::set<State> stateSet_;
  int automataIntialState_;
  std::set<int> finalStateSet_;
  std::set<Transition> trFunction_;
};

std::vector<std::string> SplitChain(std::string str, char pattern = ' ');