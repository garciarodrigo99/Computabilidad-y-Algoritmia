// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo alfabeto.h: Cabecera de la clase Alfabeto.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include "simbolo.h"
#include "cadena.h"

#include <iostream>
#include <vector>

#pragma once

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
