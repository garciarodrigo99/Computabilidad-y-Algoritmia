/**
 * @file transicion.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase Transition.
 * Se define la clase Transition con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 */

#include "estados.h"
#include "simbolo.h"

#include <iostream>

class Transition {

public:
  // Constructores y destructor
  Transition(State, Symbol, State);
  ~Transition();
  
  // Getters y setters
  State getDestinationState() const;
  State getOriginState() const;
  Symbol getSymbol() const;

  // Sobrecarga de operadores
  bool operator<(const Transition) const;
  friend std::ostream &operator<<(std::ostream &, Transition &);
  friend std::ostream &operator<<(std::ostream &, const Transition &);

private:
  State originState_;
  Symbol symbol_;
  State destinationState_;
};