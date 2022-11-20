/**
 * @file productionRule.cc
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramáticas en Forma Normal de Chomsk
 * @brief Fichero de implementación de la clase ProductionRule.
 * Se define la clase ProductionRule con sus métodos y atributos
 * @version 1.0
 * @date 2022-11-22
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
ProductionRule::ProductionRule(Symbol nonTerminalSymbol, Chain paramChain)
    : nonTerminalSymbol_(nonTerminalSymbol), chain_(paramChain) {}

ProductionRule::ProductionRule(Symbol nonTerminalSymbol, Symbol symbol)
    : nonTerminalSymbol_(nonTerminalSymbol) {
  chain_.AddSymbol(nonTerminalSymbol);
}

/**
 * @brief Destroy the ProductionRule:: ProductionRule object
 *
 */
ProductionRule::~ProductionRule() {}

/**
 * @brief Getter de la cadena de simbolos producidos
 * Objeto constante
 *
 * @return State
 */
Chain ProductionRule::getChain() const { return chain_; }

/**
 * @brief Getter de la cadena de simbolos producidos
 * 
 * @return State
 */
Chain ProductionRule::getChain() { return chain_; }

/**
 * @brief Getter simbolo no terminal de la produccion
 * Objeto constante
 *
 * @return State
 */
Symbol ProductionRule::getNonFinalSymbol() const { return nonTerminalSymbol_; }

/**
 * @brief Getter simbolo no terminal de la produccion
 *
 * @return State
 */
Symbol ProductionRule::getNonFinalSymbol() { return nonTerminalSymbol_; }

/**
 * @brief Retorna el tipo de regularidad de la producción
 * 
 * @param paramNonTerminal Simbolos no terminales de la gramatica
 * @return int: -1 No regular |
 * 0 Regular izquierda y derecha |
 * 1 Regular por la izquierda |
 * 2 Regular por la derecha
 */
int ProductionRule::getType(std::set<Symbol> paramNonTerminal) {
  if (paramNonTerminal.count(chain_.Position(0)) != 0) {
    for (int i = 1; i < chain_.Size(); i++) {
      if ((paramNonTerminal.count(chain_.Position(i)) != 0))
        return -1; // No regular
    }
    return 1; // Regular izquierda
  }
  if (paramNonTerminal.count(chain_.back()) != 0) {
    for (int i = 0; i < chain_.Size() - 1; i++) {
      if (paramNonTerminal.count(chain_.Position(i)) != 0)
        return -1; // No regular
    }
    return 2; // Regular derecha
  }
  for (auto symbol : chain_) {
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
  if (!(nonTerminalSymbol_ == paramProductionRule.getNonFinalSymbol()))
    return (nonTerminalSymbol_ < paramProductionRule.getNonFinalSymbol());
  if (chain_.Size() != paramProductionRule.chain_.Size())
    return (chain_.Size() < paramProductionRule.chain_.Size());
  for (int i = 0; i < chain_.Size() - 1; i++) {
    if (!(chain_.Position(i) == paramProductionRule.chain_.Position(i)))
      return (chain_.Position(i) < paramProductionRule.chain_.Position(i));
  }
  return (chain_.back() < paramProductionRule.chain_.back());
}

/**
 * @brief Sobrecarga operador de asignación
 * 
 * @param paramProduction Produccion a la que va a ser igualada la produccion
 * objeto
 */
void ProductionRule::operator=(const ProductionRule paramProduction) {
  nonTerminalSymbol_ = paramProduction.nonTerminalSymbol_;
  chain_ = paramProduction.chain_;
}

/**
 * @brief Sobrecarga operador de comparador de igualdad
 * 
 * @param paramProduction Produccion con la que se va a comparar la produccion
 * objeto
 */
bool ProductionRule::operator==(
    const ProductionRule paramProductionRule) const {
  if (!(nonTerminalSymbol_ == paramProductionRule.getNonFinalSymbol()))
    return false;
  if (!(chain_ == paramProductionRule.chain_))
    return false;
  return true;
}

/**
 * @brief Sobrecarga operador de escritura
 *
 * @param os
 * @param paramProductionRule
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os,
                         ProductionRule &paramProductionRule) {
  os << paramProductionRule.nonTerminalSymbol_ << " -> ";
  for (auto symbol : paramProductionRule.chain_) {
    os << symbol;
  }
  return os;
}

/**
 * @brief Sobrecarga operador de escritura
 *
 * @param os
 * @param paramProductionRule
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os,
                         const ProductionRule &paramProductionRule) {
  os << paramProductionRule.nonTerminalSymbol_ << " -> ";
  for (auto symbol : paramProductionRule.chain_) {
    os << symbol;
  }
  return os;
}