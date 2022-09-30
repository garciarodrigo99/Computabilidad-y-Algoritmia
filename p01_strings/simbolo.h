#include <iostream>

class Simbolo {
  public:
    Simbolo(char*);
    char* GetSimbolo();
    void SetSimbolo(char*);

  private:
    char* s_;
};
