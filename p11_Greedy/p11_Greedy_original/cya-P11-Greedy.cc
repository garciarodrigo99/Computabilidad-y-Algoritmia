/**
 * @file cya-P06-Automata-Simulator.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Programa principal
 * @version 1.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include <string>

#include "cash.h"
#include "greedy.h"

#define kArgumentos 1

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name
            << " input.fa input.txt\n\n"
               "input.fa\tFichero de texto que describe todos los elementos de "
               "automata finito.\n"
               "input.fa\tFichero de texto que contiene diferentes cadenas.\n";
}

int main(int argc, char *argv[]) {
  // clang-format -i style=Google ejemplo.cc

  // if ((argv[1] == "-h") || (argv[1] == "--help")) information(argv[0]);

  //  Comprobar numero de argumentos de ejecucion son correctos
  // if (argc != kArgumentos) {
  //   std::cout << "¡Error de formato!\n\n";
  //   information(argv[0]);
  //   return 1;
  // }
  GreedyMoneyChange aux;

  float f = std::stof(argv[argc-1]);
  int i = (int)(f*100);
  std::cout << aux.returnChangeAmount(i);

  return 0;
}