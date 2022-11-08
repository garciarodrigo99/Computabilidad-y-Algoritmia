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

#define kArgumentos 3
#define POS_FA_FILE 1
#define POS_CHAIN_FILE 2
#define DEFAULT_ALPHABET_SYMBOL "0"

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name
            << " input.fa input.txt\n\n"
               "input.fa\tFichero de texto que describe todos los elementos de automata finito.\n"
               "input.txt\tFichero de texto que contiene diferentes cadenas.\n";
}

int main(int argc, char *argv[]) {
  // clang-format -i style=Google ejemplo.cc

  if ((argv[1] == "-h") || (argv[1] == "--help")) information(argv[0]);

  //  Comprobar numero de argumentos de ejecucion son correctos
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }
  

  std::string automataFileName = argv[POS_FA_FILE]; // Parametro 1

  Automata myAutomata(automataFileName);
  std::cout << myAutomata;

  std::string chainsFileName = argv[POS_CHAIN_FILE];
  std::ifstream chainFile(chainsFileName.c_str());
  std::string chainFileLine;

  while (getline(chainFile,chainFileLine)) {
    std::cout << chainFileLine << " ---";
    if (myAutomata.acceptChain(chainFileLine)) 
      std::cout << "\033[;32m Accepted\033[0m\n";
    else std::cout << "\033[;31m Rejected\033[0m\n";
  }

  return 0;
}