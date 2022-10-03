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
#include <fstream>
#include <chrono>
#include <thread>
#include "simbolo.h"
#include "alfabeto.h"
#include "cadena.h"

int main(){

  // Cadena c1;
  // std::cout << "Cadena: " << c1 << ", longitud: " << c1.Longitud() << ",\tinversa: ";
  // c1.Inversa().Print();
  // std::endl(std::cout);

  // Cadena c2;
  // std::string stra("a");
  // Simbolo a(stra);
  // std::string strb("b");
  // Simbolo b(strb);
  // c2.AddSimbolo(a);
  // c2.AddSimbolo(b);
  // c2.AddSimbolo(b);
  // c2.AddSimbolo(a);
  // c2.AddSimbolo(b);

  // std::cout << "Cadena: " << c2 << ", longitud: " << c2.Longitud() << ",\tinversa: ";
  // c2.Inversa().Print();
  // std::endl(std::cout);
  // for (size_t i = 0; i < c2.Prefijo().size(); i++) {
  //   std::cout << c2.Prefijo().at(i) << " ";
  // }
  // std::endl(std::cout);


  // Cadena c3(Simbolo("6"));
  // c3.AddSimbolo(Simbolo("7"));
  // c3.AddSimbolo(Simbolo("9"));
  // c3.AddSimbolo(Simbolo("3"));
  // c3.AddSimbolo(Simbolo("8"));
  // c3.AddSimbolo(Simbolo("3"));
  // c3.AddSimbolo(Simbolo("6"));

  // std::cout << "Cadena: " << c3 << ", longitud: " << c3.Longitud() << ",\tinversa: ";
  // c3.Inversa().Print();
  // std::endl(std::cout);
  // for (size_t i = 0; i < c3.Prefijo().size(); i++) {
  //   std::cout << c3.Prefijo().at(i) << " ";
  // }
  // std::endl(std::cout);

  // Cadena c4;
  // c4.AddSimbolo(Simbolo("h"));
  // c4.AddSimbolo(Simbolo("o"));
  // c4.AddSimbolo(Simbolo("l"));
  // c4.AddSimbolo(Simbolo("a"));

  // std::cout << "Cadena: " << c4 << ", longitud: " << c4.Longitud() << ",\tinversa: ";
  // c4.Inversa().Print();
  // std::endl(std::cout);
  // for (size_t i = 0; i < c4.Prefijo().size(); i++) {
  //   std::cout << c4.Prefijo().at(i) << " ";
  // }
  // std::endl(std::cout);
  // for (size_t i = 0; i < c4.Prefijo().size(); i++) {
  //   std::cout << c4.Sufijo().at(i) << " ";
  // }
  // std::endl(std::cout);

  std::string nombre_archivo = "ejemplo.txt"; //Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;
  //char delimitador = ' ';
  while (getline(archivo, linea)) {
    std::cout << "Linea: " << linea << std::endl;
    std::vector<Cadena> vector_aux;
    int iterator1 = 0;
    while (iterator1<linea.size()){
      std::cout << "Bucle1\n";
      Cadena cadena_aux;
      int iterator2 = iterator1;
      std::string string_aux;
      while ((iterator2<linea.size()) && (linea.at(iterator2) != ' ')){
        std::cout << "Bucle\t2\n";
        string_aux.push_back(linea.at(iterator2));
        iterator2++;
      }
      Simbolo simbolo_aux(string_aux);
      cadena_aux.AddSimbolo(simbolo_aux);
      iterator1 = (iterator2+1);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
  }

  return 0;
}