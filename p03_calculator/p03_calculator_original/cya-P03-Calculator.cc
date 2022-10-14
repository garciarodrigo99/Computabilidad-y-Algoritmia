// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo cya-P02-Languages.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "lenguaje.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <stdlib.h>

#define kArgumentos 2
#define kDelimeter ' '
#define POS_FILE_IN 1
#define SET_OPENER '{'
#define SET_CLOSER '}'
#define LANG_ASSIGN '='
#define CHAIN_SEPARATOR ','
#define DEFAULT_ALPHABET_SYMBOL "0"

// Funcion para separar cada linea en cadenas según espacios
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

Language ReadLanguage(std::vector<std::string> string_vector) {
  std::string alphabet_id(string_vector.at(0));
  std::set<Chain> chain_set;
  std::set<Symbol> symbol_set;          //Para el alfabeto

  for (size_t i = 2; i < string_vector.size(); i++) {
    // Lenguaje que contiene a la cadena vacia
    std::vector<Symbol> symbol_vector;  //Para la cadena
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
  Language lang(alfa,chain_set,alphabet_id);
  std::cout << lang << "\talfabeto: " << alfa << "\n" << std::endl;
  return lang;
}

// // Funcion que imprime por pantalla un conjunto de cadenas
// void PrintChainSet(std::set<Chain> param_set){
//   std::cout << "{ ";

//   for (std::set<Chain>::iterator it = param_set.begin();
//       it != param_set.end(); ++it)
//       std::cout << *it << " ";

//   std::cout << "}\n";
// }

// Funcion que indica la forma correcta de ejecutar y cada parametro a 
// introducir en caso de error.
void information(char* p_name){
    std::cout <<"La forma correcta de ejecutar el programa es:\n"
    << p_name << " ficheroentrada.txt\n\n"
    "ficheroentrada.txt\tFichero de texto que contiene las cadenas que forman "
    "un lenguaje\n";
}

int main(int argc, char* argv[]){

  // Comprobar numero de argumentos de ejecucion son correctos
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  }

  std::string nombre_archivo = argv[POS_FILE_IN]; //Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;
  std::vector<Language> languages_vector;
  std::vector<std::string> operations_vector;
  // Comienza lectura de fichero 1, se almacenará en un vector de Language
  // para más tarde trabajar con el
  while (getline(archivo, linea)) {
    // Lo hago de esta manera para evitar llamar dos veces a la misma funcion
    // en las igualaciones
    //std::pair<Alphabet, int> pair_value(ReadAlphabet(linea));
    //SplitChain(linea);
    if (SplitChain(linea).at(1).at(0) == LANG_ASSIGN ) {
      languages_vector.push_back(ReadLanguage(SplitChain(linea)));
    }
    
    // Language aux(pair_value.first);
    // int iterator = pair_value.second + 2;
    // Language lang(ReadLanguage(linea,iterator,aux));
    // languages_vector.push_back(lang);
  }

  // Si es operacion unaria, se evita lectura fichero2
  for (size_t i = 0; i < languages_vector.size(); i++) {
    //Menu(atoi(argv[argc - 1]), vector_language_file1.at(i), 
        //vector_language_file1.at(i));
  }

  return 0;
}