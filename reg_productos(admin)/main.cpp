#include <iostream>
#include <vector>
#include <cstring>
#include "vector.h"
#include "prevector.h"
using namespace std;

Productosvector vectorpro;

void menuopcionesadmin();
void insertarpalabras();
void listarproductos();

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
	cout<<"MOSTRAR PRODUCTOS ACTUALES	[2]"<<endl;
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
			system("cls");
			listarproductos();
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
	int codigo;
	int precio;
	system("cls");
	cout<<"ADMIN, agrege los productos"<<endl;
	do
	{
		codigo = vectorpro.getCorrelativo();
		cin.ignore();
		cout<<"(Ranura "<<codigo<<") Ingresa producto: "<<endl;
		cin>>producto;
		cin.ignore();
		cout<<"Ingresar precio: "<<endl;
		cin>>precio;
		
		productos pro;
		
		pro.setcodigo(codigo);
		pro.setproducto(producto);
		pro.setprecio(precio);
		
		vectorpro.add(pro);
		vectorpro.grabarEnArchivo(pro);
		
		cout<<"Desea continuar? // SI O NO // ";
		cin>>rpta;
		system("cls");
		cout<<"Usted ha insertado "<<pro.getproducto()<<", con un precio de: "<<pro.getprecio()<<", en la ranura: "<<vectorpro.getCorrelativo()-1<<endl; 
	} while(rpta=="SI" || rpta=="si");
	system("cls");
	menuopcionesadmin();
	
}

void listarproductos()
{
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<" - "<<" Producto: "<<vectorpro.get(i).getproducto()<<" - "<<" Precio: S/."<<vectorpro.get(i).getprecio()<<endl;	
	}
	system("pause");
	system("cls");
 }
