#include "alfabeto.h"

#include <iostream>
#include <assert.h>
#include <string.h>

Alfabeto::Alfabeto(std::vector<Simbolo> param) : a_(param) {}

Alfabeto::Alfabeto(Simbolo param) {
  assert(strcmp(param.GetSimbolo(),kCadenaVacia) != 0); // No se puede insertar cadena vacia
  a_.push_back(param);
}

std::vector<Simbolo>& Alfabeto::GetAlfabeto(){
  return a_;
}
    
void Alfabeto::SetAlfabeto(std::vector<Simbolo> param){
  a_ = param;
}

void Alfabeto::AddSimbolo(Simbolo param){
  assert(strcmp(param.GetSimbolo(),kCadenaVacia) != 0); // No se puede insertar cadena vacia
  a_.push_back(param);
}

std::ostream& operator<<(std::ostream& os, Alfabeto& param_alfabeto){
  os << "{";
  os << param_alfabeto.GetAlfabeto().front();

  for (size_t i = 1; i < param_alfabeto.GetAlfabeto().size(); i++) {
    os << ", " << param_alfabeto.GetAlfabeto().at(i);
  }

  os << "}";

  return os;
}