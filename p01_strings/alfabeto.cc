#include <iostream>
#include "alfabeto.h"

Alfabeto::Alfabeto(char* param) : s_(param) {}

char* Alfabeto::GetAlfabeto(){
  return s_;
}
    
void Alfabeto::SetAlfabeto(char* param){
  s_ = param;
}