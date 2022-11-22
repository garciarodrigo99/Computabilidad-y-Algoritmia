/**
 * @file cadena.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Fichero de implementación de la clase Chain.
 * Se define la clase Chain con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 * @link
 * https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
 * @link https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
 * @link https://en.cppreference.com/w/c/string/byte/strcmp
 */

#include "cadena.h"
#include "alfabeto.h"
#include <algorithm>
#include <assert.h>

#define DEFAULT_ALPHABET_SYMBOL "0"

/**
 * @brief Construct a new Chain:: Chain object
 * Cadena vacía
 *
 */
Chain::Chain() {}

/**
 * @brief Construct a new Chain:: Chain object
 * Constructor con simbolo, todos menos cadena vacia
 * @param paramChain Primer simbolo de la cadena
 */
Chain::Chain(Symbol paramSymbol) : Chain() { chain_.push_back(paramSymbol); }

/**
 * @brief Construct a new Chain:: Chain object
 *
 * @param symbolVector Vector de simbolos
 */
Chain::Chain(std::vector<Symbol> symbolVector) {
  for (auto symbol : symbolVector) {
    chain_.push_back(symbol);
  }
}

/**
 * @brief Construct a new Chain:: Chain object
 * Constructor de copia de la clase
 * @param paramChain Cadena
 */
Chain::Chain(const Chain &paramChain) : chain_(paramChain.chain_) {}

/**
 * @brief Construct a new Chain:: Chain object
 * Constructor que, a partir de una cadena(std) va a añadiendo cada caracter
 * de la cadena como si fuera un simbolo
 * 
 * @param paramChain 
 */
Chain::Chain(std::string paramChain) {
  if ((paramChain.size() == 1) && (paramChain.at(0) == kEmptyChain))
    Chain();
  else {
    for (auto pos : paramChain) {
      Symbol aux(pos);
      AddSymbol(aux);
    }
  }
}
 /**
  * @brief Asigna un simbolo como simbolo de la cadena en la 'index' posicion
  * 
  * @param index Posicion de la cadena
  * @param paramSymbol Simbolo a establecer
  */
void Chain::assign(int index, Symbol paramSymbol) {
  chain_.at(index) = paramSymbol;
}

/**
 * @brief Metodo para devolver el ultimo simbolo de la cadena
 * 
 * @return Symbol 
 */
Symbol Chain::back() const { return chain_.back(); }

/**
 * @brief Getter del index lemento de la cadena
 *
 * @param index Indice de la cadenq
 * @return Symbol
 */
Symbol Chain::Position(int index) const {
  assert((index >= 0) && (index < (int)chain_.size()));
  return chain_.at(index);
}

/**
 * @brief Devuelve la longitud de la cadena
 *
 * @return int - Longitud cadena
 */
int Chain::Size() const { return chain_.size(); }

/**
 * @brief "Sobrecarga" de la función begin para que se pueda recorrer el vector
 * de simbolos en los for de tipo 'auto'
 * 
 * @return std::vector<Symbol>::const_iterator Iterador a la primera posicion
 * de la cadena
 */
std::vector<Symbol>::const_iterator Chain::begin() const {
  return chain_.begin();
}

/**
 * @brief "Sobrecarga" de la función begin para que se pueda recorrer el vector
 * de simbolos en los for de tipo 'auto'
 * 
 * @return std::vector<Symbol>::const_iterator Iterador a la ultima posicion
 * de la cadena
 */
std::vector<Symbol>::const_iterator Chain::end() const { return chain_.end(); }

/**
 * @brief Añadir simbolo a la cadena
 *
 * @param paramSymbol Symbol a añadir
 */
void Chain::AddSymbol(Symbol paramSymbol) { chain_.push_back(paramSymbol); }

/**
 * @brief Operacion concatenar
 *
 * @param original Primera cadena
 * @param adder Cadena a concatenar
 * @return Chain - Cadena resultante
 */
Chain Chain::Concatenate(const Chain &original, const Chain &adder) {
  Chain concatenated;
  Chain empty_chain;
  // Primera cadena no es cadena vacia
  if (!(original == empty_chain)) {
    for (auto symbol : original) {
      concatenated.AddSymbol(symbol);
    }
  }
  // Segunda cadena no es cadena vacia
  if (!(adder == empty_chain)) {
    for (auto symbol : adder) {
      concatenated.AddSymbol(symbol);
    }
  }
  return concatenated;
}

/**
 * @brief Metodo para generar un alfabeto a partir de una cadena
 *
 * @return Alphabet - Alfabeto generado
 */
Alphabet Chain::GenerateAlphabet(void) {
  std::set<Symbol> symbol_set;
  for (auto symbol : chain_) {
    symbol_set.insert(symbol);
  }
  // Cadena vacia
  if (symbol_set.size() == 0) {
    symbol_set.insert(Symbol(DEFAULT_ALPHABET_SYMBOL));
  }
  Alphabet aux(symbol_set);
  return aux;
}

/**
 * @brief Metodo para saber si la cadena contiene un simbolo pasado por
 * parametro
 *
 * @param paramSymbol Simbolo a comprobar
 * @return true - El simbolo esta en la cadena.
 * @return False - El simbolo no esta en la cadena.
 */
