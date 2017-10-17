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
		cronol[i] += fech.hechos;
	}else{
		cronol.insertar(fech, i);
	}
    }
    

//Insertar al principio
void Cronologia::insertarPrincipio(const FechaHistorica &fech){
	insertar(fech, 0);
    }

//Consultar si anio
int Cronologia::consultarAnio(int fech){
	int pos = -1;
	int n = cronol.getOcupados();
	int i=0;
	bool encontrado = false;
	while(i<ocupados && encontrado == false){
		if(cronol[i].anio == fech){
			encontrado = true;
		}else{
			i++;
		}
	}
	if(encontrado == true){
		pos = i;
	}
	return pos;
}


//Consultar si existe un hecho y en que anio ocurrió
int Cronologia::consultarHecho(const string & h){
	int pos=-1;
	int n=cronol.getOcupados();
	for()
	
	for (int i=0 ; i<n && pos==-1 ; ++i){
		int m = cronol[i].hechos.getOcupados();
		for(int j=0; j<m && pos==-1; ++j){
			if (h==cronol[i].hechos[j])
				pos=i;
		}
	}
		
	return pos;
}
		

//Eliminar
void Cronologia::eliminar(int pos){
	cronol.eliminar(pos);
}

//Eliminar anio en concreto
void Cronologia::eliminarFecha(int fech){
	int pos = consultarAnio(fech);
	if(pos != -1){
		cronol.eliminar(pos);
	}
}	

//Comprobar que está vacia
bool Cronologia::vacia() const{
	return cronol == 0;
}



