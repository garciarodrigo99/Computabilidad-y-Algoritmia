#include "cadena.h"

#include <assert.h>
#include <string.h>
#include <algorithm>

//https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
//https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
//https://en.cppreference.com/w/c/string/byte/strcmp 

Cadena::Cadena(){
  std::cout << "Constructor 1\n";
  c_.push_back(kCadenaVacia);
}

Cadena::Cadena(std::vector<Simbolo> param) : c_(param){
  std::cout << "Constructor 2\n";
  for (size_t i = 0; i < c_.size(); i++) {
    assert(strcmp(c_.at(i).GetSimbolo(),kCadenaVacia) != 0);
  }
}//Funciona

Cadena::Cadena(Simbolo param) : Cadena() {
  std::cout << "Constructor 3\n";
  assert(strcmp(param.GetSimbolo(),kCadenaVacia) != 0); // No se puede insertar cadena vacia
  c_.front().SetSimbolo(param.GetSimbolo());
}

/*
  Constructor de copia de la clase
  Se hace el if ese para poder 
*/
Cadena::Cadena(Cadena& param) : c_(param.GetCadena()){
  std::cout << "Constructor 4\n";
  if (!((c_.size()==1) && (strcmp(c_.front().GetSimbolo(),kCadenaVacia) == 0))) { 
    for (size_t i = 1; i < c_.size(); i++) {
      assert(strcmp(c_.at(i).GetSimbolo(),kCadenaVacia) != 0);
    }
  }
}

void Cadena::AddSimbolo(Simbolo param){
  if (strcmp(c_.front().GetSimbolo(),kCadenaVacia) == 0) {  // Si el primer elemento es la cadena vacia
    c_.front().SetSimbolo(param.GetSimbolo());    // simbolo parametro es ahora primer elemento
  } else {
    c_.push_back(param);                        // Añadir simbolo
  }
}//Funciona

std::vector<Simbolo>& Cadena::GetCadena(){
  return c_;
}//Funciona

int Cadena::Longitud(){
  if ((c_.size() == 1) && (strcmp(c_.front().GetSimbolo(),kCadenaVacia) == 0)) {    // Cadena vacia
    return 0;
  } else
    return c_.size();
}//Funciona

Cadena Cadena::Inversa(){
  if ((c_.size() == 1) && (strcmp(c_.front().GetSimbolo(),kCadenaVacia) == 0))      // Cadena vacia
    return *this;
    
  // Cadena inversa;
  // int cont = 0;
  // for (size_t i = (c_.size() - 1); i < c_.size(); --i) {     // De esta forma no se sale de rango
  // //  for (size_t i = (c_.size() - 1); cont < c_.size(); --i) {     // De esta forma no se sale de rango
  //   //std::cout << "Pos " << i << " Iter" << cont <<"\n";
  //   cont++;
  //   inversa.AddSimbolo(c_.at(i));
  // }

  Cadena inversa(*this);
  std::reverse(inversa.GetCadena().begin(),inversa.GetCadena().end());

  return inversa;
}

void Cadena::Print(){
    for (size_t i = 0; i < c_.size(); i++) {
        std::cout << c_.at(i).GetSimbolo();
    }
    //std::endl(std::cout);
}

std::ostream& operator<<(std::ostream& os, Cadena& param_cadena){
  for (size_t i = 0; i < param_cadena.GetCadena().size(); i++){
    os << param_cadena.GetCadena().at(i);
  }
  return os;
}