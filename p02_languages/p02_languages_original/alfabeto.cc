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

Alfabeto::Alfabeto(std::vector<Symbol> param) : alfabeto_(param) {}               //|

Alfabeto::Alfabeto(Symbol param) {
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar 
  //                                                 // cadena vacia
  alfabeto_.push_back(param);
}
    
void Alfabeto::SetAlfabeto(std::vector<Symbol> param){
  alfabeto_ = param;
}

bool Alfabeto::inSymbol(Symbol param_simbolo) {
  for (int i = 0; i < alfabeto_.size(); i++) {
    if (alfabeto_.at(i).isEqual(param_simbolo)) {
      return true;
    }
  }
  return false;
}

bool Alfabeto::okCadena(Cadena param_cadena){
  for (int i = 0; i < param_cadena.Size(); i++) {
    for (size_t j = 0; j < alfabeto_.size(); j++){
      if (param_cadena.Position(i).isEqual(alfabeto_.at(j))) {
        return false;
      }
    }
  }
  return true;
}

int Alfabeto::DistinctSimbol(Cadena param_cadena){
  int count = 0;
  for (size_t i = 0; i < alfabeto_.size(); i++) {
    if (param_cadena.inSymbol(alfabeto_.at(i))) {
      count++;
    }
  }
  return count;
}

void Alfabeto::AddSymbol(Symbol param_simbolo){
  if (!(inSymbol(param_simbolo))) {
     alfabeto_.push_back(param_simbolo); 
  }
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Alfabeto& param_alfabeto){
  os << "{";
  os << param_alfabeto.Position(0);

  for (int i = 1; i < param_alfabeto.Size(); i++) {
    os << ", " << param_alfabeto.Position(i);
  }

  os << "}";

  return os;
}

int Alfabeto::Size(){
  return alfabeto_.size();
}

Symbol Alfabeto::Position(int index){
  return alfabeto_.at(index);
}