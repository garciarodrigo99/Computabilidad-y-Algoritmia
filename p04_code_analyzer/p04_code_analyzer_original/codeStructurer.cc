#include "codeStructurer.h"

#include <iostream>
#include <fstream>

CodeStructurer::CodeStructurer(std::string paramProgramName, 
															std::string paramOutFile) : 
															program_name_(paramProgramName),
															out_file_(paramOutFile) {}

CodeStructurer::~CodeStructurer() {}

void CodeStructurer::Write() {
	std::string nombre_archivo = program_name_; // Parametro 1
  std::ifstream archivo(nombre_archivo.c_str());
  std::string linea;

  std::vector<std::string> string_vector;
  // Lectura fichero
  while (getline(archivo, linea)) {
    string_vector.push_back(linea);
  }

	for (size_t i = 0; i < string_vector.size(); i++) {
		// if (/* condition */) {
		// 	/* code */
		// }
		if (Loop::isFor(string_vector.at(i)) || 
				Loop::isWhile(string_vector.at(i))) {
			/* code */
		}
		// if (/* condition */) {
		// 	/* code */
		// }
		// if (/* condition */) {
		// 	/* code */
		// }
		
	}
	

	std::cout << "PROGRAM: " << program_name_ << std::endl;

	std::regex end("(\b*\\*\\/)");

  // if (Comments::isMultiComment(string_vector.at(0))) {
  //   std::cout << "DESCRIPTION: \n";
	// 	Comments description(string_vector.at(0));
  //   int lastDescriptionPos = 1;
  //   while (!(std::regex_search(string_vector.at(lastDescriptionPos),end))) {
	// 		description.AddString(string_vector.at(lastDescriptionPos));
  //     lastDescriptionPos++;
  //   }
	// 	description.AddString(string_vector.at(lastDescriptionPos));
	// 	description.SetEnd(lastDescriptionPos);
  //   lastDescriptionPos++;
	// 	comments_.push_back(description);
  // }
	// comments_.front().Write();
	std::cout << comments_.front() << std::endl;
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
