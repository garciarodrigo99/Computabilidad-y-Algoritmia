#include "lenguaje.h"

#include <stack>

// struct Operations {
//     char c_operator;
//     int n_elements_;
// };

class Calculator {

public:
  Calculator(std::set<Language>, std::vector<std::string>);
  ~Calculator();

  Language GetResult();

private:
  Language GetLanguage(std::string);
  bool isLanguage(std::string);

private:
  std::set<Language> language_set_;
  std::vector<std::string> sentence_;
  std::stack<Language> stack_;
  // Operations operators_;
};