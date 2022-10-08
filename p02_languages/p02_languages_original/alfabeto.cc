// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo alfabeto.cc: Fichero de implementación de la clase Alfabeto.
// Se define la clase Alfabeto con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "alfabeto.h"

#include <iostream>
#include <assert.h>

Alphabet::Alphabet(Symbol param) {
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar 
  //                                                 // cadena vacia
  alphabet_.insert(param);
}

Alphabet::Alphabet(std::set<Symbol> param) : alphabet_(param) {}
   
int Alphabet::Size()const {
  return alphabet_.size();
}

void Alphabet::AddSymbol(Symbol param_simbolo) {
  alphabet_.insert(param_simbolo);
}

int Alphabet::DistinctSimbol(Chain param_cadena) {
  int count = 0;
  for (std::set<Symbol>::iterator it = alphabet_.begin();
      it != alphabet_.end(); ++it) {
    if (param_cadena.inSymbol(*it)) {
      count++;
    }
  }
  return count;
}

bool Alphabet::inSymbol(Symbol param_simbolo) {
  if (alphabet_.count(param_simbolo) == 0)
    return true;
  else
    return false;
}

// Metodo para saber si la cadena pertenece al alfabeto
bool Alphabet::okChain(Chain param_cadena) {
  for (int i = 0; i < param_cadena.Size(); i++) {
    if (!(inSymbol(param_cadena.Position(i)))) {
      return false;
    }
  }
  return true;
}

bool Alphabet::operator<(const Alphabet param_alphabet)const {
  return ((int)alphabet_.size() < param_alphabet.Size());
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Alphabet& param_alfabeto) {
  os << "{ ";

  for (std::set<Symbol>::iterator it = param_alfabeto.alphabet_.begin();
      it != param_alfabeto.alphabet_.end(); ++it)
      std::cout << *it << " ";

  os << "}";
  return os;
}