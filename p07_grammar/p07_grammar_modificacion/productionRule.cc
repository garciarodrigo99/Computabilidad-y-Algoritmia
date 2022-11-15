/**
 * @file productionRule.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Gramaticas Regulares
 * @brief Fichero de implementación de la clase ProductionRule.
 * Se define la clase ProductionRule con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 */

#include "productionRule.h"

/**
 * @brief Construct a new ProductionRule:: ProductionRule object
 *
 * @param paramOriginState Estado origen
 * @param paramSymbol Simbolo
 * @param paramDestinationState Estado destino
 */
ProductionRule::ProductionRule(Symbol nonTerminalSymbol,
                               std::vector<Symbol> symbolVector)
    : nonTerminalSymbol_(nonTerminalSymbol), symbolVector_(symbolVector) {}

/**
 * @brief Destroy the ProductionRule:: ProductionRule object
 *
 */
ProductionRule::~ProductionRule() {}

/**
 * @brief Getter estado destino
 *
 * @return State
 */
Symbol ProductionRule::getNonFinalSymbol() const { return nonTerminalSymbol_; }

/**
 * @brief Getter estado origen
 *
 * @return State
 */
std::vector<Symbol> ProductionRule::getSymbolVector() const {
  return symbolVector_;
}

int ProductionRule::getType(std::set<Symbol> paramNonTerminal) {
  if (paramNonTerminal.count(symbolVector_.front()) != 0) {
    for (size_t i = 1; i < symbolVector_.size(); i++) {
      if ((paramNonTerminal.count(symbolVector_.at(i)) != 0))
        return -1; // No regular
    }
    return 1; // Regular izquierda
  }
  if (paramNonTerminal.count(symbolVector_.back()) != 0) {
    for (size_t i = 0; i < symbolVector_.size() - 1; i++) {
      if (paramNonTerminal.count(symbolVector_.at(i)) != 0)
        return -1; // No regular
    }
    return 2; // Regular derecha
  }
  for (auto symbol : symbolVector_) {
    if (paramNonTerminal.count(symbol) != 0)
      return -1; // No regular
  }
  return 0; // Ambas
}

/**
 * @brief Sobrecarga operador '<' para poder trabajar clase std::set
 *
 * @param paramAlphabet productionRule candidato a entrar en std::set
 * @return True - La productionRule no se encuentra en el conjunto
 * @return false - La productionRule se encuentra en el conjunto
 * @see std::set
 */
bool ProductionRule::operator<(const ProductionRule paramProductionRule) const {
  // std::cout << "Hola\n";
  if (!(nonTerminalSymbol_ == paramProductionRule.getNonFinalSymbol()))
    return (paramProductionRule.getNonFinalSymbol() < nonTerminalSymbol_);
  return (symbolVector_ != paramProductionRule.symbolVector_);
}

bool ProductionRule::operator==(
    const ProductionRule paramProductionRule) const {
  if (!(nonTerminalSymbol_ == paramProductionRule.getNonFinalSymbol()))
    return false;
  if (symbolVector_ != paramProductionRule.symbolVector_)
    return false;
  return true;
}

/**
 * @brief
 *
 * @param os
 * @param paramProductionRule
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os,
                         ProductionRule &paramProductionRule) {
  os << paramProductionRule.nonTerminalSymbol_ << " -> ";
  for (auto symbol : paramProductionRule.symbolVector_) {
    os << symbol;
  }
  return os;
}

/**
 * @brief
 *
 * @param os
 * @param paramProductionRule
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os,
                         const ProductionRule &paramProductionRule) {
  os << paramProductionRule.nonTerminalSymbol_ << " -> ";
  for (auto symbol : paramProductionRule.symbolVector_) {
    os << symbol;
  }
  return os;
}