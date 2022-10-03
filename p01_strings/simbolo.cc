#include "simbolo.h"

#include <assert.h>

//https://stackoverflow.com/questions/22855860/initializing-const-char-in-constructor-will-there-be-a-memory-leak

// Simbolo::Simbolo(std::string& param) : s_(param) {
//   assert(CheckSimbols(*this));
// }

Simbolo::Simbolo(const std::string param) : s_(param) {
  assert(CheckSimbols(*this));
}

Simbolo::~Simbolo(){}

// const char* Simbolo::GetSimbolo(){
//   return s_;
// }
    
// void Simbolo::SetSimbolo(char* param){
//   s_ = param;
// }

//Comprueba que no contiene el simbolo reservado para la cadena vacía
bool Simbolo::CheckSimbols(Simbolo simbolo_param){
  for (int i = 0; i < simbolo_param.Size(); i++) {
    if (simbolo_param.position(i) == kCadenaVacia) {
      return false;
    }
  }
  return true;
}

int Simbolo::Size(){
  return s_.size();
}

const char Simbolo::position(int index){
  return s_[index];
}

std::ostream& operator<<(std::ostream& os, const Simbolo& param_simbolo){
  os << param_simbolo.s_;
  return os;
}