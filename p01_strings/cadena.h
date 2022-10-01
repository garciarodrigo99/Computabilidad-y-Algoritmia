#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Cadena{
  public:
    Cadena();
    Cadena(std::vector<Simbolo>);
    Cadena(Simbolo);
    //Cadena(Cadena)

    std::vector<Simbolo>& GetCadena();
    void SetCadena(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    int Longitud();
    Cadena Inversa();
    void Print();//Cambiar por operador<<
    //operator=

  private:
    std::vector<Simbolo> c_;
};