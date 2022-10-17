// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo calculator.h: Cabecera de la clase Calculator.
// Se define la clase Calculator con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "lenguaje.h"

#include <stack>

class Calculator {

public:
  // Constructores y destructor
  Calculator(std::set<Language>);
  ~Calculator();

  // Getter
  Language GetResult(std::string, char);

  // Metodos privados
private:
  Language GetLanguage(std::string);
  bool isLanguage(std::string);
  void Operations(char, int);

private:
  std::set<Language> language_set_;
  std::stack<Language> stack_;
};

// Funcion para separar cada linea en cadenas según espacios
std::vector<std::string> SplitChain(std::string str, char pattern);