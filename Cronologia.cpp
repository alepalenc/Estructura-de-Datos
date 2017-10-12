#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Cronologia.h"

using namespace std;


//Constructor por defecto
Cronologia::Cronologia(){
  cronolog = NULL;
  reservados=0;
  ocupados=0;
} 

/**Constructor por reserva
Cronologia::Cronologia(int reservar){
	ocupados=0;
	if(reservar>0)
  		reservados=reservar;
  	else
		reservados=0;
	cronolog= new FechaHistorica[reservados];
} 
*/

//Constructor copia
Cronologia::Cronologia(const Cronologia & c){
  reservados=c.reservados;
  ocupados=c.ocupados;
  cronolog=new FechaHistorica[reservados];
  for (int i=0 ; i<ocupados ; ++i)
    cronolog[i]=c.cronolog[i];
}

//Destructor
Cronologia::~Cronologia(){
  	if (cronolog!=NULL){
    		delete[] cronolog;
	}
}

//Redimensionar
void Cronologia::resize(int n){
  assert(n>=0);
  if (n!=reservados){
    if (n!=0){
      string* nueva_cronolog=new FechaHistorica[n];
      if (ocupados>0){
        if (ocupados>n)
          ocupados=n;
        for (int i=0 ; i<ocupados ; ++i)
          nueva_cronolog[i]=cronolog[i];
        delete[] cronolog;
      }
      reservados=n;
      cronolog=nueva_cronolog;
    }
    else{
      if (reservados>0)
        delete[] cronolog;
      cronolog=0;
      reservados=0;
      ocupados=0;
    }
  }
}

/*
void Cronologia::insertarPrincipio(const FechaHistorica &fech){
        FechaHistorica* aux = new FechaHistorica;
        aux = fech;
        lista = aux;
    }
    
    


/*
Cronologia::Anadir(FechaHistorica & fech){
	if(ocupados+1>=reservados){
		resize(2+ocupados);
	{
	
}
