// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.es
// Fecha: 04/10/2022
// Archivo simbolo.h: Cabecera de la clase Simbolo.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
// https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <string>
#pragma once

static char const kCadenaVacia = '&'; //cambiar

class Simbolo {
  public:
    Simbolo(const std::string);
    ~Simbolo();
    std::string GetSimbolo();
    std::string GetSimbolo()const;
    bool isEqual(Simbolo);
    friend std::ostream& operator<<(std::ostream&, const Simbolo&);
    bool CheckSimbols(Simbolo);

    // Para encapsular más 
    int Size()const;
    const char position(int);

  private:
    std::string s_;
};
