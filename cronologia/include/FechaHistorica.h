/**
  * @file FechaHistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */

#ifndef __FECHA_HISTORICA
#define __FECHA_HISTORICA

#include <iostream>
#include "VectorDinamico.h"

using namespace std;

/**
  *  @brief T.D.A. FechaHistorica
  *
  * Una instancia @e f del tipo de datos abstracto @c FechaHistorica es un
  * objeto compuesto por un @c int y un @c VectorDinamico de tipo @c string
  * de tamaño @e n que representan, respectivamente, un año y un conjunto de 
  * acontecimientos ocurridos en ese año. Lo podemos representar en un archivo 
  * como
  * 
  *  anio`#'hecho1`#'hecho2`#'...,`#'hechon
  * 
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Alejandro Palencia Blanco
  * @author Inmaculada Marín Carballo
  * @date Octubre 2017
  */


class FechaHistorica {

  private:
    /**
      * @page repConjunto Rep del TDA FechaHistorica
      *
      * @section invConjunto Invariante de la representación
      *
      * Una objeto válido @e f del TDA FechaHistorica debe cumplir que 
      * @c anio <= "año actual". Sin embargo, está condición no se comprobará,
      * ya que si establecemos la condición mediante una constante AÑO_ACTUAL, 
      * la clase quedaría obsoleta al cabo de un año. Tampoco se ha establecido
      * una cota inferior, aunque se podría considerar el Big Bang para obtener
      * un valor orientativo, que ocurrió hace 13810 millones de años.
      * 
      *
      * @section faFechaHistorica  Función de abstracción
      *
      * Un objeto válido @e rep del TDA FechaHistorica representa un conjunto 
      * @e hechos de @e n acontecimientos ocurridos en un año @e anio 
      * determinado, entendiendo los valores negativos de este último como años
      * antes de Cristo (a.C.) y el resto como después de Cristo (d.C.)
      * 
      *  anio`#'hechos[0]`#'hechos[1]`#'...,`#'hechos[n-1]
      *
      */

    int anio; /**< Año */
    VectorDinamico<string> hechos; /**< Vector de hechos */

  
  public:
  // ---------------  Constructores ----------------
  /**
    * @brief Constructor por defecto
    * @param a año en el que ocurrieron los hechos (por defecto 0)
    * @note
    *   Este constructor también corresponde al de por defecto
    */
    FechaHistorica(int a=0);

  /**
    * @brief Constructor de la clase
    * @param a año en el que ocurrieron los hechos
    * @return crea una fecha histórica sin ningún hecho asociado
    */
    FechaHistorica(int a);  

  /**
    * @brief Constructor de copia de la clase
    * @param c.anio año en el que ocurrieron los hechos
    * @param c.hechos hechos que ocurrieron en ese año
    */
    FechaHistorica(const Racional & c);  
  
  // -----------------  Destructor ------------------
  /**
    * @brief Destructor de la clase
    */
    ~FechaHistorica();  
  
  // ---------------  Otras funciones ---------------
  /**
    * @brief Devuelve año
    * @return Devuelve el año
    */ 
    int getAnio() const;

  /**
    * @brief Busca la posición del hecho pasado por parámetro
    * @param h hecho a comprobar
    * @return Devuelve la posición si se encuentra un hecho cuya string coincida 
    *   exactamente con la que se pasa por parámetro, -1 en caso contrario.
    */
    int consultar(const string & h) const;

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
    * @brief Añade un nuevo hecho no guardado aún justo detrás del último
    * @param h hecho a añadir
    * @pos Si el hecho ya estaba registrado, no se añade.
    */ 
    void operator+=(const string & h);

  /**
    * @brief Elimina un hecho ya guardado
    * @param h hecho a eliminar
    * @pos Si el hecho no estaba registrado, no se hace ningún cambio.
    */ 
    void operator-=(const string & h);

  /**
    * @brief Salida de una fechaHistorica a ostream
    * @param os stream de salida
    * @param fecha FechaHistorica a escribir
    * @post Se obtiene en \a os la cadena 
    *   anio`#'hechos[0]`#'hechos[1]`#'...,`#'hechos[n-1]
    */
    friend ostream & operator<<(ostream & os, const FechaHistorica & fecha);

  /**
    * @brief Entrada de una FechaHistorica desde istream
    * @param is stream de entrada
    * @param fecha FechaHistorica que recibe el valor
    * @retval La FechaHistorica leído en fecha
    * @pre La entrada tiene el formato 
    *   anio`#'hechos[0]`#'hechos[1]`#'...,`#'hechos[n-1]
    */
    friend istream & operator>>(istream & is, FechaHistorica & fecha);
}






