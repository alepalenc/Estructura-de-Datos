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
}

//getNfechas()
int getNfechas() const{
	return cronol.getOcupados();
}	

//Comprobar que está vacia
bool Cronologia::vacia() const{
	return cronol == 0;
}


//Buscar un hecho histórico dado su año
int Cronologia::buscarAnio(int a){
	int inf=0, sup=cronol.getNhechos()-1, med=sup/2;
	bool enc=0;
	
	if (inf==sup && cronol[inf].getAnio()==a)	//Caso extremo en el que
		enc=1;					//solamente hay una fecha
	
	while (!enc && inf<sup){
		med=(sup+inf)/2;
		if (cronol[med].getAnio()<a)
			inf=med+1;
		else if(cronol[med].getAnio()>a)
			sup=med-1;
		else
			enc=1;
	}
	
	if (!enc)
		med=-1;
	
	return med;
}


//Insertar
void Cronologia::insertar(const FechaHistorica &fech){
	int a=fech.getAnio();
	int i=0;
	while (cronol[i].getAnio()<a && i<cronol.getOcupados())
		++i;
	if (i<cronol.getOcupados() && cronol[i] == a){
		int nhechos=fech.getNhechos();
		for (int j=0; j<nhechos; ++j)
			cronol[i] += fech[j];
	}else{
		cronol.insertar(fech, i);
	}
}


//Consultar si existe un hecho y en qué anio ocurrió
int Cronologia::consultarHecho(const string & h){
	int pos=-1;
	int n=cronol.getOcupados();
	for (int i=0 ; i<n && pos==-1 ; ++i){
		int m = cronol[i].getNhechos();
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
	int pos = buscarAnio(fech);
	if(pos != -1){
		cronol.eliminar(pos);
	}
}

//BUSCAR EVENTOS
Cronologia Cronologia::buscarEventos(string & h){
		
}

//operador =
Cronologia & Cronologia::operator=(const Cronologia & c){
	 if (this!=&c)
		 cronol = c.cronol;
	return *this;
}

//operador +=
void Cronologia::operator+=(const Cronologia & c){
	int n = c.cronol.getOcupados();	
	for(int i=0; i<n; i++)
		insertar(c.cronol[i],cronol.getOcupados());
}







	/*
	ANTIGUO ALGORITMO DE consultarAnio(), MENOS EFICIENTE
	(ahora está el de búsqueda binaria, borra este si estás de acuerdo)
	
	int pos = -1;
	int n = cronol.getNhechos();
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
	*/
