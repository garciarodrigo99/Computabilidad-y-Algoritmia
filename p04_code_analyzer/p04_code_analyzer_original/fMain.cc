#include "fMain.h"

fMain::fMain(/* args */)
{
}

fMain::~fMain()
{
}

bool fMain::isMain(std::string stringParam) {
  std::regex rexp("(\\s*int main \\(.*\\)\\s*\\{)");
	return (std::regex_search(stringParam, rexp));
}