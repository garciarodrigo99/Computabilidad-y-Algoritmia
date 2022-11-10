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
  Grammar gra(grammarFileName);
  std::cout << gra << std::endl;
  std::set<ProductionRule> testProductionRule;
  Symbol S("S");
  Symbol Z("Z");
  Symbol zero("0");
  Symbol A("A");
  std::vector<Symbol> symbolVector;
  symbolVector.push_back(zero);
  symbolVector.push_back(A);
  ProductionRule pr1(S,symbolVector);
  ProductionRule pr2(Z,symbolVector);
  testProductionRule.insert(pr1);
  testProductionRule.insert(pr2);
  for (auto pr : testProductionRule)
    std::cout << pr << std::endl;
  std::cout << "Iguales: " << (pr1==pr2) << std::endl;
//   std::string firstAutomataFileName = argv[POS_FA_FILE]; // Parametro 1
//   Automata firstAutomata(firstAutomataFileName);

//   std::string secondAutomataFileName = argv[POS_FA_2_FILE]; // Parametro 2
//   Automata secondAutomata(secondAutomataFileName);

//   std::cout << "Primer automata: \n" << firstAutomata << std::endl;
//   std::cout << "Segundo automata \n" << secondAutomata << std::endl;

//   Symbol zero("0");
//   Symbol one("1");
//   Alphabet alfa(zero);
//   alfa.AddSymbol(one);
//   Chain chainZero(zero);
//   Chain chainOne(one);

//   Language auxLanguage(alfa,DEFAULT_NAME);
//   auxLanguage.AddChain(chainOne);
//   auxLanguage.AddChain(chainZero);

//   int n = atoi(argv[POS_SIZE]);
//   std::set<Chain> chainSet(auxLanguage.PowerSetChain(n));

//   //std::cout << auxLanguage.Power(n) << std::endl;

//   for (auto iterator : chainSet) {
//     std::cout << iterator << std::endl;
//     if (firstAutomata.acceptChain(iterator) != secondAutomata.acceptChain(iterator)) {
//       std::cout << iterator;
//       std::cout << ": automata 1: " << std::boolalpha << firstAutomata.acceptChain(iterator);
//       std::cout << ", automata 2: " << std::boolalpha << secondAutomata.acceptChain(iterator) << std::endl;
//     }
//   }

  return 0;
}