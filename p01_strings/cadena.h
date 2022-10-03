#include "simbolo.h"

#include <iostream>
#include <vector>

#pragma once

class Cadena{                                                               //|
  public:
    Cadena();
    Cadena(Simbolo);
    Cadena(const Cadena&);
    // Cadena(Cadena&);

    const std::vector<Simbolo>& GetCadena()const;
    void SetCadena(std::vector<Simbolo>);
    void AddSimbolo(Simbolo);
    int Longitud();
    Cadena Inversa();
    std::vector<Cadena> Prefijo();
    std::vector<Cadena> Sufijo();
    void Print();
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