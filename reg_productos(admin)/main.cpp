#include <iostream>
#include <vector>
#include <cstring>
#include "vector.h"
#include "prevector.h"
using namespace std;
using std::stoi;

//globales
float ptotal;
//objectos y vectores de ayuda
Productosvector vectorpro;
vector<int> vectorregistro;
vector<int> vectorcantidad;

//prototipar
//menus
void menuopcionesadmin();
void menunormal();
//admin
void insertarpalabras();
void listarproductos();
void eliminarproductos();
void modificarproductos();

//normal
void comprando();
void comprando2();
void pagar();  //necesitos los datos del usuario
void factura();

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
			menunormal();
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

void eliminarproductos() // La funcion para restar codigos no sirve
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

void modificarproductos()
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
// NO ADMINS

void menunormal()
{
	int numero;
	string rpta;
	cout<<"Bienvenido PERSONA!"<<endl;
	cout<<"/////////////////////////////////////"<<endl;
	cout<<"COMPRAR						[1]"<<endl;
	cout<<"LISTA DE LOS PRODUCTOS ACTUALES			[2]"<<endl;
	cout<<"PAGAR						[3] (FALTA DATOS EXTERNOS)"<<endl;
	cout<<"MOSTRAR FACTURA					[4] "<<endl;
	
	cout<<"Ingresa tu numero:"<<endl;
	cin>>numero;
	
	switch (numero)
	{
	case 1:
		system("cls");
		comprando();
		break;
	case 2:
		system("cls");
		listarproductos(); //Necesito dato de admin para que el programa sepa a donde redirigir (default: admin)
		break;
	case 3:
		system("cls");
		pagar();
		break;
	case 4:
		system("cls");
		factura();
		break;
	default:
		cout<<"Ingresa numero valido!"<<endl;
		cout<<"Deseas volver al menu?( SI O NO )"<<endl;
		cin>>rpta;
		if (rpta == "SI")
		{
			system("cls");
			menunormal();
		} 
		else
		{
			exit(0);
		}
		break;
	}
}

void comprando()
{
	
	cout<<"-----------------------LISTA--------------------------"<<endl;
	for ( int i = 0; i<vectorpro.rows(); i++)
	{
		cout<<"Codigo: "<<vectorpro.get(i).getcodigo()<<" - "<<" Producto: "<<vectorpro.get(i).getproducto()<<" - "<<" Precio: S/."<<vectorpro.get(i).getprecio()<<endl;	
	}
	cout<<"------------------------------------------------------"<<endl;
	comprando2();
	
}
void comprando2()
{
	string rpta;
	string rpta2;
	float pxc;
	int cantidad;
	float precio;
	int codigo;
	
	do{
		cout<<"Ingrese el codigo que quiere comprar"<<endl;
		cin>>codigo;
		cout<<"Cuantos?"<<endl;
		cin>>cantidad;
		cout<<"Usted seleccionó: "<<endl;
		cout<<"Producto: "<<vectorpro.get(codigo-1).getproducto()<<" - "<<"S/. "<<vectorpro.get(codigo-1).getprecio()*cantidad<<endl; // listando la lista encontrada
		if (codigo > vectorpro.rows())
		{
			system("cls");
			cout<<"ingrese numero valido"<<endl;
			exit(-1);
		} 
		else
		{
			precio = vectorpro.get(codigo-1).getprecio(); // codigo-1 para hallar la pos correcta
			pxc = precio * cantidad;//cantidad
			ptotal+= pxc;//total
		}
		vectorcantidad.push_back(cantidad);  		//guardando en memoria(vector) lo que seleccionaste
		vectorregistro.push_back(codigo); 			//guardando en memoria(vector) lo que seleccionaste cantidad edition
		cout<<"Desea continuar? (SI O NO)"<<endl;
		cin>>rpta;
	} while(rpta == "SI");
	system("cls");
	cout<<"Presione cualquier letra para ver su factura!"<<endl;
	system ("pause");

	for ( unsigned int i = 0; i<vectorregistro.size();i++)
	{	
		cout<<"Producto: "<<vectorpro.get(vectorregistro[i]-1).getproducto()<<" - "<<"S/. "<<vectorpro.get(vectorregistro[i]-1).getprecio()* vectorcantidad[i]<<endl;
		
	}	
	cout<<"Total = S/. "<<ptotal<<endl;
	cout<<"Desea regresar (SI/NO)?"<<endl;
	cin>>rpta2;
	if (rpta2 != "SI")
	{
		system("cls");
		comprando2();
	} else {
		system("cls");
		menunormal();
	}
	
}

void pagar() // necesito datos de otra parte
{
	cout<<"No implementado! Necesito los datos de otra parte del proyecto"<<endl;
	system("pause");
	system("cls");
	menunormal();
}

void factura()
{
	string salir;
	for ( unsigned int i = 0; i<vectorregistro.size();i++)
	{	
		cout<<"Producto: "<<vectorpro.get(vectorregistro[i]-1).getproducto()<<" - "<<"S/. "<<vectorpro.get(vectorregistro[i]-1).getprecio()* vectorcantidad[i]<<endl;
		
	}	
	cout<<"Total = S/. "<<ptotal<<endl;
	
	cout<<"Escriba SALIR para regresar: "<<endl;
	cin>>salir;
	
	if (salir != "SALIR")
	{
		system("cls");
		factura();
	} else {
		system("cls");
		menunormal();
	}
}

