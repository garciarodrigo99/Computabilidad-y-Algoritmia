// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo alfabeto.h: Cabecera de la clase Alfabeto.
// Se define la clase Alfabeto con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "simbolo.h"
#include "cadena.h"

#include <iostream>
#include <vector>

#pragma once

class Alfabeto {
  public:
    Alfabeto(Symbol);
    Alfabeto(std::vector<Symbol>);

    void SetAlfabeto(std::vector<Symbol>);
    void AddSymbol(Symbol);
    bool inSymbol(Symbol);
    bool okCadena(Cadena);//Metodo comprobar cadena pertenece a alfabeto
    int DistinctSimbol(Cadena);
    friend std::ostream& operator<<(std::ostream&, Alfabeto&);

    int Size();
    Symbol Position(int);

  private:
    std::vector<Symbol> alfabeto_;
};
