/**
 * @file simbolo.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Cabecera de la clase Symbol.
 * Se define la clase Symbol con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 * @link
 * https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
 * @link
 * https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
 */

#include <iostream>
#include <string>
#pragma once

static char const kEmptyChain = '&'; // cambiar

class Symbol {
public:
  // Constructores y destructores
  Symbol(const std::string);
  Symbol(char);
  ~Symbol();

  // Getters
  const char position(int);
  int Size() const;

  // Operaciones
  bool CheckSimbols(Symbol);
  bool isEqual(Symbol);
  bool isEqual(Symbol) const;
  bool isEqual(std::string);

  // Sobrecarga de operadores
  bool operator<(const Symbol) const;
  void operator=(const Symbol);
  bool operator==(const Symbol) const;
  operator std::string(void) const;
  friend std::ostream &operator<<(std::ostream &, const Symbol &);

private:
  std::string symbol_;
};
