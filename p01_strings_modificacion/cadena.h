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
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
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
    std::vector<Cadena> Subcadena();
    void Print();
    friend std::ostream& operator<<(std::ostream&, Cadena&);
    //operator=
    bool isEqual(Cadena&);
    bool inSimbolo(Simbolo);
    //operator std::vector<Simbolo>(void);

  private:
    std::vector<Simbolo> c_;
};