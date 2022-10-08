// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo Alphabet.h: Cabecera de la clase Alphabet.
// Se define la clase Alphabet con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "simbolo.h"
#include "cadena.h"

#include <iostream>
#include <set>
#include <vector>

#pragma once

class Alphabet {
  public:
    // Constructores y destructores
    Alphabet(Symbol);
    Alphabet(std::set<Symbol>);

    // Getters y setters
    int Size()const;

    // Operaciones
    void AddSymbol(Symbol);
    int DistinctSimbol(Chain);
    bool inSymbol(Symbol);
    bool okChain(Chain);//Metodo comprobar cadena pertenece a alfabeto

    // Sobrecarga de operadores
    bool operator<(const Alphabet)const;
    friend std::ostream& operator<<(std::ostream&, Alphabet&);

  private:
    std::set<Symbol> alphabet_;
};
