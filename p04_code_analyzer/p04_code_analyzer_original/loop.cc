#include "loop.h"
#include <iostream>
Loop::Loop(/* args */)
{
}

Loop::~Loop()
{
}

bool Loop::isFor(std::string stringParam) {
	std::regex rexp("\\s*(for)\\s\\(.*;.*;.*\\)\\s\\{");
	return (std::regex_match(stringParam, rexp));
}

bool Loop::isLoop(std::string stringParam) {
	std::regex rexp("\\s*((for)\\s\\(.*;.*;|while\\s).*\\)\\s\\{");
	std::smatch str_match;
	std::regex_search(stringParam,str_match,rexp);
	for (size_t i = 0; i < str_match.size(); i++) {
		std::cout << i << ": " << str_match[i] << std::endl;
	}
	return (std::regex_match(stringParam, rexp));
}

bool Loop::isWhile(std::string stringParam) {
	std::regex rexp("(\\s*(while)\\s\\(.*\\)\\s\\{)");
	return (std::regex_search(stringParam, rexp));
}