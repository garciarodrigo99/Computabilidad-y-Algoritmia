// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 8: Gramáticas en Forma Normal de Chomsk
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 08/11/2022
// Archivo Alphabet.h: Cabecera de la clase Alphabet.
// Se define la clase Alphabet con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 04/11/2022 - Creaci´on (primera versi´on) del c´odigo
#include "alfabeto.h"

#include <iostream>
#include <set>
//#include <unordered_set>
#include <vector>

#define DEFAULT_NAME "default_id"

#pragma once

class Language {
public:
  // Constructores y destructores
  Language(Alphabet, std::string);
  Language(Alphabet, std::set<Chain>, std::string);
  Language(const Language &, std::string);

  // Getters y setters
  std::string GetNameID() const;
  int Size() const;
  void SetName(std::string);

  // Iteradores
  std::set<Chain>::const_iterator begin() const;
  std::set<Chain>::const_iterator end() const;

  // Operaciones
  void AddChain(Chain);
  void AddSetChain(std::set<Chain>);
  Language Concatenation(const Language &); // Union alfabeto
  Language Diference(const Language &);
  bool inChain(Chain) const;
  Language Intersection(const Language &);
  Language Power(int); // 1
  std::set<Chain> PowerSetChain(int);
  Language Reverse(); // 1
  bool Subset(const Language &);
  Language Union(const Language &); // Union alfabeto

  // Sobrecarga de operadores
  bool operator<(const Language) const;
  friend std::ostream &operator<<(std::ostream &, const Language &);

private:
  Alphabet alphabet_;
  std::set<Chain> language_;
  std::string language_id_;
};