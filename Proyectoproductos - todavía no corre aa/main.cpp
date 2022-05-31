#include<iostream>
#include<vector>
#include<cstring>
#include "vector.h"
using namespace std;

Productosvector vectorpro;

void menuopciones();
void insertarpalabras();

int main()
{
	// falta menu
	insertarpalabras();
}

void insertarpalabras()
{
	string producto;
	string rpta;
	int precio;
	
	do
	{
		producto = vectorpro.getCorrelativo();

		cout<<"Nombre("<<producto<<")"<<endl;
		cin.ignore();
		cout<<"Ingresar Nombre:";
		cin>>precio;
		
		productos pro;
		
		pro.setproducto(producto);
		pro.setprecio(precio);
		
		vectorpro.add(pro);
		vectorpro.grabarEnArchivo(pro);
		
		cout<<"SI O NO";
		cin>>rpta;
		system("cls");
	} while(rpta=="SI" || rpta=="si");
	
}
