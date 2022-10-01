#include <iostream>
#pragma once

//https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header

static char* const kCadenaVacia = "&"; //cambiar

class Simbolo {
  public:
    Simbolo(char*);
    char* GetSimbolo();
    void SetSimbolo(char*);
    //operator==
    //operator()

  private:
    char* s_;
};
