#include <iostream>
#include <string>
#pragma once

//https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
//https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition

static char const kCadenaVacia = '&'; //cambiar

class Simbolo {
  public:
    //Simbolo(std::string&);
    Simbolo(const std::string);
    ~Simbolo();
    //const char* GetSimbolo();
    //void SetSimbolo(char*);
    //operator==
    //operator()
    friend std::ostream& operator<<(std::ostream&, const Simbolo&);
    bool CheckSimbols(Simbolo);

    // Para encapsular más 
    int Size();
    const char position(int);

  private:
    std::string s_;
};
