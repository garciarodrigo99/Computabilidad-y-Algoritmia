// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo simbolo.h: Cabecera de la clase Symbol.
// Se define la clase Symbol con sus métodos y atributos
// Referencias:
// Enlaces de interés
// https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
// https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <string>
#pragma once

static char const kEmptyChain = '&'; // cambiar

class Symbol {
public:
  // Constructores y destructores
  Symbol(const std::string);
  ~Symbol();

  // Getters
  const char position(int);
  int Size() const;

  // Operaciones
  bool CheckSimbols(Symbol);
  bool isEqual(Symbol);
  bool isEqual(Symbol) const;

  // Sobrecarga de operadores
  bool operator<(const Symbol) const;
  friend std::ostream &operator<<(std::ostream &, const Symbol &);

private:
  std::string symbol_;
};
