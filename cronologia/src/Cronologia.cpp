#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Cronologia.h"

using namespace std;


//Constructor por defecto
Cronologia::Cronologia(){
  cronolog = NULL;
} 

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

//Insertar
void Cronologia::insertar(const FechaHistorica &fech, int pos){
	if(pos>=0){
		cronol.insertar(fech, pos);
	}
    }
    

//Insertar al principio
void Cronologia::insertarPrincipio(const FechaHistorica &fech){
	insertar(fech, 0);
    }



