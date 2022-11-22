// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo cadena.h: Cabecera de la clase Cadena.
// Se define la clase Cadena con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Cadena{                                                               //|
  public:
    Cadena();
    Cadena(Symbol);
    Cadena(const Cadena&);
    // Cadena(Cadena&);

    const std::vector<Symbol>& GetCadena()const;
    void SetCadena(std::vector<Symbol>);
    void AddSymbol(Symbol);
    Cadena Inversa();
    std::vector<Cadena> Prefix();
    std::vector<Cadena> Sufix();
    std::vector<Cadena> Substring();
    void Print();
    friend std::ostream& operator<<(std::ostream&, Cadena&);
    //operator=
    bool isEqual(Cadena&);
    bool inSymbol(Symbol);
    //operator std::vector<Simbolo>(void);
    int Size();
    Symbol Position(int);

  private:
    std::vector<Symbol> chain_;
};

bool inVector(std::vector<Cadena> param_vector, Cadena param_cadena);