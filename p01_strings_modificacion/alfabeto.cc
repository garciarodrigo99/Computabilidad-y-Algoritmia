#include "alfabeto.h"

#include <iostream>
#include <assert.h>

Alfabeto::Alfabeto(std::vector<Simbolo> param) : a_(param) {}               //|

Alfabeto::Alfabeto(Simbolo param) {
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar 
  //                                                 // cadena vacia
  a_.push_back(param);
}

std::vector<Simbolo>& Alfabeto::GetAlfabeto(){
  return a_;
}
    
void Alfabeto::SetAlfabeto(std::vector<Simbolo> param){
  a_ = param;
}

bool Alfabeto::inSimbolo(Simbolo param_simbolo) {
  for (int i = 0; i < a_.size(); i++) {
    if (a_.at(i).GetSimbolo() == param_simbolo.GetSimbolo()) {
      return true;
    }
  }
  return false;
}

bool Alfabeto::okCadena(Cadena param_cadena){
  for (size_t i = 0; i < param_cadena.GetCadena().size(); i++) {
    for (size_t j = 0; j < a_.size(); j++){
      if (param_cadena.GetCadena().at(i).GetSimbolo().compare(a_.at(j).GetSimbolo()) != 0) {
        return false;
      }
    }
  }
  return true;
}

int Alfabeto::DistinctSimbol(Cadena param_cadena){
  int count = 0;
  for (size_t i = 0; i < a_.size(); i++) {
    if (param_cadena.inSimbolo(a_.at(i).GetSimbolo())) {
      count++;
    }
  }
  return count;
}

void Alfabeto::AddSimbolo(Simbolo param_simbolo){
  if (!(inSimbolo(param_simbolo))) {
     a_.push_back(param_simbolo); 
  }
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