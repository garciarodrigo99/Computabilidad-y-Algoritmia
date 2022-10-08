#include "lenguaje.h"

// Sobrecarga operador<< para escritura del objeto
std::ostream& operator<<(std::ostream& os, Language& param_language) {
  os << "{ ";

  for (std::set<Chain>::iterator it = param_language.language_.begin();
      it != param_language.language_.end(); ++it)
      std::cout << *it << " ";

  os << "}";
  return os;
}