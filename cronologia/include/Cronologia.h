/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un
////////////////////////////////////
  * objeto compuesto por tres enteros y un string, que representan, 
  * respectivamente, una fecha, un conjunto de acontecimientos ocurridos en 
  * esa fecha, y dos números naturales para administrarlo (número de posiciones
  * ocupadas y número de posiciones reservadas).
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Alejandro Palencia Blanco
  * @author Inmaculada Marín Carballo
  * @date Octubre 2017
  */


class Cronologia {

 private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.reservados>=rep.ocupados>=0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa al valor
  *
  * (rep.cronolog)
  *
  */

  VectorDinamico<FechaHistorica> cronol; /**< cronol */

 public:

/**
  * @brief Constructor por defecto de la clase. Asigna NULL a cronolog 
  */
  Cronologia();
 

/**
  * @brief Destructor de la clase
  */
  ~Cronologia();  

/**
  * @brief Devuelve año
  * @return Devuelve el año
  */ 
  int getAnio() const;

/**
  * @brief Devuelve reservados
  * @return Devuelve el número de posiciones reservadas en el vector
  */ 
  int getReservados() const;

/**
  * @brief Devuelve ocupados
  * @return Devuelve el número de hechos guardados
  */ 
  int getOcupados() const;

/**
  * @brief Comprueba si un hecho ya pertenece al vector hechos
  * @param h hecho a comprobar
  */
  bool consultar(const string & h) const;

/**
  * @brief Comprueba si no hay ningún hecho guardado
  */
  bool vacia() const;

/**
  * @brief Imprime una fecha (año, número de hechos y hechos)
  */
  void print() const;

/**
  * @brief Operador de asignación de la clase
  * @param c.anio año en el que ocurrieron los hechos
  * @param c.hechos hechos que ocurrieron en ese año
  * @param c.numelem número de hechos que ocurrieron ese año
  */
  FechaHistorica & operator=(const FechaHistorica & c);

/**
  * @brief Añade un nuevo hecho no guardado aún
  * @param h hecho a añadir
  */ 
  void operator+=(const string & h);

/**
  * @brief Elimina un hecho ya guardado
  * @param h hecho a eliminar
  */ 
  void operator-=(const string & h);

/**
  * @brief Salida de una fechaHistorica a ostream
  * @param os stream de salida
  * @param fecha FechaHistorica a escribir
  * @post Se obtiene en \a os la cadena anio,hecho1,hecho2,...,hechom con
  *   \e anio el año y \e hechoi el hecho i-ésimo (con i desde 1 hasta m),
  *   todos ellos separados por el carácter '#'
  */
  friend ostream & operator<<(ostream & os, const FechaHistorica & fecha);

/**
  * @brief Entrada de una FechaHistorica desde istream
  * @param is stream de entrada
  * @param fecha FechaHistorica que recibe el valor
  * @retval La FechaHistorica leído en fecha
  * @pre La entrada tiene el formato anio,hecho1,hecho2,...,hechom con
  *   \e anio el año y \e hechoi el hecho i-ésimo (con i desde 1 hasta m),
  *   todos ellos separados por el carácter '#'
  */
  friend istream & operator>>(istream & is, FechaHistorica & fecha);
}







