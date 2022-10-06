#include "simbolo.h"

#include <assert.h>

Symbol::Symbol(const std::string param) : symbol_(param) {
  assert(CheckSimbols(*this));
}

//Destructor
Symbol::~Symbol(){}

std::string Symbol::GetSymbol(){
  return symbol_;
}

std::string Symbol::GetSymbol()const{
  return symbol_;
}

/* Comprueba, comparando con el simbolo por parametro, si un simbolo es igual 
a otro*/
bool Symbol::isEqual(Symbol simbolo_param) {
  if ((symbol_.compare(simbolo_param.GetSymbol())) == 0) { //Cambiar
    return true;
  } else { 
    return false;
  }
}

bool Symbol::isEqual(Symbol simbolo_param)const{
  if ((symbol_.compare(simbolo_param.GetSymbol())) == 0) { //Cambiar
    return true;
  } else { 
    return false;
  }
}

//Comprueba que no contiene el simbolo reservado para la cadena vacía
bool Symbol::CheckSimbols(Symbol simbolo_param){
  for (int i = 0; i < simbolo_param.Size(); i++) {
    if (simbolo_param.position(i) == kEmptyChain) {
      return false;
    }
  }
  return true;
}

// Devuelve el numero de caracteres del simbolo
int Symbol::Size()const{
  return symbol_.size();
}

// Devuelve el caracter que ocupa index posicion
const char Symbol::position(int index){
  return symbol_[index];
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, const Symbol& param_simbolo){
  os << param_simbolo.symbol_;
  return os;
}