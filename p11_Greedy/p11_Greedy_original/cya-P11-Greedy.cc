/**
 * @file cya-P06-Automata-Simulator.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy). Cambio de Monedas
 * @brief Programa principal
 * @version 1.0
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include <string>

#include "cash.h"
#include "greedy.h"

#define minArg 2
#define maxArg 4

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name
            << " [-b | -o] cambio\n\n"
               "-b\tOpción para icluir billetes en el cambio.\n"
               "-o\tOpción Algoritmo eficiente.\n"
               "cambio\tDinero en € a cambiar.\n";
}

int main(int argc, char *argv[]) {
  // clang-format -i style=Google ejemplo.cc

  // if ((argv[1] == "-h") || (argv[1] == "--help")) information(argv[0]);

  //  Comprobar numero de argumentos de ejecucion son correctos
  if ((argc < minArg) || (argc > maxArg)) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }
  GreedyMoneyChange aux;

  float f = std::stof(argv[argc - 1]);
  int i = (int)(f * 100);
  std::string option = argv[1];
  if (option.compare("-b") == 0) {
    Amount myAmount;
    myAmount = aux.returnChangeAmount(i, 'b');
    std::cout << myAmount;
    std::cout << "\nTotal monedas o billetes: " << myAmount.getSize()
              << std::endl;
    // std::cout << "\nMonedas unicas: " << myAmount.uniqueCash().size() <<
    // std::endl;
  } else {
    Amount myAmount;
    myAmount = aux.returnChangeAmount(i);
    std::cout << myAmount;
    std::cout << "\nTotal monedas: " << myAmount.getSize() << std::endl;
    // std::cout << "\nMonedas unicas: " << myAmount.uniqueCash().size() <<
    // std::endl;
  }
  return 0;
}