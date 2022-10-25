// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo fMain.h:
// Contiene la cabecera clase fMain.
// Referencias:
// Enlaces de interéss

#include <string>
#include <regex>

class fMain{

	public:
    fMain(/* args */);
    ~fMain();
	static bool isMain(std::string);

	private:
    std::string main_;
};