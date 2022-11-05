// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo fMain.cc:
// Contiene la implementacion clase fMain.
// Referencias:
// Enlaces de interéss

#include "fMain.h"

fMain::fMain(/* args */)
{
}

fMain::~fMain()
{
}

bool fMain::isMain(std::string stringParam) {
  std::regex rexp("\\s*int\\s*main\\s*\\(.*\\)\\s*\\{");
	return (std::regex_match(stringParam, rexp));
}