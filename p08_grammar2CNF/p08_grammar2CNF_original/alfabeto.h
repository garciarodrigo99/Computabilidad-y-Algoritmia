/**
 * @file alfabeto.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase Alphabet.
 * Se define la clase Alphabet con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#include "cadena.h"

#include <iostream>
#include <set>
#include <vector>

#pragma once

class Alphabet {
public:
  // Constructores y destructores
  Alphabet();
  Alphabet(Symbol);
  Alphabet(std::set<Symbol>);
  Alphabet(const Alphabet &); // Copia

  // Getters y setters
  const std::set<Symbol> getSymbols();
  int Size() const;

  // Iteradores
  std::set<Symbol>::const_iterator begin() const;
  std::set<Symbol>::const_iterator end() const;

  // Operaciones
  void AddSymbol(Symbol);
  void AlphabetUnion(const Alphabet &);
  int DistinctSimbol(Chain);
  // std::set<Chain> GenerateChains(int);
  bool inSymbol(Symbol);
  bool okChain(Chain);

  // Sobrecarga de operadores
  bool operator<(const Alphabet) const;
  friend std::ostream &operator<<(std::ostream &, Alphabet &);

private:
  std::set<Symbol> alphabet_;
};