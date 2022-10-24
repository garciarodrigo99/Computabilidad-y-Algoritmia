// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo cya-P02-Languages.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "codeStructurer.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <thread>

#define kArgumentos 3
#define kDelimeter ' '
#define POS_FILE_IN 1
#define POS_FILE_OUT 2

// Funcion externa para separar cada linea en cadenas según espacios
std::vector<std::string> SplitChain(std::string str, char pattern) {

  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  return results;
}

// Funcion externa para separar cada linea en cadenas según espacios
void RemoveInitialSpaces(std::string& str) {
  if (str.size()>0){
    while ((str.front() == kDelimeter) || (str.front() == '\t')) {
      str.erase(0,1);
    }
  }
}

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name << " test_code.cc codescheme.txt\n\n"
               "test_code.cc\tFichero de texto que contiene las cadenas "
               "que forman un lenguaje y operaciones con los lenguajes "
               "previamente definidos en las líneas anteriores.\n";
}

int main(int argc, char *argv[]) {
  // clang-format -i style=Google ejemplo.cc
  //  Comprobar numero de argumentos de ejecucion son correctos
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }

  std::string nombre_archivo = argv[POS_FILE_IN]; // Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;

  std::vector<std::string> string_vector;
  // Lectura fichero
  while (getline(archivo, linea)) {
    string_vector.push_back(linea);
  }
  
  // std::cout << string_vector.at(30) << std::endl;
  // std::cout << fMain::isMain(string_vector.at(30)) << std::endl;
  //std::string ejemplo("// Comentario");
  // std::cout << string_vector.at(23) << std::endl;
  // std::cout << Loop::isFor(string_vector.at(23)) << std::endl;
  std::cout << string_vector.at(22) << std::endl;
  std::cout << Variable::isInteger(string_vector.at(22)) << std::endl;
  return 0;
  CodeStructurer myCodeStructurer(argv[1],argv[2]);
  myCodeStructurer.Write();

  // std::cout << "MAIN: \n";
  // if (fMain::isMain(string_vector.at(30))) std::cout << "True" << std::endl;
  // else std::cout << "False" << std::endl;
  
  return 0;
}