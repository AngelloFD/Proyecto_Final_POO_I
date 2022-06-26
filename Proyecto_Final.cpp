#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include "vector.h"
#include "prevector.h"

using namespace std;
using std::stoi;

//globales - DE PRODUCTOS
float ptotal;
//objectos y vectores de ayuda - DE PRODUCTOS
Productosvector vectorpro;

//prototipar - DE PRODUCTOS
//menus - DE PRODUCTOS 
void menuopcionesadmin();
//admin - DE PRODUCTOS
void insertarpalabras();
void listarproductos();
void eliminarproductos();
void modificarproductos();

/*
#########################################################################
-------------------------INICIO DE PRODUCTOS-----------------------------
#########################################################################
*/

void menuopcionesadmin() //MENU - PRODUCTOS
{
	int numero;
	string rpta;
	cout<<"Bienvenido ADMIN!"<<endl;
	cout<<"/////////////////////////////////////"<<endl;
	cout<<"INSERTAR PRODUCTOS Y PRECIOS 	[1]"<<endl;
	cout<<"MOSTRAR PRODUCTOS ACTUALES	[2]"<<endl;
	cout<<"ELIMINAR PRODUCTOS		[3]"<<endl;
	cout<<"MODIFICAR PRODUCTOS		[4]"<<endl;
	cout<<"MENU NORMAL			[5]"<<endl;
	cout<<"Ingresa tu numero:"<<endl;
	cin>>numero;
	
	//numero y switch
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
		case 3:
			system("cls");
			eliminarproductos();
			break;
		case 4:
			system("cls");
			modificarproductos();
			break;
		case 5:
			system("cls");
			modificarproductos();
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


void insertarpalabras()  // PRODUCTOS - INSERTA PALABRAS A PRODUCTOS.CSV
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

void listarproductos() // CARGA PRODUCTOS DE PRODUCTOS.CSV
{
	string salir;
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<" - "<<" Producto: "<<vectorpro.get(i).getproducto()<<" - "<<" Precio: S/."<<vectorpro.get(i).getprecio()<<endl;	
	}
	cout<<"Escriba SALIR para regresar: "<<endl;
	cin>>salir;
	if (salir != "SALIR")
	{
		system("cls");
		listarproductos();
	} else {
		system("cls");
		menuopcionesadmin();
	}
 }

void eliminarproductos() // La funcion para restar codigos no sirve - ELIMINA ALGO DE PRODUCTOS.CSV (CAUSA BUGS) (TO-DO Funcion para restar codigos y mover de espacios por -1)
{
	productos pro;
	int codigo;
	int codmf;
	string rpta;
	//listando primero
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<" - "<<" Producto: "<<vectorpro.get(i).getproducto()<<" - "<<" Precio: S/."<<vectorpro.get(i).getprecio()<<endl;	
	}
	//
	cout<<"Ingrese el codigo de el que quiere eliminar"<<endl;
	cin>>codigo;
	productos objAEliminar = vectorpro.busquedaBinaria(codigo);
	cout<<"Desea eliminarlo(SI/NO) o quieres volver(ATRAS)? (SI/NO/ATRAS)"<<endl;
	cin>>rpta;
	
	
	//comprueba si o no
	
	if ( rpta == "ATRAS" )
	{
		system("cls");
		menuopcionesadmin();
	} else if (rpta != "SI"){
		cout<<"SI O NO O ATRAS"<<endl;;
		eliminarproductos();
	} else {
		cout<<"ELIMINADO!"<<endl;
		vectorpro.eliminar(objAEliminar);
		vectorpro.grabarModificarEliminarArchivo(pro);
		/*
		int i = vectorpro.rows();
		do
		{
			cout<<"Actual: "<<vectorpro.get(codigo).getcodigo()<<endl;
			codmf = (vectorpro.get(codigo).getcodigo());
			productos objAModificar = vectorpro.busquedaBinaria(codigo);
			bool estado = vectorpro.modificarcodigo(objAModificar, codmf);
			if(estado = true)
			{
				cout<<"Soy mayor que: "<<codigo<<endl;
				vectorpro.grabarModificarEliminarArchivo(pro);
				cout<<"Mi nuevo codigo es: "<<vectorpro.get(i-1).getcodigo()<<endl;
				vectorpro.grabarModificarEliminarArchivo(pro);
			}
			else
			{
				cout<<"ALGO FALLO";
			}
			codigo++;
		} while(i<=codigo);
		*/
	
		vectorpro.grabarModificarEliminarArchivo(pro);

		menuopcionesadmin();
	}
}

void modificarproductos() // MODIFICA EN PRODUCTOS.CSV
{
	productos pro;
	int cod;
	//listando primero
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<" - "<<" Producto: "<<vectorpro.get(i).getproducto()<<" - "<<" Precio: S/."<<vectorpro.get(i).getprecio()<<endl;	
	}
	//
	cout<<"Ingresar el codigo a modificar:"<<endl;	
	cin>>cod;
	productos objAModificar = vectorpro.busquedaBinaria(cod);	 // usando busqueda binaria y asignando a objecto
	
	cout<<"Registro Encontrado\n";
	cout<<"Codigo: "<<objAModificar.getcodigo()<<endl;
	cout<<"Producto:"<<objAModificar.getproducto()<<endl;
	cout<<"Precio: S/. "<<objAModificar.getprecio()<<endl;
	cin.ignore();
	
	string proModificado;
	float preModificado;
	cout<<"////////////////////////////////////////////////////////////////"<<endl;
	cout<<"Modifica el Producto: "<<endl;
	cin>>proModificado;
	cout<<"Modifica el Precio: "<<endl;
	cin>>preModificado;

	bool estado = vectorpro.modificar(objAModificar,proModificado,preModificado);	 //pasando a vector.h
	if(estado = true)
	{
		cout<<"GRABADO!"<<endl;;
		vectorpro.grabarModificarEliminarArchivo(pro);
		system("pause");
		system("cls");
		menuopcionesadmin();
	}
	else
	{
		cout<<"ALGO FALLO";
		system("pause");
		menuopcionesadmin();
	}
	system("pause");
	system("cls");
}

/*
#########################################################################
-------------------------FIN DE PRODUCTOS-----------------------------
#########################################################################
*/

int main()
{
	menuopcionesadmin();
}