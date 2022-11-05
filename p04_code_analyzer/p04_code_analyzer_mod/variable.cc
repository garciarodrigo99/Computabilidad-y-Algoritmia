// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo variable.cc:
// Contiene la implementacion clase variable.
// Referencias:
// Enlaces de interéss

#include "variable.h"
#include <iostream>

Variable::Variable(std::string paramString, int paramPos) : n_line_(paramPos) {
	std::regex rexp("\\s*(int)\\s(\\w*)(\\s=\\s(-)?(\\d{1,10}))?;");
	if (isDouble(paramString)) {
			rexp = "\\s*(double)\\s(\\w*)(\\s\\=\\s(-)?(\\d{1,8}\\.\\d{1,8}))?;";
	}
	if (isString(paramString)) {
			rexp = "\\s*.*(string)\\s(\\w*)(\\s\\=\\s\"(.*)\")?;";
	}
	std::smatch str_match;
	std::regex_search(paramString,str_match,rexp);
	type_ = str_match[1];
	name_ = str_match[2];
	initialization_ = (str_match[3].length() > 0);
	if (initialization_ == true) {
		if (type_ == "int") {
			integerValue = std::stoi(str_match[5]);
		}
		if (type_ == "double") {
			doubleValue = std::stod(str_match[5]);
		}
		if (type_ == "string") {
			stringValue = str_match[4];
		}
	}
}

Variable::~Variable(){
}

bool Variable::isInteger(std::string paramString) {
  std::regex rexp("\\s*(int)\\s(\\w*)(\\s=\\s(-)?(\\d{1,10}))?;");
	return (std::regex_match(paramString, rexp));
}

bool Variable::isDouble(std::string paramString) {
	std::regex rexp("\\s*(double)\\s(\\w*)(\\s\\=\\s(-)?(\\d{1,8}\\.\\d{1,8}))?;");
	return (std::regex_match(paramString, rexp));
}

bool Variable::isString(std::string paramString) {
	std::regex rexp("\\s*.*(string)\\s(\\w*)(\\s\\=\\s\"(.*)\")?;");
	return (std::regex_match(paramString, rexp));
}

bool Variable::isVariable(std::string paramString) {
	return (isInteger(paramString) || isDouble(paramString) || isString(paramString));
}

std::ostream &operator<<(std::ostream &os, Variable &paramVariable) {
	os << "[Line " << paramVariable.n_line_ << "] " << paramVariable.type_;
	os << ": " << paramVariable.name_;
	if (paramVariable.initialization_) {
		os << " = ";
		if (paramVariable.type_ == "int") {
			os << paramVariable.integerValue;
		}
		if (paramVariable.type_ == "double") {
			os << paramVariable.doubleValue;
		}
		if (paramVariable.type_ == "string") {
			os << paramVariable.stringValue;
		}
	}
	return os;
}