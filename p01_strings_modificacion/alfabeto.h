#include "simbolo.h"
#include "cadena.h"

#include <iostream>
#include <vector>

#pragma once

//https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl

class Alfabeto {
  public:
    Alfabeto(Simbolo);
    Alfabeto(std::vector<Simbolo>);
    std::vector<Simbolo>& GetAlfabeto();
    void SetAlfabeto(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    bool inSimbolo(Simbolo);
    bool okCadena(Cadena);
    int DistinctSimbol(Cadena);
    friend std::ostream& operator<<(std::ostream&, Alfabeto&);
    //Metodo comprobar cadena pertenece a alfabeto

  private:
    std::vector<Simbolo> a_;
};
