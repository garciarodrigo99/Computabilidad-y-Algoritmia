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
  alphabet_.push_back(param);
}

Alphabet::Alphabet(std::vector<Symbol> param) : alphabet_(param) {}               //|

Symbol Alphabet::Position(int index){
  return alphabet_.at(index);
}

void Alphabet::SetAlphabet(std::vector<Symbol> param){
  alphabet_ = param;
}
   
int Alphabet::Size()const{
  return alphabet_.size();
}

void Alphabet::AddSymbol(Symbol param_simbolo){
  if (!(inSymbol(param_simbolo))) {
     alphabet_.push_back(param_simbolo); 
  }
}

int Alphabet::DistinctSimbol(Chain param_cadena){
  int count = 0;
  for (size_t i = 0; i < alphabet_.size(); i++) {
    if (param_cadena.inSymbol(alphabet_.at(i))) {
      count++;
    }
  }
  return count;
}

bool Alphabet::inSymbol(Symbol param_simbolo) {
  for (int i = 0; i < alphabet_.size(); i++) {
    if (alphabet_.at(i).isEqual(param_simbolo)) {
      return true;
    }
  }
  return false;
}

bool Alphabet::okChain(Chain param_cadena){
  for (int i = 0; i < param_cadena.Size(); i++) {
    for (size_t j = 0; j < alphabet_.size(); j++){
      if (param_cadena.Position(i).isEqual(alphabet_.at(j))) {
        return false;
      }
    }
  }
  return true;
}

bool Alphabet::operator<(const Alphabet param_alphabet)const{
  return ((int)alphabet_.size() < param_alphabet.Size());
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Alphabet& param_alfabeto){
  os << "{";
  os << param_alfabeto.Position(0);

  for (int i = 1; i < param_alfabeto.Size(); i++) {
    os << ", " << param_alfabeto.Position(i);
  }

  os << "}";

  return os;
}