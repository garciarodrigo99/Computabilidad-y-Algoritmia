#include "simbolo.h"

#include <iostream>

Simbolo::Simbolo(char* param) : s_(param) {}

char* Simbolo::GetSimbolo(){
  return s_;
}
    
void Simbolo::SetSimbolo(char* param){
  s_ = param;
}

std::ostream& operator<<(std::ostream& os, Simbolo& param_simbolo){
  os << param_simbolo.GetSimbolo();
  return os;
}