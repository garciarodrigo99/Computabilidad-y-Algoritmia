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

class Cadena{                                                               //|
  public:
    // Constructores y destructores
    Cadena();
    Cadena(Symbol);
    Cadena(const Cadena&); //Constructor de copia

    // Getters y setters
    Symbol Position(int)const;
    int Size()const;

    // Operaciones 
    void AddSymbol(Symbol);
    bool inSymbol(Symbol);
    bool isEqual(Cadena&);
    std::vector<Cadena> Prefix();
    void Print();
    Cadena Reverse();
    std::vector<Cadena> Substring();
    std::vector<Cadena> Sufix();

    // Sobrecarga operadores
    bool operator<(const Cadena)const;
    friend std::ostream& operator<<(std::ostream&, Cadena&);
    //operator=

  private:
    std::vector<Symbol> chain_;
};

bool inVector(std::vector<Cadena> param_vector, Cadena param_cadena);