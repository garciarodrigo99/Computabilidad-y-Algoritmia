/**
 * @file cya-P06-Automata-Simulator.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Programa principal
 * @version 1.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 */

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <thread>

#include "alfabeto.h"
#include "automata.h"
#include "cadena.h"
#include "lenguaje.h"
#include "grammar.h"

#define kArgumentos 3
#define POS_FA_FILE 1
#define POS_GRA_FILE 2
#define DEFAULT_ALPHABET_SYMBOL "0"

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name
            << " input.fa input.txt\n\n"
               "input.fa\tFichero de texto que describe todos los elementos de automata finito.\n"
               "input.fa\tFichero de texto que contiene diferentes cadenas.\n";
}

int main(int argc, char *argv[]) {
  // clang-format -i style=Google ejemplo.cc

  //if ((argv[1] == "-h") || (argv[1] == "--help")) information(argv[0]);

  //  Comprobar numero de argumentos de ejecucion son correctos
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }
  std::string grammarFileName = argv[POS_GRA_FILE]; // Parametro 1
  // Grammar gra(grammarFileName);
  // std::cout << gra << std::endl;

  std::string automatonFileName = argv[POS_FA_FILE];
  Automata fa(automatonFileName);
  std::cout << fa << std::endl;
  Grammar grammarFromDFA;
  grammarFromDFA = fa.convertToGrammar();
  std::cout << grammarFromDFA << std::endl;
  grammarFromDFA.writeFile(grammarFileName);

  return 0;
}