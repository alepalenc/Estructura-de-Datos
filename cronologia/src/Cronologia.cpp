#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Cronologia.h"
#include <string>

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
int Cronologia::getNfechas() const{
	return cronol.getOcupados();
}

//Devuelve el año deuna fecha dada su posoición
int Cronologia::getAnio(int pos) const{
	assert(0<=pos && pos<getNfechas());
	return cronol[pos].getAnio;
}

//Operador []
FechaHistorica & Cronologia::operator[] (int i){
	assert(0<=i && i<getNfechas());
	return cronol[i];
}

//Operador [] constante
const FechaHistorica & Cronologia::operator[](int i) const{
	assert(0<=i && i<getNfechas());
	return cronol[i];
}

//Comprobar que está vacia
bool Cronologia::vacia() const{
	return cronol.getOcupados() == 0;
}

//Numero de fechas historicas contenidas PASAR AL H
int Cronologia::getNFechas() const{
	return cronol.getOcupados();
}



//Buscar la posición de una fecha dado su año
int Cronologia::buscarAnio(int a) const{
	int inf=0, sup=cronol.getNhechos()-1;
	int med=sup/2;
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


//Buscar la posición de la fecha en la que está ubicado un hecho
int Cronologia::buscarHecho(const string & h) const{
	int pos=-1;
	int n=cronol.getOcupados();
	for (int i=0 ; i<n && pos==-1 ; ++i){
		int m = cronol[i].getNhechos();
		for(int j=0; j<m && pos==-1; ++j){
			if (h==cronol[i][j])
				pos=i;
		}
	}
		
	return pos;
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
		cronol.insertar(fech, i);	//método insertar del VectorDinamico
	}
}

		

//Eliminar fecha por posición
void Cronologia::eliminarPorPos(int pos){
	cronol.eliminar(pos);
}

//Eliminar fecha por anio
void Cronologia::eliminarPorAnio(int a){
	int pos = buscarAnio(a);
	if(pos != -1){
		cronol.eliminar(pos);
	}
}

//operador =
Cronologia & Cronologia::operator=(const Cronologia & c){
	 if (this!=&c)
		 cronol = c.cronol;
	return *this;
}

//Buscar eventos que contengan una cadena y generar una sub-cronología con ellos
Cronologia Cronologia::buscarEventos(string & h){
	n = cronol.getOcupados();
	Cronologia aux;
	for(i=; i<n; ++i){
		m = cronol[i].getNhechos();
		ani = cronol[i].getAnio();
		for(j=0;j<m;++j)}{
			FechaHistorica fech(ani);
			if(strpos(cronol[i][j], h) !== false){
				fech += cronol[i][j];
			}
			if(!fech.vacio()){
				aux.insertar(fech);
			}
		}
	}
	return aux;
}

//ESTE MÉTODO ES EL MISMO QUE buscarEventos, ME GUSTARÍA SUSTITUIRLO

//Buscar eventos que contengan una cadena y generar una sub-cronología con ellos
Cronologia & Cronologia::crearSubcronologia(string & h, Cronologia & sub) const{
	n = cronol.getOcupados();		
	sub.cronol.resize(0);			
	for(i=0; i<n; ++i){
		m = cronol[i].getNhechos();
		ani = cronol[i].getAnio();
		for(j=0;j<m;++j)}{
			FechaHistorica fech(ani);
			if(cronol[i][j].find(h)!=string::npos)
				fech += cronol[i][j];
		}
		if(!fech.vacio()){
			sub.insertar(fech);
		}
	}
	return sub;
}

//Unión
void Cronologia::union(const & Cronologia c1, const & Cronologia c2){
	cronol.resize(0);
	int n1=c1.getNfechas(), n2=c2.getNfechas();
	for (int i=0; i<n1; ++i)
		insertar(c1[i]);
	for (int i=0; i<n2; ++i)
		insertar(c2[i]);
}

//Intersección
void Cronologia::interseccion(const & Cronologia c1, const & Cronologia c2){
	cronol.resize(0);
	int n1=c1.getNfechas(), n2=c2.getNfechas(), i=0, j=0;
	while (i==n1 && c1[i].getAnio()<c2[j].getAnio() || j==n2 && c2[j].getAnio()<c1[i].getAnio()){
		if (c1[i].getAnio()<c2[j].getAnio())
			++i;
		else if (c1[i].getAnio()>c2[j].getAnio())
			++j;
		else{
			int m1=c1[i].getNhechos(), m2=c2[j].getNhechos();
			FechaHistorica aux(c1[i].getAnio());
			for (int k=0; k<m1; ++k)
				for (int l=0; l<m1; ++l)
					if (c1[i][k]==c2[j][l])
						aux+=c1[i][k];
			if (!aux.vacio())
				insertar(aux);
		}
	}
}


//operador +=
void Cronologia::operator+=(const Cronologia & c){
	int n = c.cronol.getOcupados();	
	for(int i=0; i<n; i++)
		insertar(c.cronol[i],cronol.getOcupados());	//método insertar del VectorDinamico
}

//Operador <<
ostream & operator<<(ostream & os, const Cronologia & cron){
	n=cron.
}





	/*
	ANTIGUO ALGORITMO DE consultarAnio(), MENOS EFICIENTE
	(ahora está el de búsqueda binaria, borra este si estás de acuerdo)
	
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
	*/
