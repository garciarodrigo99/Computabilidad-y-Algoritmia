#include "codeStructurer.h"

#include <iostream>
#include <fstream>
#include "assert.h"
#define SALTO_LINEA std::cout << "\n";
 
CodeStructurer::CodeStructurer(std::string paramProgramName, 
															std::string paramOutFile) : 
															program_name_(paramProgramName),
															out_file_(paramOutFile) {}

CodeStructurer::~CodeStructurer() {}

void CodeStructurer::ReadFile() {
	std::string nombre_archivo = program_name_; // Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;

  // Lectura fichero
  while (getline(archivo, linea)) {
    lines_.push_back(linea);
  }
}

void CodeStructurer::FillContent() {
	// std::cout << lines_.size() << std::endl;
	// return;
	int pos = 0;
	int comment = Comments::Type(lines_.at(pos));
	if (comment >= 0) {
		Comments description(lines_.at(pos));
		if (comment == 1){
			while (!(Comments::isLastMultiComment(lines_.at(pos)))) {
				description.AddString(lines_.at(pos));
				pos++;
			}
			description.AddString(lines_.at(pos));
			description.SetEnd(pos);
		}
		pos++;
		description.SetEnd(pos);
		comments_.push_back(description);
	}

	for (size_t i = pos; i < lines_.size(); i++) {
		int comment = Comments::Type(lines_.at(i));
		if (comment >= 0) {
			Comments commentLine(lines_.at(i),i);
			if (comment == 1){
				while (!(Comments::isLastMultiComment(lines_.at(i)))) {
					commentLine.AddString(lines_.at(i));
					i++;
				}
				commentLine.AddString(lines_.at(i));
				commentLine.SetEnd(i);
				i++;
			}
			commentLine.SetEnd(i);
			comments_.push_back(commentLine);
		}
		if (Loop::isLoop(lines_.at(i))) {
			Loop auxLoop(lines_.at(i),i);
			loops_.push_back(auxLoop);
		}
		if (fMain::isMain(lines_.at(i))) {
			assert(main_ == false);
			main_ = true;
		}
		if (Variable::isVariable(lines_.at(i))) {
			Variable auxVariable(lines_.at(i),i);
			variable_.push_back(auxVariable);
		}	
	}
}

void CodeStructurer::Write() {
	ReadFile();
	FillContent();
	
	std::cout << "PROGRAM: " << program_name_ << std::endl;

	if (comments_.front().isDescription()) {
		std::cout << "DESCRIPTION:" << std::endl;
		std::cout << comments_.front() << std::endl;
	}
	SALTO_LINEA

	std::cout << "VARIABLES:" << std::endl;
	if (!(variable_.empty())) {
		for (size_t i = 0; i < variable_.size(); i++) {
			std::cout << variable_.at(i) << std::endl;
		}
	}
	SALTO_LINEA

	std::cout << "STATEMENTS:" << std::endl;
	if (!(loops_.empty())) {
		for (size_t i = 0; i < loops_.size(); i++) {
			std::cout << loops_.at(i) << std::endl;
		}
	}
	SALTO_LINEA

	std::cout << "MAIN:" << std::endl;
	std::cout << std::boolalpha << main_ << std::endl;
	SALTO_LINEA

	std::cout << "COMMENTS: \n";
	if (comments_.size() != 0) {
		comments_.front().WriteAsReference();
	}
	if (comments_.size() > 1) {
		for (size_t i = 1; i < comments_.size(); i++){
			std::cout << comments_.at(i) << std::endl;
		}
	}
}
