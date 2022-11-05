// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo alfabeto.cc: Fichero de implementación de la clase Alphabet.
// Se define la clase Alphabet con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "alfabeto.h"

#include <assert.h>
#include <iostream>

// Constructor a través de un simbolo
Alphabet::Alphabet(Symbol param) { alphabet_.insert(param); }

// Constructor a través de un conjunto de simbolos
Alphabet::Alphabet(std::set<Symbol> param) : alphabet_(param) {
  assert(alphabet_.size() > 0);
}

// Constructor de copia
Alphabet::Alphabet(const Alphabet &param_alphabet) {
  for (std::set<Symbol>::iterator it = param_alphabet.alphabet_.begin();
       it != param_alphabet.alphabet_.end(); ++it)
    alphabet_.insert(*it);
}

// Union de los simbolos del alfabeto parametro con los del primero
void Alphabet::AlphabetUnion(const Alphabet &param_alphabet) {
  for (std::set<Symbol>::iterator it = param_alphabet.alphabet_.begin();
       it != param_alphabet.alphabet_.end(); ++it)
    alphabet_.insert(*it);
}

// Getter tamaño
int Alphabet::Size() const { return alphabet_.size(); }

// Añadir simbolo al alfabeto
void Alphabet::AddSymbol(Symbol param_simbolo) {
  alphabet_.insert(param_simbolo);
}

// Metodo para saber cuantos simbolos distintos del alfabeto se encuentran en
// la cadena
int Alphabet::DistinctSimbol(Chain param_cadena) {
  int count = 0;
  for (std::set<Symbol>::iterator it = alphabet_.begin(); it != alphabet_.end();
       ++it) {
    if (param_cadena.inSymbol(*it))
      count++;
  }
  return count;
}

// Metodo que devuelve true si un simbolo se encuentra en el alfabeto
bool Alphabet::inSymbol(Symbol param_simbolo) {
  if (alphabet_.count(param_simbolo) != 0)
    return true;
  else
    return false;
}

// Metodo para saber si la cadena pertenece al alfabeto
bool Alphabet::okChain(Chain param_cadena) {
  for (int i = 0; i < param_cadena.Size(); i++) {
    if (!(inSymbol(param_cadena.Position(i))))
      return false;
  }
  return true;
}

// Sobrecarga operador '<' para poder trabajar clase std::set
bool Alphabet::operator<(const Alphabet param_alphabet) const {
  return ((int)alphabet_.size() < param_alphabet.Size());
}

// Sobrecarga operador '<<' para escritura del objeto
std::ostream &operator<<(std::ostream &os, Alphabet &param_alfabeto) {
  os << "{ ";

  for (std::set<Symbol>::iterator it = param_alfabeto.alphabet_.begin();
       it != param_alfabeto.alphabet_.end(); ++it)
    std::cout << *it << " ";

  os << "}";
  return os;
}