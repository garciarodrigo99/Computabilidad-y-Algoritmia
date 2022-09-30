#include <iostream>

#include "set_pattern.h"

int main(int argc, char* argv[]) {

  if (argc == 1) {
    std::cout << "./pattern_search pattern infile.txt outfile.txt" << std::endl;
    return 1;
  }

  if (std::string(argv[1]) == "--help"){
    std::cout << "La manera correcta de ejecutar el programa es:" << std::endl;
    std::cout << "./pattern_search pattern infile.txt outfile.txt\n" << std::endl;
    std::cout << "El programa recibe un patron, en este caso letras";
    std::cout << " minusculas, un fichero de lectura y un fichero de salida.";
    std::cout << "\nAnalizara las cadenas para ver si se encuentra el patron ";
    std::cout << "indicado en alguna de ellas, en el caso de que asi sea,\n";
    std::cout << "se indicara en el fichero de salida en la correspondiente ";
    std::cout << "linea 'Sí' si se encuentra el patron y 'No' si no se "; 
    std::cout << "encuentra. \nEn el caso de que las palabras recibidas ";
    std::cout << "tengan simbolos que no pertencen al alfabeto se imprimira "; 
    std::cout << "'Error'." << std::endl;
    return 1;
  }

  Set conjunto;

  conjunto.Search(std::string(argv[1]),std::string(argv[2]),
                 std::string(argv[3]));

  return 0;
}






















/* Example program
#include <iostream>
using namespace std;

int main()
{
  unsigned char c;
  c = 164;
  std::cout << c << (int)c << std::endl;
  //std::cout << char(75) << std::endl;
  return 0;
}*/
