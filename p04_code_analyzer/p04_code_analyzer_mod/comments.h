// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 25/10/2022
// Archivo comments.h:
// Contiene la cabecera clase comments.
// Referencias:
// Enlaces de interéss

#include <vector>
#include <string>
#include <regex>

class Comments {

	public:
		// Constructores y destructores
    Comments(std::string,int);	// No descripcion
		Comments(std::string);			// Descripcion
    ~Comments();

		// Getters y setters
		int GetEnd(void);
		int GetSize();
		int GetStart(void);
		bool isDescription(void);
		void SetEnd(int);

		// Funciones estáticas
		static bool isComment(std::string);
		static int Type(std::string);
		static bool isLastMultiComment(std::string);

		// Operaciones
		void AddString(std::string);
		void WriteAsReference(void);
		int BuildMultiComment();
		friend std::ostream &operator<<(std::ostream &, Comments &);

	private:
		bool isMultiCommentEnding(std::string);

	private:
    bool description_;
		int start_;
		int end_;
		std::vector<std::string> comments_;
};