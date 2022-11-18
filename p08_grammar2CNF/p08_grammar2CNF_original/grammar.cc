/**
 * @file Grammar.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Fichero de implementación de la clase Grammar.
 * Se define la clase Grammar con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "grammar.h"

#include <assert.h>
#include <fstream>
#include <string>

Grammar::Grammar() {}

Grammar::Grammar(std::string fileName) {
  std::ifstream archivo(fileName.c_str());
  std::string linea;

  // Simbolos terminales
  getline(archivo, linea);
  int nTerminalSymbol = stoi(linea);
  for (int i = 0; i < nTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea.front());
    terminalSymbol_.insert(auxSymbol);
  }

  // Simbolos no terminales
  getline(archivo, linea);
  int nNonTerminalSymbol = stoi(linea);
  for (int i = 0; i < nNonTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea.front());
    nonTerminalSymbol_.insert(auxSymbol);
  }

  //@To-Do
  // Asignar simbolo no terminal de arranque
  getline(archivo, linea);
  for (auto symbol : linea) {
    startSymbolId_.push_back(symbol);
  }

  // Producciones
  getline(archivo, linea);
  int nProductions = stoi(linea);
  for (int i = 0; i < nProductions; i++) {
    getline(archivo, linea);
    std::vector<std::string> splittedLine(SplitChainGrammar(linea));
    std::vector<Symbol> auxSymbolVector;
    if ((splittedLine.at(2).size() == 1) &&
        (splittedLine.at(2).at(0) == kEmptyChain)) {
      Symbol emptyChain(kEmptyChain);
      auxSymbolVector.push_back(emptyChain);
    } else {
      for (auto symbol : splittedLine.at(2)) {
        std::string auxString;
        auxString.push_back(symbol);
        Symbol auxSymbol(auxString);
        auxSymbolVector.push_back(auxSymbol);
      }
    }
    ProductionRule auxProductionRule(splittedLine.at(0), auxSymbolVector);
    addProductionRule(auxProductionRule);
  }
}

Grammar::Grammar(Grammar &paramGrammar)
    : terminalSymbol_(paramGrammar.terminalSymbol_),
      nonTerminalSymbol_(paramGrammar.nonTerminalSymbol_),
      startSymbolId_(paramGrammar.startSymbolId_),
      productionRules_(paramGrammar.productionRules_) {}

/**
 * @brief Destroy the Grammar:: Grammar object
 *
 */
Grammar::~Grammar() {}

void Grammar::addNonTerminalSymbol(Symbol paramSymbol) {
  nonTerminalSymbol_.insert(paramSymbol);
}

/**
 * @brief Metodo que añade transiciones al Grammar. Se comprueba que ambos
 * estados pertenecen al conjunto de estados del Grammar y que el simbolo
 * pertenece al Alfabeto
 *
 * @param actualStateId Estado origen
 * @param paramSymbol Simbolo
 * @param nextStateId Estado destino
 */
void Grammar::addProductionRule(ProductionRule paramProduction) {
  // assert(nonTerminalSymbol_.count(paramProduction.getNonFinalSymbol()) != 0);
  productionRules_.insert(paramProduction);
}

void Grammar::addTerminalSymbol(Symbol paramSymbol) {
  terminalSymbol_.insert(paramSymbol);
}

