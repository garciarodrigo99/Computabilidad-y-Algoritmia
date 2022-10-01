#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Cadena{
  public:
    Cadena();
    Cadena(std::vector<Simbolo>);
    Cadena(Simbolo);

    std::vector<Simbolo>& GetCadena();
    void SetCadena(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    int Longitud();


  private:
    std::vector<Simbolo> c_;
};