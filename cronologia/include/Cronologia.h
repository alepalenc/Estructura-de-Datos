/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include "VectorDinamico.h"
#include "FechaHistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un
////////////////////////////////////
  * objeto compuesto por un vector dinamino de FechaHistorica, que representa, 
  * unas fechas con, cada una, un conjunto de acontecimientos ocurridos en 
  * esa fecha.
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
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Cronologia representa al valor
  *
  * (rep.cronol)
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
  * @brief Contructor copia de la clase.
  */ 
  Cronologia(const Cronologia & c);

/**
  * @brief Devuelve el número de fechas almacenadas
  */ 
  int getNfechas() const;

/**
  * @brief Devuelve el año de una FechaHistorica dada su posición
  * @pre 0<=i<getNfechas()
  */ 
  int getAnio(int pos) const;

/**
  * @brief Acceso a un hecho de una Cronologia
  * @param i la posición donde está el fecha
  * @pre 0<=i<getNfechas()
  * @return La referencia a la fecha. Por tanto, se puede usar para almacenar
  *   un hecho en esa posición.
  */
  FechaHistorica & operator[] (int i);

/**
  * @brief Acceso a un hecho de una Cronologia constante
  * @param i la posición donde está el fecha
  * @pre 0<=i<getNfechas()
  * @return La referencia al elemento. Se supone que la Cronologia no se
  *   puede modificar y por tanto es acceso de sólo lectura
  */
  const FechaHistorica & operator[](int i) const;
 
/**
  * @brief Comprueba si no hay ningún hecho guardado
  */
  bool vacia() const;
 
/**
  * @brief Comprueba si un anio ya pertenece al vector cronol
  * @param a anio a comprobar
  * @return Devuelve la posición en que se encuentra ese anio (si no está devuelve -1) 
  */
  int buscarAnio(int a);
 
/**
  * @brief Busca a que anio pertenece el hecho enunciado
  * @param h hecho a comprobar
  * @return Devuelve la posición de la fecha en la que se encuentra ese hecho (si no está devuelve -1) 
  */
  int buscarHecho(const string & h); 
 
/**
  * @brief elimina una fecha de cronol dada su posición
  */ 
  void eliminarPorPos(int pos);
 
 /**
  * @brief elimina una fecha de cronol dado su año
  */ 
  void eliminarPorAnio(int a);


/**
  * @brief Comprueba si un hecho ya pertenece al vector hechos
  * @param h hecho a comprobar
  */
  bool consultar(const string & h) const;
 


/**
  * @brief Imprime una fecha (año, número de hechos y hechos)
  */
  void print() const;

/**
  * @brief Operador de asignación de la clase
  * @param c.cronol vector de fechas
  */
  Cronologia & operator=(const Cronologia & c);

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







