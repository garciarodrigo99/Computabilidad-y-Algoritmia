#include "cadena.h"

#include <assert.h>

Cadena::Cadena(){
  c_.push_back(kCadenaVacia);
}

Cadena::Cadena(std::vector<Simbolo> param) : c_(param){}

Cadena::Cadena(Simbolo param){
  assert(param.GetSimbolo() != kCadenaVacia);   // No se puede insertar cadena vacia
  if (c_.at(0).GetSimbolo() == kCadenaVacia) {  // Si el primer elemento es la cadena vacia
    c_.at(0).SetSimbolo(param.GetSimbolo());    // simbolo parametro es ahora primer elemento
  } else {
    c_.push_back(param);                        // Añadir simbolo
  }
}

int Cadena::Longitud(){

}