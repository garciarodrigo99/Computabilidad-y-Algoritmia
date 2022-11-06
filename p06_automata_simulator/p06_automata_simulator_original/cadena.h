// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulación de autómatas finitos
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 08/11/2022
// Archivo cadena.h: Cabecera de la clase Chain.
// Se define la clase Chain con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 04/11/2022 - Creaci´on (primera versi´on) del c´odigo

#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Alphabet;

class Chain {
public:
  // Constructores y destructores
  Chain();
  Chain(Symbol);
  Chain(std::vector<Symbol>);
  Chain(const Chain &); // Constructor de copia

  // Getters y setters
  Symbol Position(int) const;
  int Size(void) const;

  // Operaciones
  void AddSymbol(Symbol);
  static Chain Concatenate(const Chain &, const Chain &);
  Alphabet GenerateAlphabet(void);
  bool inSymbol(Symbol);
  bool isEqual(const Chain &) const;
  std::vector<Chain> Prefix();
  void Print(void);
  Chain Reverse(void);
  Chain Reverse(void) const;
  std::vector<Chain> Substring(void);
  std::vector<Chain> Sufix(void);

  // Sobrecarga operadores
  bool operator<(const Chain) const;
  friend std::ostream &operator<<(std::ostream &, const Chain &);
  bool operator==(const Chain &) const;

private:
  std::vector<Symbol> chain_;
};

bool inVector(std::vector<Chain> param_vector, Chain param_cadena);