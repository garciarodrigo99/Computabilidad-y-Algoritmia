/**
 * @file estados.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase State.
 * Se define la clase State con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#pragma once

#include <iostream>

class State {

public:
  // Constructores y destructores
  State(int);
  State(int, bool, bool);
  ~State();

  // Getters y setters
  int getIdentifier() const;
  bool isInitialState();
  bool isFinalState();
  bool isFinalState() const;

  void setInitialState();
  void setFinalState();

  // Sobrecarga de operadores
  bool operator<(const State) const;
  friend std::ostream &operator<<(std::ostream &, State &);
  friend std::ostream &operator<<(std::ostream &, const State &);
  void operator=(const State);
  bool operator==(const State) const;

private:
  int identifier_;
  bool initialState_;
  bool finalState_;
};
