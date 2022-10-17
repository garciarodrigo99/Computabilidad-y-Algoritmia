// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo cadena.cc: Fichero de implementación de la clase Chain.
// Se define la clase Chain con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "cadena.h"
#include "alfabeto.h"
#include <algorithm>
#include <assert.h>

#define DEFAULT_ALPHABET_SYMBOL "0"

// https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
// https://www.tutorialspoint.com/strcmp-in-c-cplusplus#
// https://en.cppreference.com/w/c/string/byte/strcmp

Chain::Chain() {}

// Constructor con simbolo, todos menos cadena vacia
Chain::Chain(Symbol param) : Chain() { chain_.push_back(param); }

Chain::Chain(std::vector<Symbol> symbol_vector) {
  for (size_t i = 0; i < symbol_vector.size(); i++) {
    chain_.push_back(Symbol(symbol_vector.at(i)));
  }
}

// Constructor de copia de la clase
Chain::Chain(const Chain &param) : chain_(param.chain_) {} // Comprobar

Symbol Chain::Position(int index) const { return chain_.at(index); }

int Chain::Size() const { return chain_.size(); }

void Chain::AddSymbol(Symbol param) { chain_.push_back(param); }

Chain Chain::Concatenate(const Chain &original, const Chain &adder) {
  Chain concatenated;
  Chain empty_chain;
  if (!(original == empty_chain)) {
    for (int i = 0; i < original.Size(); i++) {
      concatenated.AddSymbol(original.Position(i));
    }
  }
  if (!(adder == empty_chain)) {
    for (int i = 0; i < adder.Size(); i++) {
      concatenated.AddSymbol(adder.Position(i));
    }
  }
  return concatenated;
}

Alphabet Chain::GenerateAlphabet(void) {
  std::set<Symbol> symbol_set;
  for (size_t i = 0; i < chain_.size(); i++) {
    symbol_set.insert(chain_.at(i));
  }
  // Cadena vacia
  if (symbol_set.size() == 0) {
    symbol_set.insert(Symbol(DEFAULT_ALPHABET_SYMBOL));
  }
  Alphabet aux(symbol_set);
  return aux;
}

bool Chain::inSymbol(Symbol simbolo_param) {
  for (size_t i = 0; i < chain_.size(); i++) {
    if (chain_.at(i).isEqual(simbolo_param))
      return true;
  }
  return false;
}

bool Chain::isEqual(const Chain &cadena_param) const {
  if (((int)chain_.size()) != cadena_param.Size()) {
    return false;
  } else {
    for (size_t i = 0; i < chain_.size(); i++) {
      if (!(chain_.at(i).isEqual(cadena_param.Position(i)))) {
        return false;
      }
    }
  }
  return true;
}

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

void Chain::Print() {
  if (chain_.size() == 0) {
    std::cout << kEmptyChain;
  } else {
    for (size_t i = 0; i < chain_.size(); i++) {
      std::cout << chain_.at(i);
    }
  }
}

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

// Sobrecarga del operador< necesario para la clase std::set
// Compara si una cadena es mayor a otra
bool Chain::operator<(const Chain param_cadena) const {
  // Cadenas distinto tamaño
  if (((int)chain_.size() != param_cadena.Size()))
    return ((int)chain_.size() < param_cadena.Size());

  // Caso comparar cadena vacia (ya tienen mismo tamaño)
  if (chain_.size() == 0)
    return ((int)chain_.size() < param_cadena.Size());
  // terminate called after throwing an instance of 'std::out_of_range'
  // what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is
  // 0)

  // Cadenas mismo tamaño y distinto de 0
  for (size_t i = 0; i < (chain_.size() - 1); i++) {
    if (!(chain_.at(i).isEqual(param_cadena.Position(i)))) {
      return (chain_.at(i) < param_cadena.Position(i));
    }
  }
  return (chain_.back() < param_cadena.Position(param_cadena.Size() - 1));
}

// Sobrecarga operador<< para escritura del objeto
std::ostream &operator<<(std::ostream &os, const Chain &param_cadena) {
  if (param_cadena.Size() == 0) {
    return os << kEmptyChain;
  } else {
    for (int i = 0; i < param_cadena.Size(); i++) {
      os << param_cadena.chain_.at(i);
    }
    return os;
  }
}

bool Chain::operator==(const Chain &param_chain) const {
  return isEqual(param_chain);
}

bool inVector(std::vector<Chain> param_vector, Chain param_cadena) {
  for (size_t i = 0; i < param_vector.size(); i++) {
    if (param_cadena.isEqual(param_vector.at(i))) {
      return true;
    }
  }
  return false;
}