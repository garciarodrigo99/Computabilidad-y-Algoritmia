// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo cya-P01-Strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "cadena.h"

#include <assert.h>
#include <algorithm>

//https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
//https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
//https://en.cppreference.com/w/c/string/byte/strcmp 

Cadena::Cadena(){}

Cadena::Cadena(Simbolo param) : Cadena() {  // Constructor con simbolo, todos menos cadena vacia
  //std::cout << "Constructor 3\n";
  // assert(!(Simbolo::CheckSimbols(param))); // No se puede insertar cadena vacia
  c_.push_back(param);
}

/*
  Constructor de copia de la clase
  Se hace el if ese para poder 
*/
Cadena::Cadena(const Cadena& param) : c_(param.GetCadena()) {}//Comprobar

void Cadena::AddSimbolo(Simbolo param){
  c_.push_back(param);
}//Funciona2

const std::vector<Simbolo>& Cadena::GetCadena()const{
  return c_;
}//Funciona

int Cadena::Longitud(){
    return c_.size();
}

Cadena Cadena::Inversa(){
  if (c_.size()==0){
    return *this;
  }

  Cadena inversa;
  for (int i = (c_.size() - 1); i >= 0; --i) {     // De esta forma no se sale de rango
    inversa.AddSimbolo(c_.at(i));
  }
  return inversa;
}

bool Cadena::inSimbolo(Simbolo simbolo_param){
  for (size_t i = 0; i < c_.size(); i++){
    if (c_.at(i).isEqual(simbolo_param)) {
      return true;
    }
  }
  return false;
}

std::vector<Cadena> Cadena::Prefijo(){
  std::vector<Cadena> prefijos;
  Cadena v;
  prefijos.push_back(v);
  for (size_t i = 0; i < c_.size(); i++) {
    Cadena cadena_aux;
    for (size_t j = 0; j <= i; j++) {
      cadena_aux.AddSimbolo(c_.at(j));
    }
    prefijos.push_back(cadena_aux);
  }
  return prefijos;
}

std::vector<Cadena> Cadena::Subcadena(){
  std::vector<Cadena> subcadena;
  Cadena v;
  subcadena.push_back(v);
  for (int len = 1; len <= c_.size(); len++) {
    for (int i = 0; i <= (c_.size() - len); i++) {
      Cadena cadena_aux;
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        cadena_aux.AddSimbolo(c_.at(k));
      }
      subcadena.push_back(cadena_aux);
    }
    //std::cout << "Subcadena: " << cadena_aux << std::endl;
  }
  return subcadena;
}

std::vector<Cadena> Cadena::Sufijo(){
  std::vector<Cadena> sufijos;
  Cadena v;
  sufijos.push_back(v);
  for (int i = (c_.size()-1); i >= 0; i--) {
    Cadena cadena_aux;
    for (int j = i; j < c_.size(); j++) {
      cadena_aux.AddSimbolo(c_.at(j));
    }
    sufijos.push_back(cadena_aux);
  }
  return sufijos;
}

void Cadena::Print(){
  if (c_.size()==0) {
    std::cout << kCadenaVacia;
  } else {  
    for (size_t i = 0; i < c_.size(); i++) {
        std::cout << c_.at(i);
    }
  }
}

std::ostream& operator<<(std::ostream& os, Cadena& param_cadena){
  if (param_cadena.Longitud()==0) {
    return os << kCadenaVacia;
  } else {  
    for (int i = 0; i < param_cadena.Longitud(); i++){
      os << param_cadena.c_.at(i);
    }
    return os;
  }
}