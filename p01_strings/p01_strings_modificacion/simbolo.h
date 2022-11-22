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
// Se define la clase Symbol con sus métodos y atributos
// Referencias:
// Enlaces de interés
// https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
// https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
// Historial de revisiones
// 04/10/2022 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <string>
#pragma once

static char const kEmptyChain = '&'; //cambiar

class Symbol {
  public:
    Symbol(const std::string);
    ~Symbol();
    std::string GetSymbol();
    std::string GetSymbol()const;
    bool isEqual(Symbol);
    bool isEqual(Symbol)const;
    friend std::ostream& operator<<(std::ostream&, const Symbol&);
    bool CheckSimbols(Symbol);
    bool operator<(const Symbol)const;

    // Para encapsular más 
    int Size()const;
    const char position(int);

  private:
    std::string symbol_;
};
