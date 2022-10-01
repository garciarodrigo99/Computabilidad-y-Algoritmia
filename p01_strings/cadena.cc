#include "cadena.h"

#include <assert.h>
#include <string.h>

//https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
//https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
//https://en.cppreference.com/w/c/string/byte/strcmp 

Cadena::Cadena(){
  c_.push_back(kCadenaVacia);
}

Cadena::Cadena(std::vector<Simbolo> param) : c_(param){
  for (size_t i = 0; i < c_.size(); i++) {
    assert(strcmp(c_.at(i).GetSimbolo(),kCadenaVacia) != 0);
  }
  
}//Funciona

Cadena::Cadena(Simbolo param) : Cadena() {
  assert(strcmp(param.GetSimbolo(),kCadenaVacia) != 0); // No se puede insertar cadena vacia
  c_.at(0).SetSimbolo(param.GetSimbolo());
}

void Cadena::AddSimbolo(Simbolo param){
  if (strcmp(c_.at(0).GetSimbolo(),kCadenaVacia) == 0) {  // Si el primer elemento es la cadena vacia
    c_.at(0).SetSimbolo(param.GetSimbolo());    // simbolo parametro es ahora primer elemento
  } else {
    c_.push_back(param);                        // Añadir simbolo
  }
}//Funciona

std::vector<Simbolo>& Cadena::GetCadena(){
  return c_;
}//Funciona

int Cadena::Longitud(){
  if ((c_.size() == 1) && (strcmp(c_.front().GetSimbolo(),kCadenaVacia) == 0)) {
    return 0;
  } else
    return c_.size();
}//Funciona

void Cadena::Print(){
    for (size_t i = 0; i < c_.size(); i++) {
        std::cout << c_.at(i).GetSimbolo();
    }
    //std::endl(std::cout);
    
}