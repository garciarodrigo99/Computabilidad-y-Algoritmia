#include "lenguaje.h"

Language::Language(Alphabet param_alphabet) : alphabet_(param_alphabet) {}

Language::Language(Alphabet param_alphabet, std::set<Chain> param_chain) : 
                  alphabet_(param_alphabet), language_(param_chain) {}

int Language::Size()const { return language_.size(); }

void Language::AddChain(Chain chain_param) { language_.insert(chain_param); }

bool Language::inChain(Chain param_chain) {
  return (language_.count(param_chain) == 0);
}

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Language& param_language) {
  os << "{ ";

  for (std::set<Chain>::iterator it = param_language.language_.begin();
      it != param_language.language_.end(); ++it)
      std::cout << *it << " ";

  os << "}";
  return os;
}