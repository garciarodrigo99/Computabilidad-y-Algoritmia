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

std::set<Chain> Language::Concatenation(const Language& param_language) {
    std::set<Chain> aux;
    for (std::set<Chain>::iterator it1 = language_.begin();
        it1 != language_.end(); it1++) {
      for (std::set<Chain>::iterator it2 = param_language.language_.begin();
          it2 != param_language.language_.end(); it2++) {
        // Manejar concatenacion con cadena vacia
        // Chain empty_chain;
        // if (*it1 == empty_chain) {
        //   aux.insert(*it2);
        // } else if (*it2 == empty_chain) {
        //   aux.insert(*it1);
        // } else {
          aux.insert(Chain::Concatenate(*it1,*it2));
        // }
      }
    }
    //power.erase(empty_chain);
    return aux;
}

std::set<Chain> Language::Diference(const Language& param_language) {
  std::set<Chain> diference;

  for (std::set<Chain>::iterator it1 = language_.begin();
      it1 != language_.end(); it1++) {
    if (!(param_language.inChain(*it1)))
      diference.insert(*it1);
  }
  //power.erase(empty_chain);
  return diference;
}

std::set<Chain> Language::Intersection(const Language& param_language) {
  std::set<Chain> intersection;

  for (std::set<Chain>::iterator it1 = language_.begin();
      it1 != language_.end(); it1++) {
    if (param_language.inChain(*it1))
      intersection.insert(*it1);
  }
  //power.erase(empty_chain);
  return intersection;
}

// Metodo par
bool Language::inChain(Chain param_chain) const {
  return (language_.count(param_chain) != 0);
}

std::set<Chain> Language::Power(int n) {
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

      std::set<Chain> aux = Power(n-1);

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
//https://www.youtube.com/watch?v=G9gnSGKYIg4

std::set<Chain> Language::Reverse() {
  std::set<Chain> reverse;
  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
    reverse.insert(it->Reverse());
  }
  return reverse;
}

std::set<Chain> Language::Union(const Language& param_language) {
  std::set<Chain> aux; // "union" reservada para el lenguaje
  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
    aux.insert(*it);
  }
  for (std::set<Chain>::iterator it = param_language.language_.begin();
      it != param_language.language_.end(); ++it) {
    aux.insert(*it);
  }
  return aux;
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