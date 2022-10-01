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

#include <iostream>
#include "simbolo.h"
#include "alfabeto.h"

int main(){
  Simbolo s("a");
  std::cout << s.GetSimbolo() << std::endl;

  s.SetSimbolo("c");
  std::cout << s.GetSimbolo() << std::endl;

  Alfabeto alfa(s);

  Simbolo sb("b");
  s = sb;
  //std::cout << (s==sb) << std::endl;
  Alfabeto beta(Simbolo("t"));
  char* ejemplo = kCadenaVacia;

  return 0;
}