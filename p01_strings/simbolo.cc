#include "simbolo.h"

#include <iostream>
#include <string.h>
#include <assert.h>

Simbolo::Simbolo(char* param) : s_(param) {
  // Permitimos que haya un objeto con simbolo &, pero solo de longitud 1
  // Utilidad: inicializar una cadena como vacia
  if (strlen(s_)>1) {
    assert(!(Simbolo::contieneCadenaVacia(*this)));
  }
}

char* Simbolo::GetSimbolo(){
  return s_;
}
    
void Simbolo::SetSimbolo(char* param){
  s_ = param;
}

bool Simbolo::contieneCadenaVacia(Simbolo simbolo_param){
  for (size_t i = 0; i < strlen(simbolo_param.GetSimbolo()); i++) {
    if (simbolo_param.GetSimbolo()[i] == kCadenaVacia) {
      return true;
    }
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, Simbolo& param_simbolo){
  os << param_simbolo.GetSimbolo();
  return os;
}