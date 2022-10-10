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

#define kArgumentos 4
#define kOpcode 6
#define kDelimeter ' '
#define POS_FILE_IN 1
#define POS_FILE_OUT 2
#define POS_OPCODE 3
#define SET_CLOSER '}'

std::pair<Alphabet, int> Lectura(void){
  std::pair<int, int> ejemplo(10,20);
}

// Funcion para separar cada linea en cadenas según espacios
std::vector<std::string> SplitChain(std::string str, char pattern) {
    
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

// Funcion que imprime por pantalla un conjunto de cadenas
void PrintChainSet(std::set<Chain> param_set){
  std::cout << "{ ";

  for (std::set<Chain>::iterator it = param_set.begin();
      it != param_set.end(); ++it)
      std::cout << *it << " ";

  std::cout << "}\n";
}


// Funcion para externalizar la funcionalidad menú
void Menu(Language& param_language, int opcode){
  switch (opcode) {
    case 1:
      PrintChainSet(param_language.Concatenation(param_language));
      break;
    case 2:
      PrintChainSet(param_language.Union(param_language));
      std::endl(std::cout);
      break;
    case 3:
      PrintChainSet(param_language.Intersection(param_language));
      break;
    case 4:
      PrintChainSet(param_language.Diference(param_language));
      param_language.Diference(param_language);
      break;
    case 5:
      PrintChainSet(param_language.Reverse());
      param_language.Reverse();
      break;
    case 6: {
      int pow = 3;
      // std::cout << "Introduzca el valor de la potencia: "; 
      // std::cin >> pow;
      PrintChainSet(param_language.Power(pow));

      break;
      }
    default:
      break;
  }
}

// Funcion que indica la forma correcta de ejecutar y cada parametro a 
// introducir en caso de error.
void information(char* p_name){
    std::cout <<"La forma correcta de ejecutar el programa es:\n"
    << p_name << " ficheroentrada.txt ficherosalida.txt opcode\n\n"
    "ficheroentrada.txt\tFichero de texto que contiene los simbolos de un "
    "alfabeto y un lenguaje\n"
    "ficherosalida.txt\tFichero de texto que muestra para cada alfabeto y "
    "lenguaje la opcion de salida indicada en el opcode\n"
    "opcode\t\t\tOpcion a aplicar al lenguaje dado\n";
}

int main(int argc, char* argv[]){

  // Comprobar numero de argumentos de ejecucion son correctos
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  } else {
    // Comprobar opcode esta entre los valores aceptados
    if ((atoi(argv[argc - 1]) < 1) || (atoi(argv[argc - 1]) > kOpcode)) {
      std::cout << "¡Opcode no válido!\n\n"
      "Introducir valores entre " << 1 << " y " << kOpcode << std::endl;
      return 2;
    } else {
      
      std::string nombre_archivo = argv[POS_FILE_IN]; //Parametro 1
      std::ifstream archivo(nombre_archivo.c_str());
      std::string linea;

      // Comienza lectura de fichero
      while (getline(archivo, linea)) {
        // Se define el alfabeto
        std::set<Symbol> symbol_set;
        int iterator = 1;
        int last_symbol_pos = iterator;
        // While para recorrer los primeros corchetes(alfabeto)
        while (SplitChain(linea,kDelimeter).at(iterator).at(0) != SET_CLOSER) {
          symbol_set.insert(SplitChain(linea,kDelimeter).at(iterator));
          iterator++;
          last_symbol_pos++;
        }
        Alphabet alfa(symbol_set);

        // While para recorrer los segundos corchetes(lenguaje)
        Language lang(alfa);
        iterator = last_symbol_pos + 2;
        while (SplitChain(linea,kDelimeter).at(iterator).at(0) != SET_CLOSER) {
          Chain chain;
          // Opcion para insertar cadena vacia sin que haya problema
          // El if es negando lo de dentro por eficiencia. El incremento de
          // iterator y añadir cadena era común a las 2 condiciones
          if (!((SplitChain(linea,kDelimeter).at(iterator).size() == 1) && 
              (SplitChain(linea,kDelimeter).at(iterator).at(0) == kEmptyChain))) {
            for (size_t i = 0; 
                i < SplitChain(linea,kDelimeter).at(iterator).size(); i++){
              std::string string_aux;
              string_aux.push_back(SplitChain(linea,kDelimeter).at(iterator).at(i));
              chain.AddSymbol(Symbol(string_aux));
            }
          }
          iterator++;
          lang.AddChain(chain);
        }
        std::endl(std::cout);
        Menu(lang, atoi(argv[argc - 1]));

      }
    }
  }

  return 0;
}