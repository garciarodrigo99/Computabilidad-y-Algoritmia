/**
 * @file simbolo.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Symbol.
 * @version 2.0
 * @date 2022-11-08
 *
 * @copyright Copyright (c) 2022
 * @link
 * https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
 * @link
 * https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
 */

#include "simbolo.h"

#include <assert.h>

/**
 * @brief Construct a new Symbol:: Symbol object
 * @param paramString
 */
Symbol::Symbol(const std::string paramString) {
  for (auto pos : paramString) {
    symbol_.push_back(pos);
    assert(CheckSimbols(*this));
  }
  // Comprobar no es simbolo reservado cadena vacia
}

Symbol::Symbol(char paramString) {
  symbol_.push_back(paramString);
  // Se suprime assert para trabajar en con la clase gramatica
}

/**
 * @brief Destroy the Symbol:: Symbol object
 */
Symbol::~Symbol() {}

/**
 * @brief Devuelve el caracter que ocupa index posicion
 * @param index Posicion a la que se quiere acceder
 * @return Caracter
 */
const char Symbol::position(int index) {
  assert((index >= 0) && (index < (int)symbol_.size()));
  return symbol_[index];
}

/**
 * @brief Devuelve el numero de caracteres del simbolo
 * @return Numero de caracteres ASCII del simbolo
 */
int Symbol::Size() const { return symbol_.size(); }

/**
 * @brief Comprueba que no contiene el caracter reservado para la cadena vacía
 *
 * @param paramSymbol Simbolo
 * @return true si la cadena es correcta y false en caso contrario
 */
bool Symbol::CheckSimbols(Symbol paramSymbol) {
  for (int i = 0; i < paramSymbol.Size(); i++) {
    if (paramSymbol.position(i) == kEmptyChain) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Comprueba, comparando con el simbolo por parametro, si un simbolo
 * es igual a otro
 * @param paramSymbol Simbolo a comparar
 * @return True si los simbolos son iguales, false en caso contrario.
 */
bool Symbol::isEqual(Symbol paramSymbol) {
  if ((symbol_.compare(paramSymbol.symbol_)) == 0) { // Cambiar
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Comprueba, comparando con el simbolo por parametro, si un simbolo es
 * igual a otro. Método para objetos constantes
 * @param paramSymbol Simbolo a comparar
 * @return True si los simbolos son iguales, false en caso contrario.
 */
bool Symbol::isEqual(Symbol paramSymbol) const {
  if ((symbol_.compare(paramSymbol.symbol_)) == 0) // Cambiar
    return true;
  else
    return false;
}

bool Symbol::isEqual(std::string paramString) {
  if (symbol_.size() != paramString.size())
    return false;
  for (size_t i =0 ; i < symbol_.size();i++) {
    if (symbol_.at(i) != paramString.at(i))
      return false;
  }
  return true;
}

/**
 * @brief
 * @param paramSymbol
 * @return
 */
bool Symbol::operator==(const Symbol paramSymbol) const {
  return (isEqual(paramSymbol));
}

/**
 * @brief Sobrecarga operador '<' para trabajar con la clase std::set
 * @param param_symbol Simbolo candidato a entrar en el conjunto
 * @return True si el elemento no esta en el conjunto. False en caso contrario.
 */
bool Symbol::operator<(const Symbol param_symbol) const {
  return (symbol_ < param_symbol.symbol_);
}

/**
 * @brief Sobrecarga operador '<<' para escritura del objeto
 * @param os std::ostream
 * @param param_symbol Simbolo a escribir
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Symbol &param_symbol) {
  os << param_symbol.symbol_;
  return os;
}