bool Chain::inSymbol(Symbol paramSymbol) {
  for (auto symbol : chain_) {
    if (symbol == paramSymbol)
      return true;
  }
  return false;
}

/**
 * @brief Genera todos los prefijos de la cadena
 *
 * @return std::vector<Chain> - Vector de cadenas
 */
std::vector<Chain> Chain::Prefix() {
  std::vector<Chain> prefijos;
  Chain v;
  prefijos.push_back(v);
  for (size_t i = 0; i < chain_.size(); i++) {
    Chain cadena_aux;
    for (size_t j = 0; j <= i; j++) {
      cadena_aux.AddSymbol(chain_.at(j));
    }
    prefijos.push_back(cadena_aux);
  }
  return prefijos;
}

/**
 * @brief
 *
 * @return Chain - Reversa de la cadena
 */
Chain Chain::Reverse() {
  if (chain_.size() == 0)
    return *this;

  Chain inversa;
  for (int i = (chain_.size() - 1); i >= 0;
       --i) { // De esta forma no se sale de rango
    inversa.AddSymbol(chain_.at(i));
  }
  return inversa;
}

/**
 * @brief Metodo para objeto constante
 *
 * @return Chain - Reversa de la cadena
 */
Chain Chain::Reverse() const {
  if (chain_.size() == 0)
    return *this;

  Chain inversa;
  for (int i = (chain_.size() - 1); i >= 0;
       --i) { // De esta forma no se sale de rango
    inversa.AddSymbol(chain_.at(i));
  }
  return inversa;
}

/**
 * @brief Genera todas las subcadenas de la cadena
 *
 * @return std::vector<Chain> - Vector de cadenas
 */
std::vector<Chain> Chain::Substring() {
  std::vector<Chain> subcadena;
  Chain v;
  subcadena.push_back(v);
  for (int len = 1; len <= ((int)chain_.size()); len++) {
    for (int i = 0; i <= ((int)(chain_.size() - len)); i++) {
      Chain cadena_aux;
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        cadena_aux.AddSymbol(chain_.at(k));
      }
      if (!(inVector(subcadena, cadena_aux))) {
        subcadena.push_back(cadena_aux);
      }
    }
  }
  return subcadena;
}

/**
 * @brief Genera todos los sufijos de la cadena
 *
 * @return std::vector<Chain> - Vector de cadenas
 */
std::vector<Chain> Chain::Sufix() {
  std::vector<Chain> sufijos;
  Chain v;
  sufijos.push_back(v);
  for (int i = (chain_.size() - 1); i >= 0; i--) {
    Chain cadena_aux;
    for (int j = i; j < ((int)chain_.size()); j++) {
      cadena_aux.AddSymbol(chain_.at(j));
    }
    sufijos.push_back(cadena_aux);
  }
  return sufijos;
}

/**
 * @brief Sobrecarga del operador '<' necesario para la clase std::set
 * Compara si una cadena es mayor a otra
 *
 * @param paramChain Cadena candidata a entrar en std::set
 * @return True - La cadena no se encuentra en el conjunto.
 * @return False - La cadena se encuentra en el conjunto.
 * @see std::set
 */
bool Chain::operator<(const Chain paramChain) const {
  // Cadenas distinto tamaño
  if (((int)chain_.size() != paramChain.Size()))
    return ((int)chain_.size() < paramChain.Size());

  // Caso comparar cadena vacia (ya tienen mismo tamaño)
  if (chain_.size() == 0)
    return ((int)chain_.size() < paramChain.Size());
  // terminate called after throwing an instance of 'std::out_of_range'
  // what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is
  // 0)

  // Cadenas mismo tamaño y distinto de 0
  for (size_t i = 0; i < (chain_.size() - 1); i++) {
    if (!(chain_.at(i) == paramChain.Position(i))) {
      return (chain_.at(i) < paramChain.Position(i));
    }
  }
  return (chain_.back() < paramChain.Position(paramChain.Size() - 1));
}

/**
 * @brief Sobrecarga operador '<<' para escritura del objeto
 *
 * @param os
 * @param paramChain
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Chain &paramChain) {
  if (paramChain.Size() == 0)
    return os << kEmptyChain;
  for (auto symbol : paramChain.chain_)
    os << symbol;
  return os;
}

void Chain::operator=(const Chain paramChain) {
  chain_.clear();
  for (auto symbol : paramChain)
    chain_.push_back(symbol);
}

/**
 * @brief Sobrecarga operador '==' para comparación del objeto
 *
 * @param param_chain
 * @return true
 * @return false
 */
bool Chain::operator==(const Chain &paramChain) const {
  if (((int)chain_.size()) != paramChain.Size()) {
    return false;
  } else {
    for (size_t i = 0; i < chain_.size(); i++) {
      if (!(chain_.at(i) == paramChain.Position(i)))
        return false;
    }
  }
  return true;
}

/**
 * @brief Funcion externa para saber si en un vector de cadenas, la cadena por
 * parametro se encuentra dentro del vector
 *
 * @param param_vector Vector en el que buscar
 * @param paramChain Cadena a buscar
 * @return true Se encuentra la cadena.
 * @return false No se encuentra la cadena
 */
bool inVector(std::vector<Chain> param_vector, Chain paramChain) {
  for (auto chain: param_vector) {
    if (paramChain == chain)
      return true;
  }
  return false;
}