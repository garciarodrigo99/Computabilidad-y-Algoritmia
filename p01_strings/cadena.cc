#include "cadena.h"

#include <assert.h>
#include <algorithm>

//https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
//https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
//https://en.cppreference.com/w/c/string/byte/strcmp 

Cadena::Cadena(){}

Cadena::Cadena(Simbolo param) : Cadena() {  // Constructor con simbolo, todos menos cadena vacia
  //std::cout << "Constructor 3\n";
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar cadena vacia
  c_.push_back(param);
}

/*
  Constructor de copia de la clase
  Se hace el if ese para poder 
*/
Cadena::Cadena(const Cadena& param) : c_(param.GetCadena()) {}//Comprobar

void Cadena::AddSimbolo(Simbolo param){
  c_.push_back(param);
}//Funciona2

const std::vector<Simbolo>& Cadena::GetCadena()const{
  return c_;
}//Funciona

int Cadena::Longitud(){
    return c_.size();
}

Cadena Cadena::Inversa(){
  if (c_.size()==0){
    return *this;
  }

  Cadena inversa;
  int cont = 0;
  for (size_t i = (c_.size() - 1); i < c_.size(); --i) {     // De esta forma no se sale de rango
    for (size_t i = (c_.size() - 1); cont < c_.size(); --i) {     // De esta forma no se sale de rango
    //std::cout << "Pos " << i << " Iter" << cont <<"\n";
    cont++;
    inversa.AddSimbolo(c_.at(i));
    }
  }
  // Cadena inversa(*this);
  // std::reverse(inversa.GetCadena().begin(),inversa.GetCadena().end());
  //std::cout << "Escribiendo Inversa: " << inversa;

  return inversa;
}

std::vector<Cadena> Cadena::Prefijo(){
  std::vector<Cadena> prefijos;
  for (size_t i = 0; i < c_.size(); i++) {
    Cadena cadena_aux;
    for (size_t j = 0; j <= i; j++) {
      cadena_aux.AddSimbolo(c_.at(j));
    }
    prefijos.push_back(cadena_aux);
  }
  return prefijos;
}

std::vector<Cadena> Cadena::Sufijo(){
  std::vector<Cadena> sufijos;
  for (size_t i = 0; i < c_.size(); i++) {
    Cadena cadena_aux;
    for (size_t j = 0; j <= i; j++) {
      cadena_aux.AddSimbolo(Inversa().GetCadena().at(j));
    }
    sufijos.push_back(cadena_aux);
  }
  return sufijos;
}

void Cadena::Print(){
  if (c_.size()==0) {
    std::cout << kCadenaVacia;
  } else {  
    for (size_t i = 0; i < c_.size(); i++) {
          std::cout << c_.at(i);
      }
  }
}

std::ostream& operator<<(std::ostream& os, Cadena& param_cadena){
  if (param_cadena.Longitud()==0) {
    return os << kCadenaVacia;
  } else {  
    for (size_t i = 0; i < param_cadena.GetCadena().size(); i++){
      os << param_cadena.c_.at(i);
    }
    return os;
  }
}