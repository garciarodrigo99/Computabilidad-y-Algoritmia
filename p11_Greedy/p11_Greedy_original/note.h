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
#include "simbolo.h"

#include <iostream>
#include <string>
#include <set>
#include "assert.h"

//static std::set<int> const noteSet({50000,20000,10000,5000,2000,1000,500});

class Note : public Cash {
  public:
    // Constructores y destructores
    Note(int amount) {
        assert(noteSet.count(amount) != 0);
        amount_ = amount;
    }

    ~Note() {}

    void print(std::ostream&) const {
        int printAmount = amount_ / 100;
        std::cout << printAmount << "€";
    }
    friend std::ostream &operator<<(std::ostream &, const Note &);
    operator int (void) const { return amount_; }
    static std::set<int> const noteSet;
  private:
    int amount_;
};

inline std::ostream& operator<< (std::ostream& os, const Note& myCash){
  myCash.print(os); // delegate the work to a polymorphic member function.
  return os;
}

inline std::set<int> const Note::noteSet({50000,20000,10000,5000,2000,1000,500});