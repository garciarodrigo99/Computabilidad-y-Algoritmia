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
#include "alfabeto.h"

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

#pragma once

class Language {
  public:
    // Constructores y destructores
    Language(Alphabet);
    Language(Alphabet, std::set<Chain>);
    Language(const Language&);

    // Getters y setters
    int Size()const;

    // Operaciones
    void AddChain(Chain);
    void AddSetChain(std::set<Chain>);
    std::set<Chain> Concatenation(const Language&);//Union alfabeto
    Language Diference(const Language&);
    bool inChain(Chain) const;
    Language Intersection(const Language&);
    Language Power(int);//1
    std::set<Chain> PowerSetChain(int);
    Language Reverse();//1
    std::set<Chain> Union(const Language&);//Union alfabeto
    Language Union_L(const Language&);//Union alfabeto

    // Sobrecarga de operadores
    //bool operator<(const Language)const;
    friend std::ostream& operator<<(std::ostream&, const Language&);                 

  private:
    Alphabet alphabet_;
    std::set<Chain> language_;
};