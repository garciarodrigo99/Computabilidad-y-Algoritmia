#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Cadena{                                                               //|
  public:
    Cadena();
    // Cadena(std::vector<Simbolo>);
    Cadena(Simbolo);
    Cadena(Cadena&);

    std::vector<Simbolo>& GetCadena();
    void SetCadena(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    int Longitud();
    Cadena Inversa();
    void Print();//Cambiar por operador<<
    friend std::ostream& operator<<(std::ostream&, Cadena&);
    //operator=
    bool isEqual(Cadena&);
    //operator std::vector<Simbolo>(void);

  private:
    std::vector<Simbolo> c_;
};

//Lo declaro aquí porque si no tendría que crear un namespace
// std::ostream& operator<<(std::ostream& os, Cadena& param_cadena){
//   for (size_t i = 0; i < param_cadena.GetCadena().size(); i++){
//     os << param_cadena.GetCadena().at(i);
//   }
//   return os;
// }