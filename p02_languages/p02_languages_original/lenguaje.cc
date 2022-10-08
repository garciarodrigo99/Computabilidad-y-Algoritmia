#include "lenguaje.h"

#include <assert.h>

// https://stackoverflow.com/questions/3065438/switch-statement-with-returns-code-correctness


Language::Language(Alphabet param_alphabet) : alphabet_(param_alphabet) {}

Language::Language(Alphabet param_alphabet, std::set<Chain> param_chain) : 
                  alphabet_(param_alphabet), language_(param_chain) {}

int Language::Size()const { return language_.size(); }

void Language::AddChain(Chain chain_param) { language_.insert(chain_param); }

bool Language::inChain(Chain param_chain) {
  return (language_.count(param_chain) == 0);
}

std::set<Chain> Language::Power(int n) {
  assert(n >= 0);
  std::set<Chain> power;
  Chain empty_chain;
  if (n == 0) {
    power.insert(empty_chain);
    return power;
  } else {
    if (n == 1) {
      return language_;
    } else {
      power = language_;
      
      std::set<Chain> aux = Power(n-1);

      for (std::set<Chain>::iterator it1 = language_.begin();
          it1 != language_.end(); it1++) {
        for (std::set<Chain>::iterator it2 = aux.begin();
            it2 != aux.end(); it2++) {
          power.insert(Chain::Concatenate(*it1,*it2));
        }
      }
    }
    power.erase(empty_chain);
    return power;
  }
}
//https://www.youtube.com/watch?v=G9gnSGKYIg4

std::set<Chain> Language::Reverse() {
  std::cout << "Entrando metodo reversa\n";
  std::set<Chain> reverse;
  for (std::set<Chain>::iterator it = language_.begin();
      it != language_.end(); ++it) {
    std::cout << "reversa: " << it->Reverse() << std::endl;
    reverse.insert(it->Reverse());
  }
  return reverse;
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