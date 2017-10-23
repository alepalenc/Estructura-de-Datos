/**
  * @file VectorDinamico.h
  * @brief Fichero cabecera del TDA VectorDinamico
  *
  * Se crea un vector con capacidad de crecer y decrecer
  * 
  */
#ifndef __VECTOR_DINAMICO
#define __VECTOR_DINAMICO


/**
 *  @brief T.D.A. VectorDinamico
 *
 *
 * Una instancia @e v del tipo de datos abstracto @c VectorDinamico sobre el
 * tipo @c T es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petición del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]} 
 *
 * donde v[i] es el valor almacenado en la posición i del vector
 *
 * La eficiencia en espacio es @e O(n).
 */
template <class T>
class VectorDinamico {
  private:
    /**
      * @page repVectorDinamico Rep del TDA VectorDinamico
      *
      * @section invVectorDinamico Invariante de la representación
      *
      * Un objeto válido @e v del TDA VectorDinamico debe cumplir 
      * - @c v.ocupados >= 0
      * - @c v.nelementos >= @c v.ocupados
      * - @c v.datos apunta a una zona de memoria con capacidad para albergar
      *   @c v.nelementos valores de tipo @c T
      *
      * @section faVectorDinamico  Función de abstracción
      *
      * Un objeto válido @e rep del TDA VectorDinamico representa al vector de
      * tamaño @e nelementos, de los cuales @e ocupados elementos están en uso
      *
      * {v.datos[0],v.datos[1],...,v.datos[ocupados-1],...,v.datos[v.nelementos-1]}
      *
      */
    T * datos; /**< Apunta a los elementos del vector */
    int nelementos; /**< Indica el número de elementos en @c datos */
		int ocupados; /**< Indica el número de elementos en uso en @c datos */
  
  
  public:
  // ---------------  Constructores ----------------
  /**
    * @brief Constructor por defecto
    * @param n indica el número de componentes inicial reservadas
    *   para el vector
    * @note
    *   Este constructor también corresponde al de por defecto
    */
    VectorDinamico(int n=0);
  
  /**
    * @brief Constructor de copia
    * @param c.datos vector de datos
    * @param c.nelementos número de componentes inicial reservadas
    *   para el vector
    * @param c.ocupados número de componentes inicial ocupadas
    *   en el vector  
    */
    VectorDinamico(const VectorDinamico<T> & original);

  // ------------------ Destructor ------------------
    ~VectorDinamico();

  // --------------- Otras funciones ---------------
  /**
    * @brief Número de componentes del vector
    * @return Devuelve el número de componentes que puede almacenar en este
    * instante el vector
    * @see resize()
    */
    int getNelementos() const;

	/**
    * @brief Número de componentes en uso del vector
    * @return Devuelve el número de componentes que están usándose en este
    * instante en el vector
    */
    int getOcupados() const;
  
  /**
    * @brief Comprueba si el vector está vacío
    */
    bool vacio() const;
  
  /**
    * @brief Comprueba si el vector está lleno
    */
    bool lleno() const;

  /**
    * @brief Acceso a un elemento de un vector
    * @param i la posición del vector donde está el componente
    * @pre 0<=i<getOcupados()
    * @return La referencia al elemento. Por tanto, se puede usar para almacenar
    *     un valor en esa posición.
    */
    T & operator[] (int i);

  /**
    * @brief Acceso a un elemento de un vector constante
    * @param i la posición del vector donde está el componente
    * @pre 0<=i<getOcupados()
    * @return La referencia al elemento. Se supone que el vector no se puede
        modificar y por tanto es acceso de sólo lectura
    */
    const T & operator[](int i) const;

  /**
    * @brief Redimensión del vector
    * @param n El nuevo tamaño del vector. n>=0
    * @post Los valores almacenados antes de la redimensión no se pierden
    *  (excepto los que se salen del nuevo rango de índices)
    */
    void resize(int n);
    
  /**
    * @brief Operador de asignación
    * @param c.datos vector de datos
    * @param c.nelementos número de componentes inicial reservadas
    *   para el vector
    * @param c.ocupados número de componentes inicial ocupadas
    *   en el vector  
    */
    VectorDinamico & operator=(const VectorDinamico<T> & original);
  
  /**
    * @brief Añade un nuevo elemento
    * @param nuevo el nuevo elemento a añadir
    * @param i la posición en la que se va a añadir el nuevo elemento 
    *   (por defecto justo al principio)
    * @pre 0<=i<=getOcupados()
    */ 
    void insertar(const T & nuevo, int i=0);

  /**
    * @brief Elimina un elemento
    * @param i la posición del elemento que se va a eliminar
    *   (por defecto el primero)
    * @pre 0<=i<getOcupados()
    */ 
    void eliminar(int i=0);
};

#include "VectorDinamico.cpp"
#endif /* __VECTOR_DINAMICO */
