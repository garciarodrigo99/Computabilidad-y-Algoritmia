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
#include "cadena.h"

int main(){

  Cadena c1;

  Cadena c2;
  c2.AddSimbolo(Simbolo("a"));
  c2.AddSimbolo(Simbolo("b"));
  c2.AddSimbolo(Simbolo("b"));
  c2.AddSimbolo(Simbolo("a"));
  c2.AddSimbolo(Simbolo("b"));



  Cadena c3(Simbolo("6"));
  c3.AddSimbolo(Simbolo("7"));
  c3.AddSimbolo(Simbolo("9"));
  c3.AddSimbolo(Simbolo("3"));
  c3.AddSimbolo(Simbolo("8"));
  c3.AddSimbolo(Simbolo("3"));
  c3.AddSimbolo(Simbolo("6"));

  std::vector<Simbolo> v4;
  v4.push_back("h");
  v4.push_back("o");
  v4.push_back("l");
  v4.push_back("a");
  Cadena c4(v4);

  std::cout << "Cadena: ";
  c1.Print();
  std::cout << ", longitud: " << c1.Longitud() << std::endl;

  std::cout << "Cadena: ";
  c2.Print();
  std::cout << ", longitud: " << c2.Longitud() << std::endl;

  std::cout << "Cadena: ";
  c3.Print();
  std::cout << ", longitud: " << c3.Longitud() << std::endl;

  std::cout << "Cadena: ";
  c4.Print();
  std::cout << ", longitud: " << c4.Longitud() << std::endl;


  return 0;
}