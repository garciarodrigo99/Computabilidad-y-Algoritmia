// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo calculator.cc: Fichero de implementación de la clase Calculator.
// Se define la clase Calculator con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// https://stackoverflow.com/questions/3065438/switch-statement-with-returns-code-correctness
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "calculator.h"

#include <algorithm>
#include <assert.h>

// https://stackoverflow.com/questions/16388510/evaluate-a-string-with-a-switch-in-c

// Constructor que recibe un conjunto de lenguajes
Calculator::Calculator(std::set<Language> language_set)
    : language_set_(language_set) {}

// Destructor
Calculator::~Calculator() {}

// Metodo que dada una sentencia (conjunto de operaciones) y delimitador
// (para separar la secuencia), devuelve el lenguaje resultante de todas las
// operaciones previas
Language Calculator::GetResult(std::string operations, char delimiter) {
  std::vector<std::string> operations_vector(SplitChain(operations, delimiter));
  int power = 1;
  for (size_t i = 0; i < operations_vector.size(); i++) {
    // Lenguaje declarado
    if (isLanguage(operations_vector.at(i))) {
      stack_.push(GetLanguage(operations_vector.at(i)));
    } else if (std::all_of(operations_vector.at(i).begin(),
                           operations_vector.at(i).end(), ::isdigit)) {
      // Exponente opercion potencia
      power = std::stoi(operations_vector.at(i));
    } else {
      // Signo operación o fallo
      Operations(operations_vector.at(i).at(0), power);
    }
  }
  assert(stack_.size() == 1);

  Language lang_aux(stack_.top(), "L_result");
  return lang_aux;
}

// Metodo que devuelve un lenguaje del conjunto de lenguajes (modularidad)
Language Calculator::GetLanguage(std::string param_lang_id) {
  assert(isLanguage(param_lang_id));
  std::set<Language>::iterator iter = language_set_.begin();
  std::set<Language>::iterator ref;
  bool found = false;
  // Como sabemos que el lenguaje se encuentra en el conjunto
  // cuando lo encontremos salimos del bucle
  while (!(found)) {
    if (param_lang_id == iter->GetNameID()) {
      ref = iter;
      found = true;
    }
    ++iter;
  }
  return *ref;
}

// Metodo para saber si existe un lenguaje con un identificador de lenguaje
// recibido por parametro (modularidad)
bool Calculator::isLanguage(std::string param_name) {
  for (std::set<Language>::iterator it = language_set_.begin();
       it != language_set_.end(); ++it) {
    if (param_name == it->GetNameID()) {
      return true;
    }
  }
  return false;
}

// Metodo que ejecuta las operaciones soportadas por la calculadora, que recibe
// el supuesto operador, y un entero, para usar en el caso de la potencia, y
// si no se indica el parametro, se pasará uno por defecto (modularidad)
void Calculator::Operations(char _operator, int power = 1) {
  switch (_operator) {
  case '+': {
    Language l2(stack_.top());
    stack_.pop();
    Language l1(stack_.top());
    stack_.pop();
    stack_.push(l1.Concatenation(l2));
    break;
  }
  case '|': {
    Language l2(stack_.top());
    stack_.pop();
    Language l1(stack_.top());
    stack_.pop();
    stack_.push(l1.Union(l2));
    break;
  }
  case '^': {
    Language l2(stack_.top());
    stack_.pop();
    Language l1(stack_.top());
    stack_.pop();
    Language lan_aux(l1.Intersection(l2));
    stack_.push(l1.Intersection(l2));
    break;
  }
  case '-': {
    Language l2(stack_.top());
    stack_.pop();
    Language l1(stack_.top());
    stack_.pop();
    stack_.push(l1.Diference(l2));
    break;
  }
  case '!': {
    Language l1(stack_.top());
    stack_.pop();
    stack_.push(l1.Reverse());
    break;
  }
  case '*': {
    Language l1(stack_.top());
    stack_.pop();
    stack_.push(l1.Power(power));
    break;
  }
  default:
    bool entrada_correcta = false;
    assert(entrada_correcta);
    break;
  }
}

// Funcion externa para separar cada linea en cadenas según espacios
std::vector<std::string> SplitChain(std::string str, char pattern) {

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