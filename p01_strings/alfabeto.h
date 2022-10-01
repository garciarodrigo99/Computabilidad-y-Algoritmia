#include <iostream>
#include "simbolo.h"
#include <vector>
#pragma once

//https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl

class Alfabeto {
  public:
    Alfabeto(Simbolo);
    Alfabeto(std::vector<Simbolo>);
    std::vector<Simbolo> GetAlfabeto();
    void SetAlfabeto(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    //operator <<

  private:
    std::vector<Simbolo> a_;
};
