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

#include "calculator.h"
#include "lenguaje.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <thread>

#define kArgumentos 2
#define kDelimeter ' '
#define POS_FILE_IN 1
#define SET_OPENER '{'
#define SET_CLOSER '}'
#define LANG_ASSIGN '='
#define CHAIN_SEPARATOR ','
#define DEFAULT_ALPHABET_SYMBOL "0"

Language ReadLanguage(std::vector<std::string> string_vector) {
  std::string alphabet_id(string_vector.at(0));
  std::set<Chain> chain_set;
  std::set<Symbol> symbol_set; // Para el alfabeto

  for (size_t i = 2; i < string_vector.size(); i++) {
    // Lenguaje que contiene a la cadena vacia
    std::vector<Symbol> symbol_vector; // Para la cadena
    // Condiciones donde puede aparecer la cadena vacia
    if (((string_vector.at(i).size() == 3) &&
         (string_vector.at(i).at(1) == kEmptyChain)) ||
        ((string_vector.at(i).size() == 2) &&
         (string_vector.at(i).at(0) == kEmptyChain))) {
      Chain empty_chain;
      chain_set.insert(empty_chain);
    } else {
      for (size_t j = 0; j < string_vector.at(i).size(); j++) {
        bool read = ((string_vector.at(i).at(j) != SET_OPENER) &&
                     (string_vector.at(i).at(j) != SET_CLOSER) &&
                     (string_vector.at(i).at(j) != CHAIN_SEPARATOR) &&
                     (string_vector.at(i).at(j) != kEmptyChain));
        if (read == true) {
          std::string str_aux;
          str_aux.push_back(string_vector.at(i).at(j));
          symbol_vector.push_back(Symbol(str_aux));
          symbol_set.insert(Symbol(str_aux));
        }
      }
      // Condicion solo si no es lenguaje vacio
      if (symbol_vector.size() > 0) {
        Chain aux_chain(symbol_vector);
        chain_set.insert(aux_chain);
      }
    }
  }

  // Ningún símbolo reconocido
  if (symbol_set.size() == 0) {
    symbol_set.insert(Symbol(DEFAULT_ALPHABET_SYMBOL));
  }

  Alphabet alfa(symbol_set);
  Language lang(alfa, chain_set, alphabet_id);
  return lang;
}

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

  std::string nombre_archivo = argv[POS_FILE_IN]; // Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;
  // Guadar la definicion del conjunto de lenguajes
  std::set<Language> languages_set;
  // Guadar las n operaciones del fichero
  std::vector<std::string> operations_vector;
  // Lectura fichero
  while (getline(archivo, linea)) {
    if (SplitChain(linea, kDelimeter).at(1).at(0) == LANG_ASSIGN) {
      // Caso definición lenguaje
      languages_set.insert(ReadLanguage(SplitChain(linea, kDelimeter)));
    } else {
      // Caso operacion
      operations_vector.push_back(linea);
    }
  }

  for (size_t i = 0; i < operations_vector.size(); i++) {
    std::cout << operations_vector.at(i) << std::endl;
    Calculator calc(languages_set);
    std::cout << calc.GetResult(operations_vector.at(i), kDelimeter)
              << std::endl;
    std::endl(std::cout);
  }

  return 0;
}