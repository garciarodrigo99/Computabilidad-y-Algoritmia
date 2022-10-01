#include <iostream>
#pragma once

//https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header

static char* const CADENA_VACIA = "&";

class Simbolo {
  public:
    Simbolo(char*);
    char* GetSimbolo();
    void SetSimbolo(char*);
    //operator==

  private:
    char* s_;
};
