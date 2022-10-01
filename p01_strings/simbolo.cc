#include "simbolo.h"

#include <iostream>

Simbolo::Simbolo(char* param) : s_(param) {}

char* Simbolo::GetSimbolo(){
  return s_;
}
    
void Simbolo::SetSimbolo(char* param){
  s_ = param;
}