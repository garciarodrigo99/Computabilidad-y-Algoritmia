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
#define kOpcode 5

void ImprimirVectorCadenas(std::vector<Cadena> param_vector){
  for (size_t i = 0; i < param_vector.back().Prefijo().size(); i++) {
    std::cout << param_vector.back().Prefijo().at(i) << " ";
  }
  std::endl(std::cout);
}

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
  if (argc != kArgumentos) {
    std::cout << "¡Error de formato!\n\n";
    information(argv[0]);
    return 1;
  } else {
    if ((atoi(argv[argc - 1]) < 1) || (atoi(argv[argc - 1]) > kOpcode)) {
      std::cout << "¡Opcode no válido!\n"
      "Las opciones son entre " << 1 << " y " << kOpcode << std::endl;
      return 2;
    } else {
      
      std::string nombre_archivo = "ejemplo.txt"; //Parametro 1
      std::ifstream archivo(nombre_archivo.c_str());
      std::string linea;
      //char delimitador = ' ';
      while (getline(archivo, linea)) {
        std::vector<Cadena> vector_cadena;
        int iterator1 = 0;
        while (iterator1<linea.size()){
          int iterator2 = iterator1;
          std::vector<Simbolo> vector_simbolo;
          while ((iterator2<linea.size()) && (linea.at(iterator2) != ' ')){
            std::string string_aux;
            string_aux = linea.at(iterator2);
            Simbolo simbolo_aux(string_aux);
            vector_simbolo.push_back(simbolo_aux);
            iterator2++;
          }
          Cadena cadena_aux;
          for (size_t i = 0; i < vector_simbolo.size(); i++){
            cadena_aux.AddSimbolo(vector_simbolo.at(i));
          }
          vector_cadena.push_back(cadena_aux);
          iterator1 = (iterator2+1);
          //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        Simbolo simb(vector_cadena.back().GetCadena().back());
        Alfabeto alfa(simb);
        for (int i = 1; i < (vector_cadena.size() - 1); i++) {
          Simbolo simb_aux(vector_cadena.at(i).GetCadena().back());
          alfa.AddSimbolo(simb_aux);
        }
        
        //alfa.okCadena(vector_cadena.back());
        
        // Menu
        switch (atoi(argv[argc - 1])){
          case 1:
            std::cout << vector_cadena.back().Longitud() << std::endl;
            break;
          case 2:
            vector_cadena.back().Inversa().Print();
            std::endl(std::cout);
            break;
          case 3:
            ImprimirVectorCadenas(vector_cadena.back().Prefijo());
            break;
          case 4:
            ImprimirVectorCadenas(vector_cadena.back().Sufijo());
            break;
          case 5:
            ImprimirVectorCadenas(vector_cadena.back().Subcadena());
            break;
          case 6:
            std::cout << "Simbolos distintos: " << alfa.DistinctSimbol(vector_cadena.back()) << "/" << alfa.GetAlfabeto().size() << std::endl;
            break;
          default:
            break;
        }
      }
    }
  }

  return 0;
}