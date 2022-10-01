#include <iostream>
#include "alfabeto.h"

Alfabeto::Alfabeto(std::vector<Simbolo> param) : a_(param) {}

Alfabeto::Alfabeto(Simbolo param) {
  a_.push_back(param);
}

std::vector<Simbolo> Alfabeto::GetAlfabeto(){
  return a_;
}
    
void Alfabeto::SetAlfabeto(std::vector<Simbolo> param){
  a_ = param;
}

void Alfabeto::AddSimbolo(Simbolo param){
  a_.push_back(param);
}