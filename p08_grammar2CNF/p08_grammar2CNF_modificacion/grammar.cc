/**
 * @file Grammar.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Fichero de implementación de la clase Grammar.
 * Se define la clase Grammar con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-22
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
  // Comprobar mayor que 0
  // Coger solo hasta el primer espacio
  for (int i = 0; i < nTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea.front());
    terminalSymbol_.insert(auxSymbol);
  }

  // Simbolos no terminales
  getline(archivo, linea);
  int nNonTerminalSymbol = stoi(linea);
  // Comprobar mayor que 0
  // Coger solo hasta el primer espacio
  for (int i = 0; i < nNonTerminalSymbol; i++) {
    getline(archivo, linea);
    Symbol auxSymbol(linea);
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
    Chain auxChain;
    if (!((splittedLine.at(2).size() == 1) &&
          (splittedLine.at(2).at(0) == kEmptyChain))) {
      for (size_t i = 2; i < splittedLine.size(); i++) {
        std::string auxString;
        auxString.append(splittedLine.at(i));
        Symbol auxSymbol(auxString);
        auxChain.AddSymbol(auxSymbol);
      }
    }
    ProductionRule auxProductionRule(splittedLine.at(0), auxChain);
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

bool Grammar::checkGrammar() {
  for (auto pr : productionRules_) {
    if (pr.getChain().Size() == 0)
      return false;
    if (pr.getChain().Size() == 1) {
      bool finded = false;
      for (auto symbol : nonTerminalSymbol_) {
        if (pr.getChain().inSymbol(symbol)) {
          finded = true;
          break;
        }
      }
      if (finded)
        return false;
    }
  }
  return true;
}

void Grammar::convertToCNF() {
  /* Comprobar que la gramatica no tiene producciones unitarias
   * Comprobar que la gramatica no tiene producciones vacias menos el de
   * arranque
   */
  // Producciones vacias
  std::set<ProductionRule> toEraseSet;

  // Sustituir simbolos terminales
  //std::set<ProductionRule> toEraseSet;
  for (auto pr : productionRules_) {
    // Longitud de produccion > 1
    if (pr.getChain().Size() > 1) {
      for (int i = 0; i < pr.getChain().Size(); i++) {
        // Simbolo terminal
        if (terminalSymbol_.count(pr.getChain().Position(i)) != 0) {
          toEraseSet.insert(pr); // Enviar produccion para que sea borrada
          // Nombre nueva produccion
          std::string auxString;
          auxString.push_back('C');
          for (auto symbol : pr.getChain().Position(i))
            auxString.push_back(symbol);

          Symbol Cs(auxString);
          // Se inserta el simbolo designado al conjunto de simbolos no
          // terminales
          nonTerminalSymbol_.insert(Cs);
          // Inserto la (nueva) produccion de simbolo terminal al conjunto de
          // producciones
          Chain auxChain(pr.getChain().Position(i));

          ProductionRule terminalSymbolProduction(Cs,auxChain);
          productionRules_.insert(terminalSymbolProduction);

          // Modificar la produccion cambiando simbolo terminal por su
          // produccion
          Chain prChain(pr.getChain());
          prChain.assign(i, Cs);
          ProductionRule correctedProd(pr.getNonFinalSymbol(), prChain);
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
  char initialCharacter = 'D';
  for (auto pr : productionRules_) {
    ProductionRule referenceProduction(pr.getNonFinalSymbol(), pr.getChain());
    int counter = referenceProduction.getChain().Size() - 2;
    bool modified = false;
    while (referenceProduction.getChain().Size() > 2) {
      modified = true;
      toEraseSet.insert(
          referenceProduction); // Enviar referenceProductionoduccion para que
                                // sea borrada
      std::string sustNonTerminalSymbolId{initialCharacter};
      sustNonTerminalSymbolId.append(std::to_string(counter));
      counter--;
      Symbol newNonTerminalSymbol(sustNonTerminalSymbolId);
      nonTerminalSymbol_.insert(newNonTerminalSymbol);
      Chain newProductionChain(referenceProduction.getChain().Position(
          referenceProduction.getChain().Size() - 2));
      newProductionChain.AddSymbol(referenceProduction.getChain().Position(
          referenceProduction.getChain().Size() - 1));
      ProductionRule newProduction(newNonTerminalSymbol, newProductionChain);
      productionRules_.insert(newProduction);
      Chain sustitutionChain;
      for (int i = 0; i < referenceProduction.getChain().Size() - 2; i++)
        sustitutionChain.AddSymbol(pr.getChain().Position(i));
      sustitutionChain.AddSymbol(newNonTerminalSymbol);
      ProductionRule sustitutionProduction(
          referenceProduction.getNonFinalSymbol(), sustitutionChain);
      productionRules_.insert(sustitutionProduction);
      referenceProduction = sustitutionProduction;
    }
    if (modified)
      initialCharacter++;
  }
  // Borrar las producciones obsoletas tras la primera pasada
  for (auto erase : toEraseSet)
    productionRules_.erase(erase);
  toEraseSet.clear(); // Limpiar set
}

Grammar Grammar::getCNFGrammar() {
  Grammar auxGrammar(*this);
  auxGrammar.convertToCNF();
  return auxGrammar;
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
  for (auto pr : productionRules_) {
    file << pr.getNonFinalSymbol() << " -> ";
    for (auto symbol : pr.getChain()) {
      file << symbol << " ";
    }
    file << "\n";
  }
  //file << *this;
  file.close();
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
          os << production.getChain();
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

int Grammar::getNProductions(Symbol paramSymbol) {
  assert(nonTerminalSymbol_.count(paramSymbol) != 0);
  int count = 0;
  for (auto production : productionRules_) {
    if (paramSymbol == production.getNonFinalSymbol())
      count++;
  }
  return count;
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

  while (results.front().size() == 0)
    results.erase(results.begin());
  
  while (results.back().size() == 0)
    results.pop_back();
  return results;
}