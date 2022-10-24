#include "variable.h"

Variable::Variable(/* args */){
}

Variable::~Variable(){
}

bool Variable::isInteger(std::string stringParam) {
  std::regex rexp("\\s*int\\s\\w*(\\s=\\s(-)?\\d{1,10})?;");
	return (std::regex_search(stringParam, rexp));
}

bool Variable::isDouble(std::string stringParam) {
	std::regex rexp("(\\s*double\\s\\w*(\\s\\=\\s(-)?\\d{1,8}\\.\\d{1,8})?;)");
	return (std::regex_search(stringParam, rexp));
}

bool Variable::isVariable(std::string stringParam) {
	return (isInteger(stringParam) || isDouble(stringParam));
}