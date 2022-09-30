#include "set_pattern.h"

/// Constructor de vector de letras minusculas (construir conjunto)
Set::Set() {
  for (unsigned i = 0; i < LETRAS; i++) {
    alfabeto_.push_back(97 + i);
  }
}

/// Metodo tipo bool que comprueba si un simbolo pertenece al cojunto
bool Set::IsSet(short ascii_code) {

  for (unsigned i = 0; i < alfabeto_.size(); i++) {
   if (ascii_code == alfabeto_[i])
    return true;
  }
  return false;
}

/** Metodo tipo bool que comprueba si todos los simbolos de la cadena  
  * pertenecen al conjunto */
bool Set::StrOk(const std::string str_check) {

  for (unsigned i = 0; i < str_check.size(); i++) {
   if (!(IsSet((short)str_check[i])))
    return false;
  }
  return true;
}
/** Metodo que se encarga de llamar a Read, almacena el texto que contiene,
  * llama StrOk, si devuelve true comprueba si un simbolo pertenece al 
  * patron, en caso afirmativo avanzara a medida que los simbolos lleven
  * el mismo orden que el patron indicado(dfa) imprimiendo "Sí" (llamando 
  * a Write()) en caso de que se encuentre el patron, y en caso negativo
  * se mantendra en el estado 0 imprimiendo "No" (llamando a Write()); y si
  * devuelve false mostrara por pantalla "Error" (llamando a Write()) */
void Set::Search(const std::string pattern, const std::string in_file,
                const std::string out_file) {
  std::vector<std::string> text_in = Read(in_file);

  for (unsigned i = 0; i < text_in.size(); i++) {
    unsigned estado = 0;
    if (StrOk(text_in[i])) {
      for (unsigned j = 0; 
          (j < text_in[i].size()) && (estado != pattern.length()); j++) {
          if (text_in[i][j] == pattern[(int)estado])
            estado++;
          else 
            estado = 0;
      }
      if (estado != pattern.length())
        Write(out_file, 0);
      else
        Write(out_file, 1);
    } else {
      Write(out_file, -1);
    }
  }
}
/** Metodo que lee el texto del fichero de entrada y lo almacena en un vector 
  * de strings*/
std::vector<std::string> Set::Read(const std::string file_name) {
  std::ifstream archivo_in(file_name);
  std::vector<std::string> saved_text;
  while (!archivo_in.eof()) {
    std::string texto;
    archivo_in >> texto;
    saved_text.push_back(texto);
  }
  return saved_text;
}
/** Metodo que escribe en un fichero de salida, cuyo nombre recibe por param,
  * "Sí" si recibe por segundo parametro 1, "No" si recibe 0, y "Error" si
  * recibe -1. */
void Set::Write(const std::string text_to_file, short cond) {
  std::ofstream archivo_out;
  archivo_out.open(text_to_file,std::ofstream::app);

  if (cond == 1) {
    archivo_out << "Sí" << std::endl;
  
  } else if (cond == 0) {
    archivo_out << "No" << std::endl;
  
  } else if (cond == -1) {
    archivo_out << "Error" << std::endl;
  } else {
  }
  

  archivo_out.close();
}