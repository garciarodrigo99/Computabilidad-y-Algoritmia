/**
 * @file cadena.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase Chain.
 * Se define la clase Chain con sus métodos y atributos.
 * @version 2.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 */

#include "simbolo.h"

#include <algorithm>
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
  Chain(std::string);

  // Getters y setters
  void assign(int, Symbol);
  Symbol back(void) const;
  Symbol Position(int) const;
  int Size(void) const;

  // Iteradores
  std::vector<Symbol>::const_iterator begin() const;
  std::vector<Symbol>::const_iterator end() const;

  // Operaciones
  void AddSymbol(Symbol);
  static Chain Concatenate(const Chain &, const Chain &);
  Alphabet GenerateAlphabet(void);
  bool inSymbol(Symbol);
  std::vector<Chain> Prefix();
  Chain Reverse(void);
  Chain Reverse(void) const;
  std::vector<Chain> Substring(void);
  std::vector<Chain> Sufix(void);

  // Sobrecarga operadores
  bool operator<(const Chain) const;
  friend std::ostream &operator<<(std::ostream &, const Chain &);
  void operator=(const Chain);
  bool operator==(const Chain &) const;

private:
  std::vector<Symbol> chain_;
};

bool inVector(std::vector<Chain> param_vector, Chain param_cadena);