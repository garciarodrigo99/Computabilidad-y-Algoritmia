// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo codeStructurer.h:
// Contiene la cabecera clase codeStructurer.
// Referencias:
// Enlaces de interéss

#include "variable.h"
#include "loop.h"
#include "fMain.h"
#include "comments.h"

class CodeStructurer {

	public:
		CodeStructurer(std::string, std::string);
		~CodeStructurer();
		void Write(void);

	private:
		void ReadFile();
		void FillContent();

	private:
		std::string program_name_;
		std::string out_file_;
		//fMain main_;
		bool main_;
		std::vector<Comments> comments_;
		std::vector<Loop> loops_;
		std::vector<Variable> variable_;
		std::vector<std::string> lines_;
};