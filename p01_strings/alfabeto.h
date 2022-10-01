#include <iostream>
#include "simbolo.h"

class Alfabeto {
  public:
    Alfabeto(char*);
    char* GetAlfabeto();
    void SetAlfabeto(char*);

  private:
    char* s_;
};
