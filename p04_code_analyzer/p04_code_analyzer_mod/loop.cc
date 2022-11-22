// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo loop.cc:
// Contiene la implementacion clase loop.
// Referencias:
// Enlaces de interéss

#include "loop.h"
#include <iostream>

Loop::Loop(std::string paramString, int paramLine) : start_(paramLine) {
	std::regex rexp("\\s*((for)\\s\\(.*;.*;|while\\s).*\\)\\s\\{");
	std::smatch str_match;
	std::regex_search(paramString,str_match,rexp);
	if (str_match[2].length() == 0) {
		type_ = "while";
	} else {
		type_ = "for";
	}
	
}

Loop::~Loop() {}

bool Loop::isFor(std::string stringParam) {
	std::regex rexp("\\s*(for)\\s\\(.*;.*;.*\\)\\s\\{");
	return (std::regex_match(stringParam, rexp));
}

bool Loop::isLoop(std::string stringParam) {
	return (isWhile(stringParam) || isFor(stringParam));
}

bool Loop::isWhile(std::string stringParam) {
	std::regex rexp("(\\s*(while)\\s\\(.*\\)\\s\\{)");
	return (std::regex_search(stringParam, rexp));
}

std::ostream &operator<<(std::ostream & os, Loop & paramLoop) {
	os << "[Line " << paramLoop.start_ << "] LOOP: " << paramLoop.type_;
	return os;
}