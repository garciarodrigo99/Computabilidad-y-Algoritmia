#include <iostream>
#pragma once

//https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
//https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition

static char* const kCadenaVacia = "&"; //cambiar

class Simbolo {
  public:
    Simbolo(char*);
    char* GetSimbolo();
    void SetSimbolo(char*);
    //operator==
    //operator()
    friend std::ostream& operator<<(std::ostream&, Simbolo&);

  private:
    char* s_;
};
