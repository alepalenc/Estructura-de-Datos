/**
  * @file Vectordinamico.cpp
  * @brief Implementación del TDA VectorDinamico
  *
  */
#include <cassert>


/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::VectorDinamico(int n) 
{
  assert(n>=0);
  if (n>0)
    datos=new T[n];
  else
    datos=0;
  nelementos=n;
  ocupados=0;
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico<T> & original) 
{
  nelementos=original.nelementos;
	ocupados=original.ocupados;
  if (ocupados>0) {
    datos=new T[nelementos];
    for (int i=0; i<ocupados; ++i)
      datos[i]=original.datos[i];
  }
  else
    datos=0;
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T>::~VectorDinamico() 
{
  if (nelementos>0) delete[] datos;
}
/* _________________________________________________________________________ */

template <class T>
int VectorDinamico<T>::getNelementos() const 
{ 
  return nelementos; 
}
/* _________________________________________________________________________ */

template <class T>
int VectorDinamico<T>::getOcupados() const 
{ 
  return ocupados; 
}
/* _________________________________________________________________________ */

template <class T>
bool VectorDinamico<T>::vacio() const
{
  return ocupados==0;
}
/* _________________________________________________________________________ */

template <class T>
bool VectorDinamico<T>::lleno() const{
  return ocupados==nelementos;
}
/* _________________________________________________________________________ */

template <class T>
T & VectorDinamico<T>::operator[](int i)
{
  assert (0<=i && i<ocupados);
  return datos[i];
}
/* _________________________________________________________________________ */

template <class T>
const T & VectorDinamico<T>::operator[](int i) const 
{
  assert (0<=i && i<ocupados);
  return datos[i];
}
/* _________________________________________________________________________ */

template <class T>
void VectorDinamico<T>::resize(int n){
  assert(n>=0);
  if (n!=nelementos){
    if (n!=0){
      T* nuevos_datos=new T[n];
      if (ocupados>0){
        if (ocupados>n)
          ocupados=n;
        for (int i=0 ; i<ocupados ; ++i)
          nuevos_datos[i]=datos[i];
        delete[] datos;
      }
      nelementos=n;
      datos=nuevos_datos;
    }
    else{
      if (nelementos>0)
        delete[] datos;
      datos=0;
      nelementos=0;
      ocupados=0;
    }
  }
}
/* _________________________________________________________________________ */

template <class T>
VectorDinamico<T> & VectorDinamico<T>::operator=(const VectorDinamico<T> & original) 
{
  if (this!= &original) {
    if (nelementos>0) 
			delete[] datos;
    nelementos=original.nelementos;
    ocupados=original.ocupados;
		if (nelementos>0){
    	datos=new T[nelementos];
    	for (int i=0; i<nelementos;++i)
      	datos[i]=original.datos[i];
		}
		else
			datos=0;
  }
  return *this;
}
/* __________________________________________________________________________ */

template <class T>
void VectorDinamico<T>::insertar(const T & nuevo, int i){
  assert(0<=i && i<=ocupados);
  if (ocupados==nelementos)
    resize(2*nelementos+1);
  for(int j=ocupados; j>i; --j)
    datos[j]=datos[j-1];
  datos[i]=nuevo;
  ++ocupados;
}
/* __________________________________________________________________________ */

template <class T>
void VectorDinamico<T>::eliminar(int i){
  assert(0<=i && i<ocupados);
  for (int j=i; j<ocupados; ++j)
    datos[j]=datos[j+1];
  --ocupados;
  if (ocupados<=nelementos/4)
    resize(nelementos/2);
}
/* __________________________________________________________________________ */





