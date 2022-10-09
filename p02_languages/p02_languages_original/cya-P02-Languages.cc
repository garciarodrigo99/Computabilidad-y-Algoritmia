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

#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "lenguaje.h"
#define kArgumentos 4
#define kOpcode 6
#define kDelimeter ' '
#define POS_FILE_IN 1
#define POS_FILE_OUT 2
#define POS_OPCODE 3
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

// Funcion que imprime por pantalla un vector de cadenas
void PrintChainSet(std::set<Chain> param_set){
  std::cout << "{ ";

  for (std::set<Chain>::iterator it = param_set.begin();
      it != param_set.end(); ++it)
      std::cout << *it << " ";

  std::cout << "}\n";
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

  // Symbol s1("a");
  // Symbol s2("ab");
  // Symbol s3("s");
  // Symbol s4("l");
  // Symbol s5("e");
  // Symbol s6("v");

  // Chain c1(s3);
  // c1.AddSymbol(s1);
  // c1.AddSymbol(s4);
  // c1.AddSymbol(s1);
  
  // Chain c2(s5);
  // c2.AddSymbol(s6);
  // c2.AddSymbol(s1);

  // Alphabet a1(s1);
  // Alphabet a2(s1);
  // a2.AddSymbol(s2);

  // Language l1(a2);
  // l1.AddChain(c1);
  // l1.AddChain(c2);

  // std::cout << l1 << std::endl;
  // PrintChainSet(l1.Reverse());

  // Symbol s7("1");
  // Symbol s8("0");
  // Alphabet a3(s7);
  // a3.AddSymbol(s8);
  
  // Language l2(a3);
  // l2.AddChain(Chain(s7));
  // l2.AddChain(Chain(s8));
  // // Chain empty_chain;
  // // l2.AddChain(empty_chain);
  // std::cout << "\nAlfabeto: " << a3 << "\nPotencia: ";
  // PrintChainSet(l2.Power(0));
  // PrintChainSet(l2.Power(1));
  // PrintChainSet(l2.Power(2));

  // Language l3(a3);
  // Language l4(a3);

  // Chain ojos;
  // ojos.AddSymbol(Symbol("o"));
  // ojos.AddSymbol(Symbol("j"));
  // ojos.AddSymbol(Symbol("o"));
  // ojos.AddSymbol(Symbol("s"));
  // l3.AddChain(ojos);

  // Chain azules;
  // azules.AddSymbol(Symbol("a"));
  // azules.AddSymbol(Symbol("z"));
  // azules.AddSymbol(Symbol("u"));
  // azules.AddSymbol(Symbol("l"));
  // azules.AddSymbol(Symbol("e"));
  // azules.AddSymbol(Symbol("s"));
  // l4.AddChain(azules);

  // Chain negros;
  // negros.AddSymbol(Symbol("n"));
  // negros.AddSymbol(Symbol("e"));
  // negros.AddSymbol(Symbol("g"));
  // negros.AddSymbol(Symbol("r"));
  // negros.AddSymbol(Symbol("o"));
  // negros.AddSymbol(Symbol("s"));
  // l4.AddChain(negros);

  // std::cout << "\nL1:" << l3 << " L2:" << l4 << "\nCocatenacion: ";
  // PrintChainSet(l3.Concatenation(l4));

  // Language l5(a3);
  // Language l6(a3);

  // Chain empty_chain;

  // Symbol one("1");
  // Symbol zero("0");

  // Chain l5_1(zero);
  // Chain l5_2(one);
  // Chain l5_3(one);
  // l5_3.AddSymbol(zero);
  // Chain l5_4(one);
  // l5_4.AddSymbol(one);

  // l5.AddChain(l5_1);
  // l5.AddChain(l5_2);
  // l5.AddChain(l5_3);
  // l5.AddChain(l5_4);
  // //l5.AddChain(empty_chain);

  // Chain l6_1(one);
  // Chain l6_2(zero);
  // l6_2.AddSymbol(one);
  // l6_2.AddSymbol(one);
  // l6_2.AddSymbol(zero);
  // Chain l6_3(one);
  // l6_3.AddSymbol(one);
  // l6_3.AddSymbol(zero);
  // l6_3.AddSymbol(one);
  // l6_3.AddSymbol(zero);

  // //l6.AddChain(empty_chain);
  // l6.AddChain(l6_1);
  // l6.AddChain(l6_2);
  // l6.AddChain(l6_3);

  // std::cout << "\nL1:" << l5 << " L2:" << l6 << "\nUnion: ";
  // PrintChainSet(l5.Union(l6));

  // std::cout << "\nL1:" << l5 << " L2:" << l6 << "\nInterseccion: ";
  // PrintChainSet(l5.Intersection(l6));

  // std::cout << "\nL1:" << l5 << " L2:" << l6 << "\nDiferencia: ";
  // PrintChainSet(l5.Diference(l6));

  // std::string str = "{ a b c } { a abc cab bbcc }";
  // for (size_t i = 0; i < SplitChain(str,kDelimeter).size(); i++){
  //   std::cout << SplitChain(str,kDelimeter).at(i) << std::endl;
  // }
  
  // return 0;
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
      
      std::string nombre_archivo = argv[POS_FILE_IN]; //Parametro 1
      std::ifstream archivo(nombre_archivo.c_str());
      std::string linea;

      // Comienza lectura de fichero
      while (getline(archivo, linea)) {   
        // Se define el alfabeto
        std::set<Symbol> symbol_set;
        int iterator = 1;
        while (SplitChain(linea,kDelimeter).at(iterator).at(0) != SET_CLOSER) {
          symbol_set.insert(SplitChain(linea,kDelimeter).at(iterator));
        }
        for (size_t i = 1; i < (SplitChain(linea,kDelimeter).size() - 1); i++) {
          symbol_set.insert(SplitChain(linea,kDelimeter).at(i));
        }
        Alphabet alfa(symbol_set);

        // Se crea y rellena la cadena
        Chain chain;
        for (size_t i = 0; i < SplitChain(linea,kDelimeter).back().size(); i++){
          std::string string_aux;
          string_aux.push_back(SplitChain(linea,kDelimeter).back().at(i));
          chain.AddSymbol(Symbol(string_aux));
        }
        
        //Comprobar cadena pertenece al alfabeto

        // Menu. Ejecutar opcion según opcode
        switch (atoi(argv[argc - 1])) {
          case 1:
            std::cout << chain.Size() << std::endl;
            break;
          case 2:
            chain.Reverse().Print();
            std::endl(std::cout);
            break;
          case 3:
            //PrintChainVector(chain.Prefix());
            break;
          case 4:
            //PrintChainVector(chain.Sufix());
            break;
          case 5:
            //PrintChainSet(language.Reverse());
            break;
          case 6: {
            int pow = 2;
            std::cout << "Introduzca el valor de la potencia: "; 
            std::cin >> pow;
            // PrintChainSet(language.Power(pow));
            break;
            }
          default:
            break;
        }
      }
    }
  }

  return 0;
}