// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo cya-P01-Strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "simbolo.h"
#include "alfabeto.h"
#include "cadena.h"
#define kArgumentos 4
#define kOpcode 6
#define kDelimeter ' '

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

// Funcion que imprime por pantalla un vector de cadenas
void PrintChainVector(std::vector<Cadena> param_vector){
  for (size_t i = 0; i < param_vector.size(); i++) {
    std::cout << param_vector.at(i) << " ";
  }
  std::endl(std::cout);
}

// Funcion que indica la forma correcta de ejecutar y cada parametro a 
// introducir en caso de error.
void information(char* p_name){
    std::cout <<"La forma correcta de ejecutar el programa es:\n"
    << p_name << " ficheroentrada.txt ficherosalida.txt opcode\n\n"
    "ficheroentrada.txt\tFichero de texto que contiene los simbolos de un "
    "alfabeto y una cadena\n"
    "ficherosalida.txt\tFichero de texto que muestra para cada alfabeto y "
    "cadena la opcion de salida indicada en el opcode\n"
    "opcode\t\t\tOpcion a aplicar a la cadena dada\n";
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
      std::cout << "¡Opcode no válido!\n"
      "Las opciones son entre " << 1 << " y " << kOpcode << std::endl;
      return 2;
    } else {
      
      std::string nombre_archivo = "ejemplo.txt"; //Parametro 1
      std::ifstream archivo(nombre_archivo.c_str());
      std::string linea;

      // Comienza lectura de fichero
      while (getline(archivo, linea)) {   
        // Se define el alfabeto
        std::vector<Symbol> symbol_vector;
        if (SplitChain(linea,kDelimeter).size() == 1) {   //Cadena sin alfabeto
          
        } else {
          for (size_t i = 0; i < (SplitChain(linea,kDelimeter).size() - 1); i++) {
            symbol_vector.push_back(SplitChain(linea,kDelimeter).at(i));
          } 
        }
        Alfabeto alfa(symbol_vector);

        // Se crea y rellena la cadena
        Cadena chain;
        for (size_t i = 0; i < SplitChain(linea,kDelimeter).back().size(); i++){
          std::string string_aux;
          string_aux.push_back(SplitChain(linea,kDelimeter).back().at(i));
          chain.AddSymbol(Symbol(string_aux));
        }
        
        //Comprobar cadena pertenece al alfabeto

        // Menu. Ejecutar opcion según opcode
        switch (atoi(argv[argc - 1])){
          case 1:
            std::cout << chain.Size() << std::endl;
            break;
          case 2:
            chain.Inversa().Print();
            std::endl(std::cout);
            break;
          case 3:
            PrintChainVector(chain.Prefix());
            break;
          case 4:
            PrintChainVector(chain.Sufix());
            break;
          case 5:
            PrintChainVector(chain.Substring());
            break;
          case 6:
            std::cout << "Simbolos distintos: " << alfa.DistinctSimbol(chain) << "/" << alfa.Size() << std::endl; // Cambiar
            break;
          default:
            break;
        }
      }
    }
  }

  return 0;
}