// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor:  
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo lenguaje.cc: Fichero de implementación de la clase Language.
// Se define la clase Language con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "lenguaje.h"

#include <assert.h>

// https://stackoverflow.com/questions/3065438/switch-statement-with-returns-code-correctness


Language::Language(Alphabet param_alphabet) : alphabet_(param_alphabet) {}

Language::Language(Alphabet param_alphabet, std::set<Chain> param_chain) : 
                  alphabet_(param_alphabet), language_(param_chain) {}

Language::Language(const Language& param_language) : 
                  Language(param_language.alphabet_, param_language.language_) {} 

int Language::Size()const { return language_.size(); }

void Language::AddChain(Chain chain_param) { language_.insert(chain_param); }

void Language::AddSetChain(std::set<Chain> param_set) {
  for (std::set<Chain>::iterator it = param_set.begin();
    it != param_set.end(); ++it)
    AddChain(*it);
}

Language Language::Concatenation_L(const Language& param_language) {
  Alphabet aux_alphabet(alphabet_);
  aux_alphabet.AlphabetUnion(param_language.alphabet_);
  Language union_language(aux_alphabet);

  for (std::set<Chain>::iterator it1 = language_.begin();
      it1 != language_.end(); it1++) {
    for (std::set<Chain>::iterator it2 = param_language.language_.begin();
        it2 != param_language.language_.end(); it2++) {
        union_language.AddChain(Chain::Concatenate(*it1,*it2));
    }
  }
  return union_language;
}

Language Language::Diference(const Language& param_language) {
  Language diference(alphabet_);
  for (std::set<Chain>::iterator it1 = language_.begin();
      it1 != language_.end(); it1++) {
    if (!(param_language.inChain(*it1)))
      diference.AddChain(*it1);
  }
  return diference;
}

// Metodo para saber si una cadena dada esta en el lenguaje
bool Language::inChain(Chain param_chain) const {
  return (language_.count(param_chain) != 0);
}

Language Language::Intersection(const Language& param_language) {
  Language intersection(alphabet_);
  for (std::set<Chain>::iterator it1 = language_.begin();
      it1 != language_.end(); it1++) {
    if (param_language.inChain(*it1))
      intersection.AddChain(*it1);
  }
  return intersection;
}

Language Language::Power(int power) {
  // Aprovechando el constructor y el metodo recursivo, 
  // el método quedaría simplificado de la siguiente manera
  Language aux(alphabet_, PowerSetChain(power));
  return aux;
}

// Metodo recursivo para obtener la potencia de un set de cadenas
std::set<Chain> Language::PowerSetChain(int n) {
  assert(n >= 0);

  Chain empty_chain;
  std::set<Chain> power;
  power.insert(empty_chain);
  switch (n) {
    case 0:
      power.insert(empty_chain);
      return power;
      break;

    case 1:
      return language_;
      break;
    
    default: {
      power = language_;

      std::set<Chain> aux = PowerSetChain(n-1);

      for (std::set<Chain>::iterator it1 = language_.begin();
          it1 != language_.end(); it1++) {
        for (std::set<Chain>::iterator it2 = aux.begin();
            it2 != aux.end(); it2++) {
          power.insert(Chain::Concatenate(*it1,*it2));
        }
      }
      return power;
      break;
    }
  }
}

Language Language::Reverse() {
  Language reverse(alphabet_);
  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
    reverse.AddChain(it->Reverse());
  }
  return reverse;
}

bool Language::Subset(const Language& param_language) {

  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
      if (!(param_language.inChain(*it))) {
        return false;
      }
  }
  return true;
}

Language Language::Union(const Language& param_language) {
  Alphabet aux_alphabet(alphabet_);
  aux_alphabet.AlphabetUnion(param_language.alphabet_);
  Language union_language(aux_alphabet);

  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
    union_language.AddChain(*it);
  }
  for (std::set<Chain>::iterator it = param_language.language_.begin();
      it != param_language.language_.end(); ++it) {
    union_language.AddChain(*it);
  }
  return union_language;
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, const Language& param_language) {
  os << "{ ";

  for (std::set<Chain>::iterator it = param_language.language_.begin();
      it != param_language.language_.end(); ++it)
      std::cout << *it << " ";

  os << "}";
  return os;
}