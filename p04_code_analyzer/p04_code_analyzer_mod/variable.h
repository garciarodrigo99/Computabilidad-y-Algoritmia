// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo variable.h:
// Contiene la cabecera clase variable.
// Referencias:
// Enlaces de interéss

#include <string>
#include <regex>

class Variable{

	public:
  Variable(std::string,int);
	~Variable();

	static bool isVariable(std::string);

	friend std::ostream &operator<<(std::ostream &, Variable &);
	static bool isString(std::string);
	private:
		static bool isInteger(std::string);
		static bool isDouble(std::string);
		

	private:
		int n_line_;
		std::string type_;
		std::string name_;
		int integerValue;
		double doubleValue;
		std::string stringValue;
		bool initialization_;
};