// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo cadena.cc: Fichero de implementación de la clase Cadena.
// Se define la clase Cadena con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "cadena.h"

#include <assert.h>
#include <algorithm>

//https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
//https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
//https://en.cppreference.com/w/c/string/byte/strcmp 

Cadena::Cadena(){}

Cadena::Cadena(Symbol param) : Cadena() {  // Constructor con simbolo, todos menos cadena vacia
  //std::cout << "Constructor 3\n";
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar cadena vacia
  chain_.push_back(param);
}

// Constructor de copia de la clase
Cadena::Cadena(const Cadena& param) : chain_(param.chain_) {}//Comprobar

Symbol Cadena::Position(int index)const{
  return chain_.at(index);
}

int Cadena::Size()const{
  return chain_.size();
}

void Cadena::AddSymbol(Symbol param){
  chain_.push_back(param);
}

bool Cadena::inSymbol(Symbol simbolo_param){
  for (size_t i = 0; i < chain_.size(); i++){
    if (chain_.at(i).isEqual(simbolo_param)) {
      return true;
    }
  }
  return false;
}

bool Cadena::isEqual(Cadena& cadena_param){
  if (((int)chain_.size()) != cadena_param.Size()) {
    return false;
  } else {
    for (size_t i = 0; i < chain_.size(); i++) {
      if (!(chain_.at(i).isEqual(cadena_param.Position(i)))) {
        return false;
      }
    }
  }
  return true;
}

std::vector<Cadena> Cadena::Prefix(){
  std::vector<Cadena> prefijos;
  Cadena v;
  prefijos.push_back(v);
  for (size_t i = 0; i < chain_.size(); i++) {
    Cadena cadena_aux;
    for (size_t j = 0; j <= i; j++) {
      cadena_aux.AddSymbol(chain_.at(j));
    }
    prefijos.push_back(cadena_aux);
  }
  return prefijos;
}

void Cadena::Print(){
  if (chain_.size()==0) {
    std::cout << kEmptyChain;
  } else {  
    for (size_t i = 0; i < chain_.size(); i++) {
        std::cout << chain_.at(i);
    }
  }
}

Cadena Cadena::Reverse(){
  if (chain_.size()==0){
    return *this;
  }

  Cadena inversa;
  for (int i = (chain_.size() - 1); i >= 0; --i) {     // De esta forma no se sale de rango
    inversa.AddSymbol(chain_.at(i));
  }
  return inversa;
}

std::vector<Cadena> Cadena::Substring(){
  std::vector<Cadena> subcadena;
  Cadena v;
  subcadena.push_back(v);
  for (int len = 1; len <= chain_.size(); len++) {
    for (int i = 0; i <= (chain_.size() - len); i++) {
      Cadena cadena_aux;
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        cadena_aux.AddSymbol(chain_.at(k));
      }
      if (!(inVector(subcadena,cadena_aux))) {
        subcadena.push_back(cadena_aux); 
      }
    }
  }
  return subcadena;
}

std::vector<Cadena> Cadena::Sufix(){
  std::vector<Cadena> sufijos;
  Cadena v;
  sufijos.push_back(v);
  for (int i = (chain_.size()-1); i >= 0; i--) {
    Cadena cadena_aux;
    for (int j = i; j < chain_.size(); j++) {
      cadena_aux.AddSymbol(chain_.at(j));
    }
    sufijos.push_back(cadena_aux);
  }
  return sufijos;
}

bool Cadena::operator<(const Cadena param_cadena)const{
  if ((int)chain_.size() != param_cadena.Size()) {
    return ((int)chain_.size() < param_cadena.Size());
  } else {
    for (size_t i = 0; i < (chain_.size() - 1); i++) {
      if (!(chain_.at(i).isEqual(param_cadena.Position(i)))) {
        return (chain_.at(i) < param_cadena.Position(i));
      }
    }
    return (chain_.back() < param_cadena.Position(param_cadena.Size() - 1));
  }
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Cadena& param_cadena){
  if (param_cadena.Size()==0) {
    return os << kEmptyChain;
  } else {  
    for (int i = 0; i < param_cadena.Size(); i++){
      os << param_cadena.chain_.at(i);
    }
    return os;
  }
}

bool inVector(std::vector<Cadena> param_vector, Cadena param_cadena) {
  for (size_t i = 0; i < param_vector.size(); i++) {
    if (param_cadena.isEqual(param_vector.at(i))) {
      return true;
    }
  }
  return false;
}