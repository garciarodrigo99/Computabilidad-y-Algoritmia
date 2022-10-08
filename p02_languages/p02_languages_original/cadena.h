// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo cadena.h: Cabecera de la clase Cadena.
// Se define la clase Cadena con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Chain{                                                               //|
  public:
    // Constructores y destructores
    Chain();
    Chain(Symbol);
    Chain(const Chain&); //Constructor de copia

    // Getters y setters
    Symbol Position(int)const;
    int Size()const;

    // Operaciones 
    void AddSymbol(Symbol);
    bool inSymbol(Symbol);
    bool isEqual(const Chain&);
    std::vector<Chain> Prefix();
    void Print();
    Chain Reverse();
    std::vector<Chain> Substring();
    std::vector<Chain> Sufix();

    // Sobrecarga operadores
    bool operator<(const Chain)const;
    friend std::ostream& operator<<(std::ostream&, const Chain&);
    inline bool operator==(const Chain&);

  private:
    std::vector<Symbol> chain_;
};

bool inVector(std::vector<Chain> param_vector, Chain param_cadena);