/**
 * @file transicion.h
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulación de autómatas finitos
 * @brief Cabecera de la clase TransitionFunction.
 * Se define la clase TransitionFunction con sus métodos y atributos
 * Se ha implementado este objeto para establecer un punto medio entre el 
 * objeto Transition y el objeto Automata. El razonamiento es que me parecia
 * poco modular declarar std::set<Transitions> en Automata ya que este tiene
 * por propiedad el atributo 'funcion de transicion' donde se definen las 
 * transiciones. Además de lo mencionado anteriormente, a la hora de 
 * implementar el metodo para reconocer cadenas en el Automata tenia que crear
 * codigo que podia estar compacto en este clase.
 * @see class Transition
 * @see class Automata
 * @version 1.0
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * @link https://campusingenieriaytecnologia2223.ull.es/mod/resource/view.php?id=5919
 */

#include "transicion.h"

#include <iostream>
#include <set>

class TransitionFunction {

  public:
    // Constructores y destructores
    TransitionFunction();
    ~TransitionFunction();

    // Getters y setters
    int getSize();
    //State getState(State, Symbol);
    std::set<State> getStatesSet(State, Symbol);

    // Operaciones
    void addTransition(Transition);
    bool isTransition(State, Symbol);

    // Sobrecarga de operadores
    friend std::ostream &operator<<(std::ostream &, TransitionFunction &);

  private:
    std::set<Transition> transitionSet_;
};