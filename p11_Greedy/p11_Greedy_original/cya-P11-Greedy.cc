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

// #include <algorithm>
// #include <chrono>
// #include <fstream>
#include <iostream>
// #include <stdlib.h>
// #include <thread>

#include "alfabeto.h"
#include "simbolo.h"
#include "amount.h"

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
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }
  GreedyMoneyChange aux;
  //std::cout << aux.biggestElementLessThanSum(coinSet, 150) << std::endl;
  // Cash* a = new Coin(10);
  // Coin c(10);
  // if (c < 11) std::cout << "hola\n"; return 0;
  //std::cout << a << std::endl;
  // a->print(std::cout);
  // std::cout << c << std::endl;
  // std::cout << "Solución: ";
  // for (auto i: aux.returnChange(42534))
  //   std::cout << i << " ";
  // std::endl(std::cout);
  // std::cout << "Total monedas: " << aux.returnChange(42534).size() << std::endl;

  std::cout << aux.returnChangeAmount(42534) << std::endl;

  return 0;
}