#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Cronologia.h"

using namespace std;


//Constructor por defecto
Cronologia::Cronologia(){
  cronol = 0;
} 

//Constructor copia
Cronologia::Cronologia(const Cronologia & c){
   cronol=c.cronol;
}

//Destructor
Cronologia::~Cronologia(){
  	if (cronolog!=NULL){
    		delete[] cronolog;
	}
}

//Insertar
void Cronologia::insertar(const FechaHistorica &fech){
	int aux =fech.anio;;
	int i=0;
	while(cronol[i].anio<aux)
		i++;
	if(cronol[i] == aux){
		//////////
	}else{
		cronol.insertar(fech, i);
	}
    }
    

//Insertar al principio
void Cronologia::insertarPrincipio(const FechaHistorica &fech){
	insertar(fech, 0);
    }

//Eliminar
void Cronologia::eliminar(int pos){
	cronol.eliminar(pos);
}

//Comprobar que está vacia
bool Cronologia::vacia(){
	return cronol == 0;
}



