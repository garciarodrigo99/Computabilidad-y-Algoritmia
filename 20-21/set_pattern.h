#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LETRAS 26

class Set {
  public:
  Set(void);
  bool IsSet(short);
  bool StrOk(const std::string);
  void Search(const std::string, const std::string, const std::string);
  std::vector<std::string> Read(const std::string);
  void Write(const std::string, short);

  private:
  std::vector<short> alfabeto_;
};