// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo loop.h:
// Contiene la cabecera clase loop.
// Referencias:
// Enlaces de interéss 

#include <string>
#include <regex>

class Loop {

	public:
		Loop(std::string,int);
		~Loop();

		static bool isFor(std::string);
		static bool isWhile(std::string);
		static bool isLoop(std::string);
		friend std::ostream &operator<<(std::ostream &, Loop &);
	private:
		std::string type_;
		int start_;
};
