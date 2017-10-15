#include <iostream>
#include <cassert>
#include <cstdlib>
#include "FechaHistorica.h"

using namespace std;


//Constructor por defecto
FechaHistorica::FechaHistorica(): anio(a), hechos(){}


//Constructor de copia
FechaHistorica::FechaHistorica(const FechaHistorica & c): 
  anio(c.anio), hechos(c.hechos){}


//Destructor
FechaHistorica::~FechaHistorica(){}


//getAnio
int FechaHistorica::getAnio() const{
  return anio;
}


//Consultar
int FechaHistorica::consultar(const string & h) const{
  int pos=-1;
  int n=hechos.getOcupados();
  for (int i=0 ; i<n && pos==-1 ; ++i)
    if (h==hechos[i])
      pos=i;
  return pos;
}


//Print
void FechaHistorica::print() const{
  cout << anio << endl;
  int n=hechos.getOcupados();
  for (int i=0 ; i<n ; ++i)
    cout << hechos[i] << endl;
}


//Operador =
FechaHistorica & FechaHistorica::operator=(const FechaHistorica & c){
  if (this!=&c){
    anio=c.anio;
    hechos=c.hechos;
  }
  
  return *this;
}


//Operador +=
void FechaHistorica::operator+=(const string & h){
  if (consultar(h)==-1)
    hechos.insertar(h);
}


//Operador -=
void FechaHistorica::operator-=(const string & h){
  pos=consultar(h);
  if (pos!=-1)
    hechos.eliminar(pos);
}


//Operador <<
ostream & operator<<(ostream & os, const FechaHistorica & fecha){
  os << anio;
  n=fecha.hechos.getOcupados();
  for (int i=0 ; i<n ; ++i)
    os << '#' << fecha.hechos[i];
  
  return os;
}


//Operador >>
istream & operator>>(istream & is, FechaHistorica & fecha){
  if (!fecha.hechos.vacia())
    fecha.hechos.resize(0);
  
  string aux1, aux2;
  getline(is, aux1, '\n');    //Leo la cadena entera y la guardo en aux1
  
  aux2=strtok(aux1,"#");      //Obtengo el valor de fecha.anio
  fecha.anio=atoi(aux2);
  
  while(aux2!=NULL)           //Obtengo los valores de cada hecho
    fecha+=strtok(NULL,"#");
  
  return is;
}



