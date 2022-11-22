// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo cya-P01-Strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
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

/*
  Constructor de copia de la clase
  Se hace el if ese para poder 
*/
Cadena::Cadena(const Cadena& param) : chain_(param.GetCadena()) {}//Comprobar

void Cadena::AddSymbol(Symbol param){
  chain_.push_back(param);
}//Funciona2

const std::vector<Symbol>& Cadena::GetCadena()const{
  return chain_;
}

Cadena Cadena::Inversa(){
  if (chain_.size()==0){
    return *this;
  }

  Cadena inversa;
  for (int i = (chain_.size() - 1); i >= 0; --i) {     // De esta forma no se sale de rango
    inversa.AddSymbol(chain_.at(i));
  }
  return inversa;
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

void Cadena::Print(){
  if (chain_.size()==0) {
    std::cout << kEmptyChain;
  } else {  
    for (size_t i = 0; i < chain_.size(); i++) {
        std::cout << chain_.at(i);
    }
  }
}

int Cadena::Size(){
  return chain_.size();
}

Symbol Cadena::Position(int index){
  return chain_.at(index);
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