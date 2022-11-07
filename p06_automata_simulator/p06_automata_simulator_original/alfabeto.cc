/**
 * @file alfabeto.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Se define la clase Symbol con sus métodos y atributos
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Fichero de implementación de la clase Alphabet.
 * Se define la clase Alphabet con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * @link https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
 */

#include "alfabeto.h"

#include <assert.h>
#include <iostream>

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * Constructor a través de un simbolo 
 * @param paramSymbol Simbolo
 */
Alphabet::Alphabet(Symbol paramSymbol) { alphabet_.insert(paramSymbol); }

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * Constructor a través de un conjunto de simbolos
 * @param paramSymbolSet Conjunto de simbolos
 */
Alphabet::Alphabet(std::set<Symbol> paramSymbolSet) : alphabet_(paramSymbolSet) {
  assert(alphabet_.size() > 0);
}

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * Constructor de copia
 * @param paramAlphabet 
 */
Alphabet::Alphabet(const Alphabet &paramAlphabet) {
  for (std::set<Symbol>::iterator it = paramAlphabet.alphabet_.begin();
       it != paramAlphabet.alphabet_.end(); ++it)
    alphabet_.insert(*it);
}

/**
 * @brief 
 * 
 * @return int - Numero de elementos del alfabeto
 */
int Alphabet::Size() const { return alphabet_.size(); }

/**
 * @brief Añadir simbolo al alfabeto
 * 
 * @param paramSymbol Simbolo a añadir
 */
void Alphabet::AddSymbol(Symbol paramSymbol) {
  alphabet_.insert(paramSymbol);
}

/**
 * @brief Union de los simbolos del alfabeto parametro con los del alfabeto 
 * objeto
 * 
 * @param paramAlphabet Alfabeto
 */
void Alphabet::AlphabetUnion(const Alphabet &paramAlphabet) {
  for (std::set<Symbol>::iterator it = paramAlphabet.alphabet_.begin();
      it != paramAlphabet.alphabet_.end(); ++it) 
        alphabet_.insert(*it);
}

/**
 * @brief Metodo para saber cuantos simbolos distintos del alfabeto se 
 * encuentran en la cadena
 * 
 * @param paramChain 
 * @return int 
 */
int Alphabet::DistinctSimbol(Chain paramChain) {
  int count = 0;
  for (std::set<Symbol>::iterator it = alphabet_.begin();
    it != alphabet_.end(); ++it) {
    if (paramChain.inSymbol(*it))  count++;
  }
  return count;
}
 
/**
 * @brief Metodo que comprueba si un simbolo pertenece al alfabeto
 * 
 * @param paramSymbol Simbolo a comprobar
 * @return true - El simbolo pertenece al alfabeto
 * @return false - El simbolo no pertenece al alfabeto
 */
bool Alphabet::inSymbol(Symbol paramSymbol) {
  if (alphabet_.count(paramSymbol) != 0) return true;
  return false;
}

/**
 * @brief Metodo que comprueba que todos los simbolos de una cadena pertenecen 
 * al objeto alfabeto
 * 
 * @param paramChain Cadena a analizar
 * @return true - Todos los simbolos de la cadena pertenecen al alfabeto
 * @return false - Todos los simbolos de la cadena no pertenecen al alfabeto
 */
bool Alphabet::okChain(Chain paramChain) {
  for (int i = 0; i < paramChain.Size(); i++) {
    if (!(inSymbol(paramChain.Position(i)))) return false;
  }
  return true;
}

/**
 * @brief Sobrecarga operador '<' para poder trabajar clase std::set
 * 
 * @param paramAlphabet Alfabeto candidato a entrar en std::set
 * @return True - El alfabeto no se encuentra en el conjunto 
 * @return false - El alfabeto se encuentra en el conjunto 
 * @see std::set
 */
bool Alphabet::operator<(const Alphabet paramAlphabet) const {
  return ((int)alphabet_.size() < paramAlphabet.Size());
}

/**
 * @brief Sobrecarga operador '<<' para escritura del objeto
 * 
 * @param os 
 * @param paramAlphabet 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, Alphabet &paramAlphabet) {
  os << "{ ";

  for (std::set<Symbol>::iterator it = paramAlphabet.alphabet_.begin();
       it != paramAlphabet.alphabet_.end(); ++it)
    std::cout << *it << " ";

  os << "}";
  return os;
}