void Grammar::convertToCNF() {
  // Sustituir simbolos terminales
  std::set<ProductionRule> toEraseSet;
  for (auto pr : productionRules_) {
    // Longitud de produccion > 1
    if (pr.getSymbolVector().size() > 1) {
      for (size_t i = 0; i < pr.getSymbolVector().size(); i++) {
        // Simbolo terminal
        if (terminalSymbol_.count(pr.getSymbolVector().at(i)) != 0) {
          toEraseSet.insert(pr); // Enviar produccion para que sea borrada
          // Nombre nueva produccion
          std::string auxString;
          auxString.push_back('C');
          for (int j = 0; j < pr.getSymbolVector().at(i).Size(); j++)
            auxString.push_back(pr.getSymbolVector().at(i).position(j));

          Symbol Cs(auxString);
          // Se inserta el simbolo designado al conjunto de simbolos no
          // terminales
          nonTerminalSymbol_.insert(Cs);
          // Inserto la (nueva) produccion de simbolo terminal al conjunto de
          // producciones
          ProductionRule terminalSymbolProduction(Cs,
                                                  pr.getSymbolVector().at(i));
          productionRules_.insert(terminalSymbolProduction);

          // Modificar la produccion cambiando simbolo terminal por su
          // produccion
          std::vector<Symbol> prVector(pr.getSymbolVector());
          prVector.at(i) = Cs;
          ProductionRule correctedProd(pr.getNonFinalSymbol(), prVector);
          productionRules_.insert(correctedProd);
        }
      }
    }
  }
  // Borrar las producciones obsoletas tras la primera pasada
  for (auto erase : toEraseSet)
    productionRules_.erase(erase);
  toEraseSet.clear(); // Limpiar set

  // Reducir a 2 numero estados no terminales
  for (auto pr : productionRules_) {
  }
}

bool Grammar::isRegular() {
  bool status = true;
  for (auto pr : productionRules_) {
    if (pr.getType(nonTerminalSymbol_) == -1)
      status = false;
  }
  return status;
}

void Grammar::setStartSymbol(std::string paramString) {
  startSymbolId_ = paramString;
}

void Grammar::writeFile(std::string outputFile) {
  std::ofstream file(outputFile);
  std::string line;
  file << terminalSymbol_.size() << "\n";
  for (auto symbol : terminalSymbol_)
    file << symbol << "\n";
  file << nonTerminalSymbol_.size() << "\n";
  for (auto symbol : nonTerminalSymbol_)
    file << symbol << "\n";
  file << startSymbolId_ << "\n";
  file << productionRules_.size() << "\n";
  for (auto pr : productionRules_)
    file << pr << "\n";
  file.close();
}

int Grammar::getNProductions(Symbol paramSymbol) {
  assert(nonTerminalSymbol_.count(paramSymbol) != 0);
  int count = 0;
  for (auto production : productionRules_) {
    if (paramSymbol == production.getNonFinalSymbol())
      count++;
  }
  return count;
}

void Grammar::writeTypes() {
  for (auto pr : productionRules_) {
    std::cout << pr;
    switch (pr.getType(nonTerminalSymbol_)) {
    case -1:
      std::cout << " : No regular." << std::endl;
      break;
    case 0:
      std::cout << " : Regular ambos lados." << std::endl;
      break;
    case 1:
      std::cout << " : Regular por la izquierda." << std::endl;
      break;

    case 2:
      std::cout << " : Regular por la derecha." << std::endl;
      break;

    default:
      break;
    }
  }
}

void Grammar::operator=(const Grammar &paramGrammar) {
  terminalSymbol_ = paramGrammar.terminalSymbol_;
  nonTerminalSymbol_ = paramGrammar.nonTerminalSymbol_;
  startSymbolId_ = paramGrammar.startSymbolId_;
  productionRules_ = paramGrammar.productionRules_;
}

/**
 * @brief Sobrecarga del operador de escritura
 *
 * @param os
 * @param paramFTransition
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Grammar &paramGrammar) {
  std::cout << "Simbolo de arranque: " << paramGrammar.startSymbolId_
            << std::endl;

  for (auto symbol : paramGrammar.nonTerminalSymbol_) {
    int productionsNumber = paramGrammar.getNProductions(symbol);
    if (productionsNumber > 0) {
      os << symbol << " -> ";
      int iterator = 0;
      for (auto production : paramGrammar.productionRules_) {
        if (production.getNonFinalSymbol() == symbol) {
          for (auto vectorSymbol : production.getSymbolVector())
            os << vectorSymbol;
          if ((productionsNumber - 1) > iterator)
            os << " | ";
          iterator++;
        }
      }
      os << "\n";
    }
  }
  return os;
}

/**
 * @brief Funcion auxiliar, que dada una cadena, normalmente, devuelve un
 * vector de cadenas que elimina los espacios
 *
 * @param str Cadena a partir
 * @param pattern Caracter a eliminar
 * @return std::vector<std::string> Vector de cadenas
 */
std::vector<std::string> SplitChainGrammar(std::string str, char pattern) {

  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }
  return results;
}