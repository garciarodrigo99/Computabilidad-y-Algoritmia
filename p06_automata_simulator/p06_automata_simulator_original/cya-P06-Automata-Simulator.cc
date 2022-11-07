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
#define kDelimeter ' '
#define POS_FA_FILE 1
#define POS_CHAIN_FILE 2
#define DEFAULT_ALPHABET_SYMBOL "0"

std::vector<std::string> SplitChain(std::string str,
                                    char pattern = kDelimeter) {

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

// std::pair<Alphabet, int> ReadAlphabet(std::string string){
//   std::set<Symbol> symbol_set;
//   int iterator = 1;
//   // While para recorrer los primeros corchetes(alfabeto)
//   while (SplitChain(string,kDelimeter).at(iterator).at(0) != SET_CLOSER) {
//     symbol_set.insert(SplitChain(string,kDelimeter).at(iterator));
//     iterator++;
//   }
//   Alphabet alfa(symbol_set);
//   return std::pair<Alphabet, int>(alfa,iterator);
// }

// Funcion que indica la forma correcta de ejecutar y cada parametro a
// introducir en caso de error.
void information(char *p_name) {
  std::cout << "La forma correcta de ejecutar el programa es:\n"
            << p_name
            << " ficheroentrada.txt\n\n"
               "ficheroentrada.txt\tFichero de texto que contiene las cadenas "
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

  std::string nombre_archivo = argv[POS_FA_FILE]; // Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;

  // Simbolos alfabeto
  getline(archivo, linea);
  std::set<Symbol> auxSet;
  for (size_t i = 0; i < SplitChain(linea).size(); i++) {
    auxSet.insert(SplitChain(linea).at(i));
  }
  Alphabet myAlphabet(auxSet);

  // Simbolos numero estados automata
  getline(archivo, linea);
  int nStates = linea.at(0) - 48;

  // Estado arranque
  getline(archivo, linea);
  int initialState = linea.at(0) - 48;

  std::vector<std::vector<std::string>>
      statesInformation;       // Parte del fichero descripcion estados
  std::set<State> auxStateSet; // Conjunto auxiliar de estados

  getline(archivo, linea);
  statesInformation.push_back(SplitChain(linea));
  // Identificador y si es estado final
  if (stoi(SplitChain(linea).at(0)) != initialState)
    return 1;

  State auxState(stoi(SplitChain(linea).at(0)));
  if (stoi(SplitChain(linea).at(1)) == 1)
    auxState.setFinalState();
  // Insertar estado en conjunto
  auxStateSet.insert(auxState);

  Automata myAutomata(myAlphabet, auxState);

  for (int iteratorLine = 1; iteratorLine < nStates; iteratorLine++) {
    getline(archivo, linea);
    statesInformation.push_back(SplitChain(linea));
    // Identificador y si es estado final
    State auxState(stoi(SplitChain(linea).at(0)));
    if (stoi(SplitChain(linea).at(1)) == 1)
      auxState.setFinalState();
    // Insertar estado en conjunto
    myAutomata.addState(auxState);
  }

  // myAutomata.print();

  for (size_t iteratorStates = 0; iteratorStates < statesInformation.size();
       iteratorStates++) {
    int nTransitions = stoi(statesInformation.at(iteratorStates).at(2));
    int positions = 3;
    for (int i = 0; i < nTransitions; i++) {

      int originId = stoi(statesInformation.at(iteratorStates).at(0));
      int destinationId =
          stoi(statesInformation.at(iteratorStates).at(positions + 1));
      myAutomata.addTransition(
          originId, Symbol(statesInformation.at(iteratorStates).at(positions)),
          destinationId);
      positions += 2;
    }
  }
  std::endl(std::cout);
  std::cout << myAutomata << std::endl;

  Symbol one("1");
  Symbol zero("0");
  Chain chain1(one);
  chain1.AddSymbol(one);
  chain1.AddSymbol(zero);
  std::cout << std::boolalpha << myAutomata.acceptChainNFA(chain1) << std::endl;

  return 0;
}