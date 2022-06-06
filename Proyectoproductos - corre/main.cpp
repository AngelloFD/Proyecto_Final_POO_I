#include<iostream>
#include<vector>
#include<cstring>
#include "vector.h"
#include "prevector.h"
using namespace std;

Productosvector vectorpro;

void menuopcionesadmin();
void insertarpalabras();

int main()
{
	menuopcionesadmin();
}

void menuopcionesadmin()
{
	int numero;
	string rpta;
	cout<<"Bienvenido ADMIN!"<<endl;
	cout<<"/////////////////////////////////////"<<endl;
	cout<<"INSERTAR PRODUCTOS Y PRECIOS 	[1]"<<endl;
	cout<<"MOSTRAR PRODUCTOS ACTUALES	[2] (no implementado)"<<endl;
	cout<<"Ingresa tu numero:"<<endl;
	cin>>numero;
	
	//numero! y switch
	switch (numero)
	{
		case 1:
			insertarpalabras();
			system("cls");
			break;
		case 2:
			cout<<"NO IMPLEMENTADO!"<<endl;
			cout<<"Deseas volver al menu?( SI O NO )"<<endl;
			cin>>rpta;
			if (rpta == "SI")
			{
				system("cls");
				menuopcionesadmin();
			} 
			else
			{
				exit(0);
			}
			break;
		default:
			cout<<"Ingresa numero valido!"<<endl;
			cout<<"Deseas volver al menu?( SI O NO )"<<endl;
			cin>>rpta;
			if (rpta == "SI")
			{
				system("cls");
				menuopcionesadmin();
			} 
			else
			{
				exit(0);
			}
			break;
	}
}
void insertarpalabras()
{
	string producto;
	string rpta;
	int precio;
	system("cls");
	cout<<"ADMIN, agrege los productos"<<endl;
	do
	{
		producto = vectorpro.getCorrelativo();

		cout<<"Ingresa producto: "<<endl;
		cin>>producto;
		cin.ignore();
		cout<<"Ingresar precio: "<<endl;
		cin>>precio;
		
		productos pro;
		
		pro.setproducto(producto);
		pro.setprecio(precio);
		
		vectorpro.add(pro);
		vectorpro.grabarEnArchivo(pro);
		
		cout<<"Desea continuar? // SI O NO // ";
		cin>>rpta;
		system("cls");
	} while(rpta=="SI" || rpta=="si");
	system("cls");
	menuopcionesadmin();
	
}
