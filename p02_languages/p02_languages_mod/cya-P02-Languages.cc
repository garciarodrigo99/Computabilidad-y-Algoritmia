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

#define kArgumentos 5
#define kOpcode 7
#define kDelimeter ' '
#define POS_FILE_IN 1
#define POS_FILE_IN_2 2
#define POS_FILE_OUT 3
#define POS_OPCODE 4
#define SET_CLOSER '}'

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

std::pair<Alphabet, int> ReadAlphabet(std::string string){
  std::set<Symbol> symbol_set;
  int iterator = 1;
  // While para recorrer los primeros corchetes(alfabeto)
  while (SplitChain(string,kDelimeter).at(iterator).at(0) != SET_CLOSER) {
    symbol_set.insert(SplitChain(string,kDelimeter).at(iterator));
    iterator++;
  }
  Alphabet alfa(symbol_set);
  return std::pair<Alphabet, int>(alfa,iterator);
}

Language ReadLanguage(std::string string, int start_position, Language& lang) {
  while (SplitChain(string,kDelimeter).at(start_position).at(0) != SET_CLOSER) {
    Chain chain;
    // Opcion para insertar cadena vacia sin que haya problema
    // El if es negando lo de dentro por eficiencia. El incremento de
    // iterator y añadir cadena era común a las 2 condiciones
    if (!((SplitChain(string,kDelimeter).at(start_position).size() == 1) && 
        (SplitChain(string,kDelimeter).at(start_position).at(0) == kEmptyChain))) {
      for (size_t i = 0; 
          i < SplitChain(string,kDelimeter).at(start_position).size(); i++){
        std::string string_aux;
        string_aux.push_back(SplitChain(string,kDelimeter).at(start_position).at(i));
        chain.AddSymbol(Symbol(string_aux));
      }
    }
    start_position++;
    lang.AddChain(chain);
  }
  return lang;
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
void Menu(int opcode, Language& param_language, Language& param_language2) {
  switch (opcode) {
    case 1:
      std::cout << param_language.Concatenation_L(param_language2) << std::endl;
      break;
    case 2:
      std::cout << param_language.Union(param_language2) << std::endl;
      break;
    case 3:
      std::cout << param_language.Intersection(param_language2) << std::endl;
      break;
    case 4:
      std::cout << param_language.Diference(param_language2) << std::endl;
      break;
    case 5:
      std::cout << param_language.Reverse() << std::endl;
      break;
    case 6: {
      int pow = 2;
      std::cout << "Introduzca el valor de la potencia: "; 
      std::cin >> pow;
      std::cout << param_language.Power(pow) << std::endl;
      break;
      }
    case 7:
      if (param_language.Subset(param_language2)) {
        std::cout << param_language << " es sublenguaje de ";
        std::cout << param_language2 << std::endl;
      }
      else {
        std::cout << param_language << " NO es sublenguaje de ";
        std::cout << param_language2 << std::endl;
      }
      std::endl(std::cout);
      break;
    default:
      break;
  }
}

// Funcion que indica la forma correcta de ejecutar y cada parametro a 
// introducir en caso de error.
void information(char* p_name){
    std::cout <<"La forma correcta de ejecutar el programa es:\n"
    << p_name << " ficheroentrada.txt ficheroentrada2.txt ficherosalida.txt"
    " opcode\n\n"
    "ficheroentrada.txt\tFichero de texto que contiene los simbolos de un "
    "alfabeto y un lenguaje\n"
    "ficheroentrada2.txt\tFichero de texto que contiene los simbolos de un "
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
  }

  // Comprobar opcode esta entre los valores aceptados
  if ((atoi(argv[argc - 1]) < 1) || (atoi(argv[argc - 1]) > kOpcode)) {
    std::cout << "¡Opcode no válido!\n\n"
    "Introducir valores entre " << 1 << " y " << kOpcode << std::endl;
    return 2;
  }

  std::string nombre_archivo = argv[POS_FILE_IN]; //Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;
  std::vector<Language> vector_language_file1;
  bool operacion_unaria = ((atoi(argv[argc - 1]) == 5) || 
                          (atoi(argv[argc - 1]) == 6));
  // Comienza lectura de fichero 1, se almacenará en un vector de Language
  // para más tarde trabajar con el
  while (getline(archivo, linea)) {
    // Lo hago de esta manera para evitar llamar dos veces a la misma funcion
    // en las igualaciones
    std::pair<Alphabet, int> pair_value(ReadAlphabet(linea));
    Language aux(pair_value.first);
    int iterator = pair_value.second + 2;
    Language lang(ReadLanguage(linea,iterator,aux));
    vector_language_file1.push_back(lang);
  }

  // Si es operacion unaria, se evita lectura fichero2
  if (operacion_unaria) {
    for (size_t i = 0; i < vector_language_file1.size(); i++) {
      Menu(atoi(argv[argc - 1]), vector_language_file1.at(i), 
          vector_language_file1.at(i));
    }
    return 0;
  }

  std::string nombre_archivo2 = argv[POS_FILE_IN_2]; //Parametro 2
  std::ifstream archivo2(nombre_archivo2.c_str());
  std::string linea2;
  std::vector<Language> vector_language_file2;

  while (getline(archivo2, linea2)) {
    std::pair<Alphabet, int> pair_value(ReadAlphabet(linea2));
    Language aux(pair_value.first);
    int iterator = pair_value.second + 2;
    Language lang(ReadLanguage(linea2,iterator,aux));
    vector_language_file2.push_back(lang);
  }

  if (vector_language_file1.size() > vector_language_file2.size()) {
    std::cout << "El numero de lenguajes de " << nombre_archivo;
    std::cout << " es mayor que el numero de lenguajes de " << nombre_archivo;
    std::endl(std::cout);
    return 3;
  }

  for (size_t i = 0; i < vector_language_file1.size(); i++) {
    Menu(atoi(argv[argc - 1]), vector_language_file1.at(i), 
        vector_language_file2.at(i));
  }

  return 0;
}