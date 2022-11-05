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

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <thread>

#include "alfabeto.h"
#include "cadena.h"
#include "automata.h"

#define kArgumentos 3
#define kDelimeter ' '
#define POS_FA_FILE 1
#define POS_CHAIN_FILE 2
#define DEFAULT_ALPHABET_SYMBOL "0"

// Language ReadLanguage(std::vector<std::string> string_vector) {
//   // ID lenguaje
//   std::string language_id(string_vector.at(0));
//   std::set<Chain> chain_set;
//   std::set<Symbol> symbol_set; // Para alfabeto

//   // Empieza en dos ya que i=0 es nombre lenguaje
//   // e i=1 es simbolo igual
//   for (size_t i = 2; i < string_vector.size(); i++) {
//     std::vector<Symbol> symbol_vector; // Para cadena
//     // Condiciones donde puede aparecer la cadena vacia
//     // Las demas opciones no serían correctas
//     if (((string_vector.at(i).size() == 3) &&
//          (string_vector.at(i).at(1) == kEmptyChain)) ||
//         ((string_vector.at(i).size() == 2) &&
//          (string_vector.at(i).at(0) == kEmptyChain))) {
//       Chain empty_chain;
//       chain_set.insert(empty_chain);
//     } else {
//       for (size_t j = 0; j < string_vector.at(i).size(); j++) {
//         // Si se encuentra algunos de los siguientes elementos, no se inserta
//         bool read = ((string_vector.at(i).at(j) != SET_OPENER) &&
//                      (string_vector.at(i).at(j) != SET_CLOSER) &&
//                      (string_vector.at(i).at(j) != CHAIN_SEPARATOR) &&
//                      (string_vector.at(i).at(j) != kEmptyChain));
//         if (read == true) {
//           std::string str_aux;
//           str_aux.push_back(string_vector.at(i).at(j));
//           symbol_vector.push_back(Symbol(str_aux));
//           symbol_set.insert(Symbol(str_aux));
//         }
//       }
//       // Condicion solo si no es lenguaje vacio
//       if (symbol_vector.size() > 0) {
//         Chain aux_chain(symbol_vector);
//         chain_set.insert(aux_chain);
//       }
//     }
//   }

//   // Ningún símbolo reconocido, generar alfabeto por defecto y lenguaje vacio
//   if (symbol_set.size() == 0) {
//     symbol_set.insert(Symbol(DEFAULT_ALPHABET_SYMBOL));
//   }

//   Alphabet alfa(symbol_set);
//   Language lang(alfa, chain_set, language_id);
//   return lang;
// }

std::vector<std::string> SplitChain(std::string str, char pattern = kDelimeter) {
    
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;
    
    while(posFound >= 0){
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
  std::cout << myAlphabet << std::endl;

  // Simbolos numero estados automata
  getline(archivo, linea);
  int nStates = linea.at(0) - 48;
	std::cout << nStates << std::endl;

  // Estado arranque
  getline(archivo, linea);
  int initialState = linea.at(0) - 48; 
	std::cout << initialState << std::endl;

  std::vector<std::vector<std::string>> statesInformation; // Parte del fichero descripcion estados
  std::set<State> auxStateSet; // Conjunto auxiliar de estados
  for (int iteratorLine = 0; iteratorLine < nStates; iteratorLine++) {
    getline(archivo, linea);
    statesInformation.push_back(SplitChain(linea));
    // Identificador y si es estado final
    State auxState(stoi(SplitChain(linea).at(0)));
    if (stoi(SplitChain(linea).at(1)) == 1) auxState.setFinalState();
    // Insertar estado en conjunto
    auxStateSet.insert(auxState);
  }
  for (int iteratorStates = 0; iteratorStates < statesInformation.size();
      iteratorStates++) {
    int nTransitions = stoi(statesInformation.at(iteratorStates).at(2));
    
  }
    //   State auxState(stoi(auxStrVector.at(0)));
    // if (stoi(auxStrVector.at(1)) == 1) auxState.setFinalState();
    // int nTransitions = stoi(auxStrVector.at(2));
    // for (size_t i = 0; i < nTransitions; i = i + 2) {
    //   Transition 
    // }

  // for (size_t i = 0; i < operations_vector.size(); i++) {
  //   std::cout << operations_vector.at(i) << std::endl;
  //   Calculator calc(languages_set);
  //   std::cout << calc.GetResult(operations_vector.at(i), kDelimeter)
  //             << std::endl;
  //   std::endl(std::cout);
  // }

  return 0;
}