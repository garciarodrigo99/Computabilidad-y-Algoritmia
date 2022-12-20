/**
 * @file estados.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase State.
 * Se define la clase State con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#pragma once

#include <iostream>

class State {

public:
  // Constructores y destructores
  State();
  State(int);
  ~State();

  // Getters y setters
  int getIdentifier() const;

  // Sobrecarga de operadores
  bool operator<(const State) const;
  friend std::ostream &operator<<(std::ostream &, State &);
  friend std::ostream &operator<<(std::ostream &, const State &);
  void operator=(const State);
  bool operator==(const State) const;

private:
  int identifier_;
};