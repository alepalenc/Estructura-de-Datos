#include <iostream>
#include <cassert>
#include <cstdlib>
#include "FechaHistorica.h"

using namespace std;


//Constructor por defecto
FechaHistorica::FechaHistorica(int a): anio(a), hechos(0){}


//Constructor de copia
FechaHistorica::FechaHistorica(const FechaHistorica & c): 
  anio(c.anio), hechos(c.hechos){}


//Destructor
FechaHistorica::~FechaHistorica(){}


//setAnio
void FechaHistorica::setAnio(int a){
  anio=a;
}

//getAnio
int FechaHistorica::getAnio() const{
  return anio;
}

//getNhechos
int FechaHistorica::getNhechos() const{
  return hechos.getOcupados();
}

//Operador []
string & FechaHistorica::operator[] (int i){
  assert(0<=i && i<getNhechos());
  return hechos[i];
}

//Operador [] constante
const string & FechaHistorica::operator[](int i) const{
  assert(0<=i && i<getNhechos());
  return hechos[i];
}

//Vacia
bool FechaHistorica::vacio() const{
	return hechos.vacio();
}


//Buscar Hecho
int FechaHistorica::buscarHecho(const string & h) const{
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
  if (buscarHecho(h)==-1)
    hechos.insertar(h, hechos.getOcupados());
}


//Operador -=
void FechaHistorica::operator-=(const string & h){
  int pos=buscarHecho(h);
  if (pos!=-1)
    hechos.eliminar(pos);
}


//Operador <
bool FechaHistorica::operator<(const FechaHistorica & f) const{
  return anio<f.anio;
}


//Operador >
bool FechaHistorica::operator>(const FechaHistorica & f) const{
  return anio>f.anio;
}


//Operador <=
bool FechaHistorica::operator<=(const FechaHistorica & f) const{
  return anio<=f.anio;
}


//Operador >=
bool FechaHistorica::operator>=(const FechaHistorica & f) const{
  return anio>=f.anio;
}


//Operador ==
bool FechaHistorica::operator==(const FechaHistorica & f) const{
  return anio==f.anio;
}


//Operador !=
bool FechaHistorica::operator!=(const FechaHistorica & f) const{
  return anio!=f.anio;
}


//Operador <<
ostream & operator<<(ostream & os, const FechaHistorica & fecha){
  os << fecha.getAnio();
  int n=fecha.getNhechos();
  for (int i=0 ; i<n ; ++i)
    os << '#' << fecha.hechos[i];
  
  return os;
}


//Operador >>
istream & operator>>(istream & is, FechaHistorica & fecha){
  if (!fecha.vacio())
    fecha.hechos.resize(0);
  
  string aux;
  getline(is, aux, '\n');    //Leo la cadena entera y la guardo en aux1
	unsigned int pos=aux.find('#');			//Busco la primera ocurrencia de '#' en aux1
	
	if (pos!=string::npos){
  		int longitud=aux.length();		//Guardo longitud de aux
		fecha.setAnio(stoi(aux.substr(0,pos-1)));		//Tomo la subcadena que va desde el
				//principio de aux hasta el primer '#', la paso a int y la guardo en fecha.anio
		aux=aux.substr(pos+1,longitud);		//Quito de aux la parte a la izquierda del primer '#'
		longitud=aux.length();		//Guardo longitud de aux
		pos=aux.find('#');		//Busco la primera ocurrencia de '#' en aux

		while(pos!=string::npos){
			fecha+=aux.substr(0,pos-1);		//Tomo la subcadena que va desde el
				//principio de aux hasta el primer '#', la paso a int y la guardo en fecha.hechos
			aux=aux.substr(pos+1,longitud);		//Quito de aux la parte a la izquierda del primer '#'
			longitud=aux.length();		//Guardo longitud de aux
			pos=aux.find('#');		//Busco la primera ocurrencia de '#' en aux
		}
		
		fecha+=aux;		//Guardo aux (la parte final del original) en fecha.hechos
	}
	else
		fecha.setAnio(stoi(aux));		//Paso aux a int y la guardo en fecha.anio

  return is;
}
