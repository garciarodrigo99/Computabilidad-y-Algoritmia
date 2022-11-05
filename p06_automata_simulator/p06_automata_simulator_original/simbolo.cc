// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo simbolo.h: Fichero de implementación de la clase Symbol.
// Se define la clase Symbol con sus métodos y atributos
// Referencias:
// Enlaces de interés
// https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
// https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "simbolo.h"

#include <assert.h>

// Constructor a través de caracter
Symbol::Symbol(const std::string param) : symbol_(param) {
  // Comprobar no es simbolo reservado cadena vacia
  assert(CheckSimbols(*this));
}

// Destructor
Symbol::~Symbol() {}

// Devuelve el caracter que ocupa index posicion
const char Symbol::position(int index) {
  assert((index >= 0) && (index < (int)symbol_.size()));
  return symbol_[index];
}

// Devuelve el numero de caracteres del simbolo
int Symbol::Size() const { return symbol_.size(); }

// Comprueba que no contiene el caracter reservado para la cadena vacía y
// devuelve true si la cadena es correcta y false en caso contrario
bool Symbol::CheckSimbols(Symbol simbolo_param) {
  for (int i = 0; i < simbolo_param.Size(); i++) {
    if (simbolo_param.position(i) == kEmptyChain) {
      return false;
    }
  }
  return true;
}

// Comprueba, comparando con el simbolo por parametro, si un simbolo es igual
// a otro
bool Symbol::isEqual(Symbol simbolo_param) {
  if ((symbol_.compare(simbolo_param.symbol_)) == 0) { // Cambiar
    return true;
  } else {
    return false;
  }
}

// Método anterior para objetos constantes
bool Symbol::isEqual(Symbol simbolo_param) const {
  if ((symbol_.compare(simbolo_param.symbol_)) == 0) // Cambiar
    return true;
  else
    return false;
}

bool Symbol::operator==(const Symbol paramSymbol) const {
  return (isEqual(paramSymbol));
}

// Sobrecarga operador '<' para trabajar con la clase std::set
bool Symbol::operator<(const Symbol param_symbol) const {
  return (symbol_ < param_symbol.symbol_);
}

// Sobrecarga operador '<<' para escritura del objeto
std::ostream &operator<<(std::ostream &os, const Symbol &param_simbolo) {
  os << param_simbolo.symbol_;
  return os;
}