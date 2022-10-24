#include "loop.h"

Loop::Loop(/* args */)
{
}

Loop::~Loop()
{
}

bool Loop::isFor(std::string stringParam) {
	std::regex rexp("(\\s*for\\s\\(.*;.*;.*\\)\\s\\{)");
	return (std::regex_search(stringParam, rexp));
}

bool Loop::isWhile(std::string stringParam) {
	std::regex rexp("(\\s*while\\s\\(.*\\)\\s\\{)");
	return (std::regex_search(stringParam, rexp));
}