// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor:  
// Correo: alu0101154473@ull.es
// Fecha: 11/10/2022
// Archivo cadena.h: Cabecera de la clase Chain.
// Se define la clase Chain con sus métodos y atributos
// Referencias:
// Enlaces de interéss
//
// Historial de revisiones
// 11/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Chain{                                                               
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
    static Chain Concatenate(const Chain&, const Chain&);
    bool inSymbol(Symbol);
    bool isEqual(const Chain&) const;
    std::vector<Chain> Prefix();
    void Print();
    Chain Reverse();
    Chain Reverse() const;
    std::vector<Chain> Substring();
    std::vector<Chain> Sufix();

    // Sobrecarga operadores
    bool operator<(const Chain)const;
    friend std::ostream& operator<<(std::ostream&, const Chain&);
    bool operator==(const Chain&) const;
    

  private:
    std::vector<Symbol> chain_;
};

bool inVector(std::vector<Chain> param_vector, Chain param_cadena);