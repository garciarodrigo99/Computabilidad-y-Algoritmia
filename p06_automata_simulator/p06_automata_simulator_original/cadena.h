/**
 * @file cadena.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase Chain.
 * Se define la clase Chain con sus métodos y atributos.
 * @version 2.0
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 */

#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Alphabet;

class Chain {
public:
  // Constructores y destructores
  Chain();
  Chain(Symbol);
  Chain(std::vector<Symbol>);
  Chain(const Chain &); // Constructor de copia

  // Getters y setters
  Symbol Position(int) const;
  int Size(void) const;

  // Operaciones
  void AddSymbol(Symbol);
  static Chain Concatenate(const Chain &, const Chain &);
  Alphabet GenerateAlphabet(void);
  bool inSymbol(Symbol);
  bool isEqual(const Chain &) const;
  std::vector<Chain> Prefix();
  Chain Reverse(void);
  Chain Reverse(void) const;
  std::vector<Chain> Substring(void);
  std::vector<Chain> Sufix(void);

  // Sobrecarga operadores
  bool operator<(const Chain) const;
  friend std::ostream &operator<<(std::ostream &, const Chain &);
  bool operator==(const Chain &) const;

private:
  std::vector<Symbol> chain_;
};

bool inVector(std::vector<Chain> param_vector, Chain param_cadena);