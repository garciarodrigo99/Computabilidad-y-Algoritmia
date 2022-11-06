// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulación de autómatas finitos
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 08/11/2022
// Archivo Alphabet.h: Cabecera de la clase Alphabet.
// Se define la clase Alphabet con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 04/11/2022 - Creaci´on (primera versi´on) del c´odigo

#include "cadena.h"

#include <iostream>
#include <set>
#include <vector>

#pragma once

class Alphabet {
public:
  // Constructores y destructores
  Alphabet(Symbol);
  Alphabet(std::set<Symbol>);
  Alphabet(const Alphabet &); // Copia

  // Getters y setters
  void AlphabetUnion(const Alphabet &);
  int Size() const;

  // Operaciones
  void AddSymbol(Symbol);
  int DistinctSimbol(Chain);
  bool inSymbol(Symbol);
  bool okChain(Chain);

  // Sobrecarga de operadores
  bool operator<(const Alphabet) const;
  friend std::ostream &operator<<(std::ostream &, Alphabet &);

private:
  std::set<Symbol> alphabet_;
};