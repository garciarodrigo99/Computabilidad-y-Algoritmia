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

int main(int argc, char* argv[]){

  std::string nombre_archivo = "ejemplo.txt"; //Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;
  //char delimitador = ' ';
  while (getline(archivo, linea)) {
    std::vector<Cadena> vector_cadena;
    int iterator1 = 0;
    while (iterator1<linea.size()){
      //std::cout << "Bucle1\n";
      int iterator2 = iterator1;
      std::vector<Simbolo> vector_simbolo;
      while ((iterator2<linea.size()) && (linea.at(iterator2) != ' ')){
        std::string string_aux;
        string_aux = linea.at(iterator2);
        Simbolo simbolo_aux(string_aux);
        vector_simbolo.push_back(simbolo_aux);
        iterator2++;
      }
      Cadena cadena_aux;
      for (size_t i = 0; i < vector_simbolo.size(); i++){
        cadena_aux.AddSimbolo(vector_simbolo.at(i));
      }
      vector_cadena.push_back(cadena_aux);
      iterator1 = (iterator2+1);
      //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "Cadena: " << vector_cadena.back() << ", longitud: " << vector_cadena.back().Longitud() << ",\tinversa: ";
    vector_cadena.back().Inversa().Print();
    std::endl(std::cout);
    for (size_t i = 0; i < vector_cadena.back().Prefijo().size(); i++) {
      std::cout << vector_cadena.back().Prefijo().at(i) << " ";
    }
    std::endl(std::cout);
    for (size_t i = 0; i < vector_cadena.back().Sufijo().size(); i++) {
      std::cout << vector_cadena.back().Sufijo().at(i) << " ";
    }
    std::endl(std::cout);
  }

  return 0;
}