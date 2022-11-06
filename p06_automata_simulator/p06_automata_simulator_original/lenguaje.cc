// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulación de autómatas finitos
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 08/11/2022
// Archivo lenguaje.cc: Fichero de implementación de la clase Language.
// Se define la clase Language con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// https://stackoverflow.com/questions/3065438/switch-statement-with-returns-code-correctness
// Historial de revisiones
// 04/11/2022 - Creaci´on (primera versi´on) del c´odigo

#include "lenguaje.h"

#include <assert.h>

// Constructor con los parametros Alfabeto que define el lenguaje y el nombre
// del lenguaje, que en caso de no pasar string se asignará uno por defecto
Language::Language(Alphabet param_alphabet, std::string s = DEFAULT_NAME)
    : alphabet_(param_alphabet) {
  language_id_ = s;
}

// Constructor con los parametros Alfabeto que define el lenguaje, un conjunto
// de cadenas y el nombre del lenguaje, que en caso de no pasar string se
// asignará uno por defecto
Language::Language(Alphabet param_alphabet, std::set<Chain> param_chain,
                   std::string s = DEFAULT_NAME)
    : alphabet_(param_alphabet), language_(param_chain) {
  language_id_ = s;
}

// Constructor de copia que recibe como parametros el lenguaje al que va a ser
// igual y el nombre del lenguaje. En caso de que no se especifique este
// parametro se le asignará un nombre por defecto
Language::Language(const Language &param_language, std::string s = DEFAULT_NAME)
    : Language(param_language.alphabet_, param_language.language_) {
  language_id_ = s;
}

// Retorna el nombre del lenguaje
std::string Language::GetNameID() const { return language_id_; }

// Retorna el numero de cadenas del lenguaje
int Language::Size() const { return language_.size(); }

// Setter del nombre del lenguaje
void Language::SetName(std::string id) { language_id_ = id; }

// Añadir cadena al lenguaje
void Language::AddChain(Chain chain_param) { language_.insert(chain_param); }

// Añadir un conjunto de cadenas al lenguaje
void Language::AddSetChain(std::set<Chain> param_set) {
  for (std::set<Chain>::iterator it = param_set.begin(); it != param_set.end();
       ++it)
    AddChain(*it);
}

// Operacion para concatenar dos lenguajes
Language Language::Concatenation(const Language &param_language) {
  Alphabet aux_alphabet(alphabet_);
  aux_alphabet.AlphabetUnion(param_language.alphabet_);
  Language union_language(aux_alphabet);

  for (std::set<Chain>::iterator it1 = language_.begin();
       it1 != language_.end(); it1++) {
    for (std::set<Chain>::iterator it2 = param_language.language_.begin();
         it2 != param_language.language_.end(); it2++) {
      union_language.AddChain(Chain::Concatenate(*it1, *it2));
    }
  }
  return union_language;
}

// Operacion diferencia de lenguajes
Language Language::Diference(const Language &param_language) {
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

// Operacion intersección de dos lenguajes
Language Language::Intersection(const Language &param_language) {
  Language intersection(alphabet_);
  for (std::set<Chain>::iterator it1 = language_.begin();
       it1 != language_.end(); it1++) {
    if (param_language.inChain(*it1))
      intersection.AddChain(*it1);
  }
  return intersection;
}

// Operacion potencia sobre un lenguaje, que recibe como parametro el exponente
// al cual elevar el lenguaje
Language Language::Power(int power) {
  // Aprovechando el constructor y el metodo recursivo,
  // el método quedaría simplificado de la siguiente manera
  assert(power >= 0);
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

    std::set<Chain> aux = PowerSetChain(n - 1);

    for (std::set<Chain>::iterator it1 = language_.begin();
         it1 != language_.end(); it1++) {
      for (std::set<Chain>::iterator it2 = aux.begin(); it2 != aux.end();
           it2++) {
        power.insert(Chain::Concatenate(*it1, *it2));
      }
    }
    return power;
    break;
  }
  }
}

// Operacion inversa de un lenguaje
Language Language::Reverse() {
  Language reverse(alphabet_);
  for (std::set<Chain>::iterator it = language_.begin(); it != language_.end();
       ++it) {
    reverse.AddChain(it->Reverse());
  }
  return reverse;
}

// Operacion para saber si el lenguaje objeto está contenido o es igual que el
// lenguaje que se la ha pasado por parametro
bool Language::Subset(const Language &param_language) {

  for (std::set<Chain>::iterator it = language_.begin(); it != language_.end();
       ++it) {
    if (!(param_language.inChain(*it))) {
      return false;
    }
  }
  return true;
}

// Operacion union de dos lenguajes
Language Language::Union(const Language &param_language) {
  Alphabet aux_alphabet(alphabet_);
  aux_alphabet.AlphabetUnion(param_language.alphabet_);
  Language union_language(aux_alphabet);

  for (std::set<Chain>::iterator it = language_.begin(); it != language_.end();
       ++it) {
    union_language.AddChain(*it);
  }
  for (std::set<Chain>::iterator it = param_language.language_.begin();
       it != param_language.language_.end(); ++it) {
    union_language.AddChain(*it);
  }
  return union_language;
}

// Sobrecarga operador '<' para trabajar con la clase std::set
bool Language::operator<(const Language param_language) const {
  // Diferente tamaño
  if ((int)language_.size() != param_language.Size()) {
    return ((int)language_.size() < param_language.Size());
  }
  // Ya sabemos tienen mismo tamaño
  // Lenguaje vacio
  if (language_.size() == 0) {
    return ((int)language_.size() < param_language.Size());
  }
  // Mismo tamaño mayor que 0
  // Recorremos el conjunto de cadenas que forman el lenguaje del obejeto
  for (std::set<Chain>::iterator it = language_.begin(); it != language_.end();
       ++it) {
    // Si una cadena no se encuentra en el lenguaje parametro, retornamos true
    if (!(param_language.inChain(*it)))
      return true;
  }
  // Una vez terminado el for, sin que se haya salido del metodo, indicamos
  // false. Se ha implementado de esta manera evitar lenguajes repetidos cuando
  // se trabaje con la clase std::set
  return false;
}

// Sobrecarga operador '<<' para escritura del objeto
std::ostream &operator<<(std::ostream &os, const Language &param_language) {
  os << param_language.language_id_ << " = {";

  for (std::set<Chain>::iterator it = param_language.language_.begin();
       it != param_language.language_.end(); ++it) {
    std::cout << *it;
    // Arreglo para que salga en el formato requerido
    std::set<Chain>::iterator it2 = it;
    ++it2;
    if (it2 != param_language.language_.end()) {
      std::cout << ", ";
    }
  }

  os << "}";
  return os;
}