#include "comments.h"

Comments::Comments(/* args */) {}

Comments::~Comments() {}

bool Comments::isDescription(std::string stringParam) {
	std::regex rexp("(/'\'*)");
	return (std::regex_search(stringParam, rexp));
}

bool Comments::isComment(std::string stringParam) {
	std::regex rexp("(hola((\b)*))");
	return (std::regex_search(stringParam, rexp));
}