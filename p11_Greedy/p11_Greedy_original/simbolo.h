/**
 * @file simbolo.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Cabecera de la clase Cash.
 * Se define la clase Cash con sus métodos y atributos
 * @version 2.0
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 * @link
 * https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
 * @link
 * https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
 */

#pragma once
#include <iostream>
#include <string>
#include <set>

//static std::set<int> const coinSet({200,100,50,20,10,5,2,1});
//static std::set<int> const noteSet({50000,20000,10000,5000,2000,1000,500});

class Cash {
  public:
    // Constructores y destructores
    //Cash();
    //virtual ~Cash() = 0;
    virtual void print(std::ostream&) const = 0;
    virtual operator int (void) const = 0;
    friend std::ostream &operator<<(std::ostream &, const Cash &);
};

inline std::ostream& operator<< (std::ostream& os, const Cash& myCash){
  myCash.print(os); // delegate the work to a polymorphic member function.
  return os;
}