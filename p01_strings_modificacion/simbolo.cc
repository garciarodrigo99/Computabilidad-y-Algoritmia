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

std::string Simbolo::GetSimbolo(){
  return s_;
}

std::string Simbolo::GetSimbolo()const{
  return s_;
}
    
bool Simbolo::isEqual(Simbolo simbolo_param) {
  if ((s_.compare(simbolo_param.GetSimbolo())) == 0) {
    return true;
  } else { 
    return false;
  }
}

//Comprueba que no contiene el simbolo reservado para la cadena vacía
bool Simbolo::CheckSimbols(Simbolo simbolo_param){
  for (int i = 0; i < simbolo_param.Size(); i++) {
    if (simbolo_param.position(i) == kCadenaVacia) {
      return false;
    }
  }
  return true;
}

int Simbolo::Size()const{
  return s_.size();
}

const char Simbolo::position(int index){
  return s_[index];
}

std::ostream& operator<<(std::ostream& os, const Simbolo& param_simbolo){
  os << param_simbolo.s_;
  return os;
}