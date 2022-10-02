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
#include <algorithm>
#include <string.h>
#include "simbolo.h"
#include "alfabeto.h"
#include "cadena.h"



int main(){

  Cadena c1;
  std::cout << "Cadena: " << c1 << ", longitud: " << c1.Longitud() << ",\tinversa: ";
  c1.Inversa().Print();
  std::endl(std::cout);

  Cadena c2;
  c2.AddSimbolo(Simbolo("a"));
  c2.AddSimbolo(Simbolo("b"));
  c2.AddSimbolo(Simbolo("b"));
  c2.AddSimbolo(Simbolo("a"));
  c2.AddSimbolo(Simbolo("b"));

  std::cout << "Cadena: " << c2 << ", longitud: " << c2.Longitud() << ",\tinversa: ";
  c2.Inversa().Print();
  std::endl(std::cout);

  Cadena c3(Simbolo("6"));
  c3.AddSimbolo(Simbolo("7"));
  c3.AddSimbolo(Simbolo("9"));
  c3.AddSimbolo(Simbolo("3"));
  c3.AddSimbolo(Simbolo("8"));
  c3.AddSimbolo(Simbolo("3"));
  c3.AddSimbolo(Simbolo("6"));

  std::cout << "Cadena: " << c3 << ", longitud: " << c3.Longitud() << ",\tinversa: ";
  c3.Inversa().Print();
  std::endl(std::cout);

  Cadena c4;
  c4.AddSimbolo(Simbolo("h"));
  c4.AddSimbolo(Simbolo("o"));
  c4.AddSimbolo(Simbolo("l"));
  c4.AddSimbolo(Simbolo("a"));

  std::cout << "Cadena: " << c4 << ", longitud: " << c4.Longitud() << ",\tinversa: ";
  c4.Inversa().Print();
  std::endl(std::cout);

  return 0;
}