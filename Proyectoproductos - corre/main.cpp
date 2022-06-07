#include<iostream>
#include<vector>
#include<cstring>
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
		cout<<"(ROWS TIENE QUE CARGAR EL ARCHIVO ACTUAL //soy tonto, me olvide poner la funcion para cargar)"vectorpro.rows()<<endl;
		codigo = vectorpro.getCorrelativo();
		cin.ignore();
		cout<<codigo<<" Ingresa producto: "<<endl;
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
	} while(rpta=="SI" || rpta=="si");
	system("cls");
	menuopcionesadmin();
	
}

void listarproductos()
{
	vectorpro.	
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<"-"<<" Producto: "<<vectorpro.get(i).getproducto()<<"-"<<" Precio: "<<vectorpro.get(i).getprecio()<<endl;	
	}
	system("pause");
	system("cls");
}
