#include "lenguaje.h"

#include <stack>

class Calculator {

public:
    Calculator(/* args */);
    ~Calculator();

private:
    std::set<Language> language_set;
};