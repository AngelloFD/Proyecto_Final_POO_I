#pragma once
// librerï¿½as global
#include <iostream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
// headers global
#include "CLIENTES_V.h"
#include "vendedorVector.h"
#include "vector.h"
#include "prevector.h"
#include "VENTAS_VECTOR.h"

using namespace std;
using std::stoi;

// globales - DE PRODUCTOS
float ptotal;
float nuevot;
// objectos y vectores de ayuda - DE PRODUCTOS
Productosvector vectorpro;
vector<int> vectorregistro;
vector<int> vectorcantidad;

// menu - VENTAS
void menunormal();

// normal - VENTAS
void comprando();
void comprando2();
void listandoNOADMIN();
void pagar();
void factura();

// prototipar - clientes
void menu_clientes();
// prototipar - DE PRODUCTOS
// menus - DE PRODUCTOS
void menuopcionesadmin();
// admin - DE PRODUCTOS
void insertarpalabras();
void listarproductos();
void eliminarproductos();
void modificarproductos();
// prototipar - DE VENDEDORES
void tipoDeUsuario();
void inicio();
void inicioAdmin();
void loginUsuario();
void recuperarCuenta();
void menuDeOpciones();
void adicionarVendedores();
void eliminarVendedores();
void modificarVendedores();
void buscarVendedor();
void listarVendedores();
void gotoxy(int, int);

// objectos y vectores de ayuda - DE VENDEDORES
VendedorVector vendedorVector;

CLIENTES_V cliente_vector;

int main()
{
	setlocale(LC_CTYPE, "Spanish"); // idioma ESPAï¿½OL
	tipoDeUsuario();
}
/*
#########################################################################
-------------------------INICIO DE PRODUCTOS-----------------------------
#########################################################################
*/

void menuopcionesadmin() // MENU - PRODUCTOS
{
	int numero;
	string rpta;
	cout << "Bienvenido ADMIN!" << endl;
	cout << "/////////////////////////////////////" << endl;
	cout << "INSERTAR PRODUCTOS Y PRECIOS 	[1]" << endl;
	cout << "MOSTRAR PRODUCTOS ACTUALES	[2]" << endl;
	cout << "ELIMINAR PRODUCTOS		[3]" << endl;
	cout << "MODIFICAR PRODUCTOS		[4]" << endl;
	cout << "MENU VENTAS			[5]" << endl;
	cout << "Ingresa tu numero:" << endl;
	cin >> numero;

	// numero y switch
	switch (numero)
	{
	case 1:
		insertarpalabras();
		system("cls");
		break;
	case 2:
		system("cls");
		if (vectorpro.rows() == 0)
		{
			cout << "No hay productos en el archivo!" << endl;
			system("pause");
			system("cls");
			menuopcionesadmin();
		}
		else
		{
			listarproductos();
		}
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
		cout << "Ingresa numero valido!" << endl;
		cout << "Deseas volver al menu?( SI O NO )" << endl;
		cin >> rpta;
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

void insertarpalabras() // PRODUCTOS - INSERTA PALABRAS A PRODUCTOS.CSV
{
	string producto;
	string rpta;
	int codigo;
	float precio;
	system("cls");
	cout << "ADMIN, agrege los productos" << endl;
	do
	{
		codigo = vectorpro.getCorrelativo();
		cin.ignore();
		cout << "(Ranura " << codigo << ") Ingresa producto: " << endl;
		cin >> producto;
		cin.ignore();
		cout << "Ingresar precio: " << endl;
		cin >> precio;

		productos pro;

		pro.setcodigo(codigo);
		pro.setproducto(producto);
		pro.setprecio(precio);

		vectorpro.add(pro);
		vectorpro.grabarEnArchivo(pro);

		cout << "Desea continuar? // SI O NO // "<<endl;
		cin >> rpta;
		system("cls");
		cout << "Usted ha insertado " << pro.getproducto() << ", con un precio de: " << pro.getprecio() << ", en la ranura: " << vectorpro.getCorrelativo() - 1 << endl;
	} while (rpta == "SI" || rpta == "si");
	system("cls");
	menuopcionesadmin();
}

void listarproductos() // CARGA PRODUCTOS DE PRODUCTOS.CSV
{
	string salir;
	for (int i = 0; i < vectorpro.rows(); i++)
	{
		cout << "Codigo: " << vectorpro.get(i).getcodigo() << " - "
			 << " Producto: " << vectorpro.get(i).getproducto() << " - "
			 << " Precio: S/." << vectorpro.get(i).getprecio() << endl;
	}
	cout << "Escriba SALIR para regresar: " << endl;
	cin >> salir;
	if (salir != "SALIR")
	{
		system("cls");
		listarproductos();
	}
	else
	{
		system("cls");
		menuopcionesadmin();
	}
}

void eliminarproductos() // La funcion para restar codigos no sirve - ELIMINA ALGO DE PRODUCTOS.CSV (CAUSA BUGS) (TO-DO Funcion para restar codigos y mover de espacios por -1)
{
	productos pro;
	int codigo;
	string rpta;
	// listando primero
	for (int i = 0; i < vectorpro.rows(); i++)
	{
		cout << "Codigo: " << vectorpro.get(i).getcodigo() << " - "
			 << " Producto: " << vectorpro.get(i).getproducto() << " - "
			 << " Precio: S/." << vectorpro.get(i).getprecio() << endl;
	}
	//
	cout << "Ingrese el codigo de el que quiere eliminar" << endl;
	cin >> codigo;
	productos objAEliminar = vectorpro.busquedaBinaria(codigo);
	cout << "Desea eliminarlo(SI/NO) o quieres volver(ATRAS)? (SI/NO/ATRAS)" << endl;
	cin >> rpta;

	// comprueba si o no

	if (rpta == "ATRAS")
	{
		system("cls");
		menuopcionesadmin();
	}
	else if (rpta != "SI")
	{
		cout << "SI O NO O ATRAS" << endl;
		;
		eliminarproductos();
	}
	else
	{
		cout << "ELIMINADO!" << endl;
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
		system("cls");
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

/*
#########################################################################
-------------------------INICIO DE VENDEDORES-----------------------------
#########################################################################
*/
void tipoDeUsuario()
{
	int rpta;
	string admin;
	string vendedor;
	gotoxy(30, 8);
	cout << "******************** Bienvenido, Cajero ********************" << endl;
	gotoxy(50, 10);
	cout << "[1]. Usuario(VENDEDOR)" << endl;
	gotoxy(50, 12);
	cout << "[2]. Admin" << endl;
	gotoxy(50, 14);
	cout << "Ingresa tu opcion:";
	cin >> rpta;

	switch (rpta)
	{
	case 1:
		system("cls");
		inicio();
		gotoxy(50, 10);
		break;

	case 2:
		system("cls");
		inicioAdmin();
		break;
	}
}

void inicioAdmin()
{
	string cod = "ADMIN";
	string nom = "ADMIN";
	int contador = 0;
	bool ingresa = false;
	int choice;

	do
	{
		system("cls");
		gotoxy(30, 8);
		cout << "******************** Bienvenido, Cajero ********************" << endl;
		gotoxy(50, 10);
		cout << " Ingrese su contrase?a:";
		cin >> cod;
		gotoxy(50, 12);
		cout << " Ingrese su nombre:";
		cin >> nom;

		if (cod == "ADMIN" && nom == "ADMIN")
		{
			ingresa = true;
		}
		else
		{
			cout << "No tienes permiso de administrador" << endl;
			contador++;
			system("pause");
		}
	} while (ingresa == false && contador < 3);

	if (ingresa == false)
	{
		cout << "\nNo puede ingresar al sistema. Nuemero de intentos agotados" << endl;
		system("pause");
		system("cls");
		tipoDeUsuario();
	}
	else
	{
		system("cls");
		gotoxy(50, 10);
		cout << "[1]. Registro Vendedores" << endl;
		gotoxy(50, 12);
		cout << "[2]. Registro Clientes" << endl;
		gotoxy(50, 14);
		cout << "[3] Registro Productos";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			menuDeOpciones();
			break;

		case 2:
			system("cls");
			menu_clientes();
			break;

		case 3:
			system("cls");
			menuopcionesadmin();
			break;
		}
	}
}

void inicio()
{
	int choice;
	//	system("COLOR 80");

	gotoxy(30, 8);
	cout << "******************** Bienvenido, Cajero ********************" << endl;
	gotoxy(50, 10);
	cout << "[1]. Ingresar" << endl;
	gotoxy(50, 12);
	cout << "[2]. Recuperar contrase?a" << endl;
	gotoxy(50, 14);
	cout << "Ingresa tu opcion:";
	cin >> choice;

	switch (choice)
	{
	case 1:
		loginUsuario();
		break;

	case 2:
		recuperarCuenta();
		break;

	default:
		cout << "Ingrese una opcion correcta[1-2]" << endl;
	}
}

void loginUsuario()
{
	system("cls");
	string nom;
	string n[100];
	int cod;
	int c[100];
	int i;
	string rpta;

	gotoxy(30, 6);
	cout << "============================================================" << endl;
	gotoxy(50, 8);
	cout << "Ingrese su contrase?a:";
	cin >> cod;
	cout << endl;
	gotoxy(30, 10);
	cout << "============================================================" << endl;
	gotoxy(50, 12);
	cout << "Ingrese su usuario:";
	cin >> nom;

	ifstream fe("Vendedores.csv", ios::in);

	while (!fe.eof())
	{
		for (i = 0; i < vendedorVector.rows(); i++)
		{
			c[i] = vendedorVector.get(i).getCodigo();

			n[i] = vendedorVector.get(i).getNombre();

			if (cod == c[i] && nom == n[i])
			{
				system("cls");
				gotoxy(30, 6);
				cout << "============================================================" << endl;
				gotoxy(50, 8);
				cout << "Bienvenido, " << nom << endl;
				gotoxy(30, 10);
				cout << "FALTA___________COMPLETAR";
				gotoxy(45, 12);
				system("pause");
				system("cls");

				cout << "COMPLETAR CON CLIENTES O VENTAS" << endl;
				system("pause");
				system("cls");
				tipoDeUsuario(); // REEMPLAZAR PROXIMAMENTE-------
			}
		}
		system("cls");
		menunormal();
	}
}

void recuperarCuenta()
{
	int opcion;
	string nom;
	string n[100];
	int cod;
	int c[100];
	int i;
	system("cls");
	gotoxy(30, 6);
	cout << "======================== Recupera tu cuenta ========================";
	gotoxy(50, 8);
	cout << "[1]. Recuperar por nombre de usuario " << endl;
	gotoxy(50, 10);
	cout << "[2]. Recuperar po contrase?a" << endl;
	gotoxy(50, 12);
	cout << "[3]. Volver al menu" << endl;
	gotoxy(50, 14);
	cout << "Ingresa tu opcion:";
	cin >> opcion;

	ifstream fe("Vendedores.csv", ios::in);
	while (!fe.eof())
	{

		switch (opcion)
		{
		case 1:
			system("cls");
			gotoxy(30, 6);
			cout << "======================== Recupera tu cuenta ========================";
			gotoxy(50, 8);
			cout << "Ingresa tu nombre de usuario:";
			cin >> nom;

			for (i = 0; i < vendedorVector.rows(); i++)
			{
				c[i] = vendedorVector.get(i).getCodigo();

				n[i] = vendedorVector.get(i).getNombre();

				if (nom == n[i])
				{
					gotoxy(50, 10);
					cout << "Se encontr? tu cuenta" << endl;
					gotoxy(45, 12);
					system("pause");
					system("cls");
					gotoxy(30, 6);
					cout << "======================== Recupera tu cuenta ========================";
					gotoxy(50, 8);
					cout << "Tu contrase?a es: " << c[i] << endl;
					gotoxy(45, 10);
					system("pause");
					system("cls");
					tipoDeUsuario();
				}
			}
			gotoxy(50, 10);
			cout << "El usuario no existe" << endl;
			gotoxy(45, 12);
			system("pause");
			system("cls");
			recuperarCuenta();

		case 2:
			system("cls");
			gotoxy(30, 6);
			cout << "======================== Recupera tu cuenta ========================";
			gotoxy(50, 8);
			cout << "Ingresa tu contrase?a:";
			cin >> cod;

			for (i = 0; i < vendedorVector.rows(); i++)
			{
				c[i] = vendedorVector.get(i).getCodigo();

				n[i] = vendedorVector.get(i).getNombre();

				if (cod == c[i])
				{
					gotoxy(50, 10);
					cout << "Se encontr? tu cuenta" << endl;
					gotoxy(45, 12);
					system("pause");
					system("cls");
					gotoxy(30, 6);
					cout << "======================== Recupera tu cuenta ========================";
					gotoxy(50, 8);
					cout << "Tu usuario es: " << n[i] << endl;
					gotoxy(45, 10);
					system("pause");
					system("cls");
					tipoDeUsuario();
				}
			}
			gotoxy(50, 10);
			cout << "El usuario no existe" << endl;
			gotoxy(45, 12);
			system("pause");
			system("cls");
			recuperarCuenta();

		case 3:
			gotoxy(30, 6);
			cout << "======================== Recupera tu cuenta ========================";
			gotoxy(50, 8);
			system("pause");
			system("cls");
			tipoDeUsuario();

		default:
			cout << "Ingrese una opcion correcta[1-3]" << endl;
		}
	}
}

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void menuDeOpciones()
{
	// Declarar Variables
	int opt;
	string rpta;
	do
	{
		gotoxy(30, 6);
		cout << "================== MENU DE REGISTRO DE VENDEDORES ==================\n";
		gotoxy(30, 8);
		cout << "[1].Ingresar Vendedores\n";
		gotoxy(30, 10);
		cout << "[2].Eliminar Vendedores\n";
		gotoxy(30, 12);
		cout << "[3].Modificar Vendedores\n";
		gotoxy(30, 14);
		cout << "[4].Buscar Vendedores\n";
		gotoxy(30, 16);
		cout << "[5].Listar Vendedores\n";
		gotoxy(30, 18);
		cout << "[6].Cerrar sesi?n\n";
		gotoxy(30, 20);
		cout << "[7].Salir\n";
		gotoxy(30, 22);
		cout << "Ingrese una opcion[1-7]:";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			adicionarVendedores();
			break;
		case 2:
			system("cls");
			eliminarVendedores();
			break;
		case 3:
			system("cls");
			modificarVendedores();
			break;
		case 4:
			system("cls");
			buscarVendedor();
			break;
		case 5:
			system("cls");
			listarVendedores();
			break;
		case 6:
			system("cls");
			gotoxy(30, 6);
			cout << "================== MENU DE REGISTRO DE VENDEDORES ==================\n";
			gotoxy(45, 8);
			cout << "?Esta seguro de cerrar sesi?n(SI/si)?:";
			cin >> rpta;
			if (rpta == "SI" || rpta == "si")
			{
				system("cls");
				tipoDeUsuario();
			}
			else
			{
				system("cls");
			}
			break;
			system("cls");
		case 7:
			system("cls");
			gotoxy(30, 6);
			cout << "************************ Vuelve Pronto !!! ************************\n";
			exit(0);
			break;
		default:
			cout << "Ingrese una opcion correcta[1-7]" << endl;
		}
	} while (opt != 7);
}

void adicionarVendedores()
{
	// Crear Variables
	int cod;
	string nom,
		rpta;
	// Crear el Objeto de la clase alumno
	do
	{
		system("cls");
		gotoxy(30, 6);
		cout << "==================== INGRESAR NUEVOS VENDEDORES ====================\n";

		srand(time(0));
		for (int i = 0; i < 1; i++)
		{
			cod = 100000 + (rand() % 999999);
		}
		gotoxy(50, 8);
		cout << "La contrasena generada es:";
		gotoxy(50, 10);
		cout << cod << endl;
		cin.ignore();

		gotoxy(50, 12);
		cout << "Ingresar Nombre:";
		getline(cin, nom);

		Vendedor vendedor; /*Crear el Objeto*/

		vendedor.setCodigo(cod);
		vendedor.setNombre(nom);

		vendedorVector.add(vendedor); // Agregar el Objeto al vector dinamico

		vendedorVector.grabarEnArchivo(vendedor);
		gotoxy(50, 14);
		cout << "Para continuar pulsar(SI o si):";
		cin >> rpta;
		system("cls"); // Limpiar
	} while (rpta == "SI" || rpta == "si");
	tipoDeUsuario();
}

void listarVendedores()
{
	cout << "======================= LISTA DE VENDEDORES =======================\n";
	for (int i = 0; i < vendedorVector.rows(); i++)
	{
		cout << "Codigo:" << vendedorVector.get(i).getCodigo() << "\n";
		cout << "Nombre:" << vendedorVector.get(i).getNombre() << "\n";
	}
	system("pause");
	system("cls");
}

void eliminarVendedores()
{
	int cod;
	gotoxy(30, 6);
	cout << "======================= ELIMINAR VENDEDOR(ES) =======================\n";
	gotoxy(50, 8);
	cout << "Ingresar el codigo del vendedor a eliminar:";
	cin >> cod;

	Vendedor SellerDelete = vendedorVector.buscarPorCodigo(cod);
	vendedorVector.remove(SellerDelete);

	gotoxy(50, 10);
	system("pause");
	gotoxy(40, 12);
	cout << "******** Vendedor Eliminado Satisfactoriamente ********";

	// ACTUALIZAR ARCHIVO
	vendedorVector.grabarModificarEliminarArchivo();
}

void modificarVendedores()
{
	int code;
	gotoxy(30, 6);
	cout << "======================= MODIFICAR VENDEDOR(ES) =======================\n";
	gotoxy(50, 8);
	cout << "Ingresar el codigo del vendedor:";
	cin >> code;

	Vendedor vendModificar = vendedorVector.buscarPorCodigo(code);

	system("pause");
	system("cls");
	gotoxy(30, 6);
	cout << "======================= MODIFICAR VENDEDOR(ES) =======================\n";
	gotoxy(50, 8);
	cout << "**** Registro encontrado ****" << endl;
	gotoxy(50, 10);
	cout << "Codigo:" << vendModificar.getCodigo() << endl;
	gotoxy(50, 12);
	cout << "Nombre:" << vendModificar.getNombre() << endl;
	cin.ignore();
	system("pause");
	string nomModificado;
	cout << endl;
	gotoxy(50, 14);
	cout << "Modificar Vendedor:";
	getline(cin, nomModificado);
	bool estado = vendedorVector.modificar(vendModificar, nomModificado);

	if (estado = true)
	{

		gotoxy(40, 16);
		cout << "**** Registro modificado satisfactoriamente ****";
		// Grabar archivo modificado
		vendedorVector.grabarModificarEliminarArchivo();
	}
	else
	{
		gotoxy(45, 16);
		cout << "**** No se modific? el registro *****";
		gotoxy(40, 18);
		system("pause");
		menuDeOpciones();
	}
	gotoxy(40, 18);
	system("pause");
	system("cls");
}
void buscarVendedor()
{
	int code;
	gotoxy(30, 6);
	cout << "======================= BUSCAR AL VENDEDOR =======================\n";
	gotoxy(30, 8);
	cout << "Ingresar el codigo del vendedor:";
	cin >> code;
	Vendedor vend = vendedorVector.buscarPorCodigo(code);
	gotoxy(30, 10);
	system("pause");
	if (vend.getNombre() != "Error")
	{
		system("cls");
		gotoxy(30, 6);
		cout << "======================= BUSCAR AL VENDEDOR =======================\n";
		gotoxy(30, 8);
		cout << "**** Registro encontrado ****" << endl;
		gotoxy(30, 10);
		cout << "Codigo:" << vend.getCodigo() << endl;
		gotoxy(30, 12);
		cout << "Nombre:" << vend.getNombre() << endl;
	}
	else
	{
		system("cls");
		gotoxy(30, 6);
		cout << "======================= BUSCAR AL VENDEDOR =======================\n";
		gotoxy(30, 8);
		cout << "No se encontro el registro\n";
		gotoxy(30, 10);
		system("pause");
		menuDeOpciones();
	}
	gotoxy(30, 14);
	system("pause");
}

/*
#########################################################################
-------------------------FIN DE VENDEDORES--------------------------------
#########################################################################
*/

/*
#########################################################################
-------------------------INICIO DE VENTAS--------------------------------
#########################################################################
*/

void menunormal()
{
	int numero;
	string rpta;
	cout << "Bienvenido!" << endl;
	cout << "/////////////////////////////////////" << endl;
	cout << "COMPRAR						[1]" << endl;
	cout << "LISTA DE LOS PRODUCTOS ACTUALES			[2]" << endl;
	cout << "PAGAR						[3] " << endl;
	cout << "MOSTRAR FACTURA					[4] " << endl;

	cout << "Ingresa tu numero:" << endl;
	cin >> numero;

	switch (numero)
	{
	case 1:
		system("cls");
		comprando();
		break;
	case 2:
		system("cls");
		listandoNOADMIN(); // Necesito dato de admin para que el programa sepa a donde redirigir (default: admin)
		break;
	case 3:
		system("cls");
		if (vectorregistro.size() == 0)
		{
			cout << "No hay productos en el carrito!" << endl;
			system("pause");
			system("cls");
			menunormal();
		}
		else
		{
			pagar();
		}
		break;
	case 4:
		system("cls");
		if (vectorregistro.size() == 0)
		{
			cout << "No hay productos en el carrito!" << endl;
			system("pause");
			system("cls");
			menunormal();
		}
		else
		{
			factura();
		}
		break;
	default:
		cout << "Ingresa numero valido!" << endl;
		cout << "Deseas volver al menu?( SI O NO )" << endl;
		cin >> rpta;
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

void listandoNOADMIN()
{

	cout << "-----------------------LISTA--------------------------" << endl;
	for (int i = 0; i < vectorpro.rows(); i++)
	{
		cout << "Codigo: " << vectorpro.get(i).getcodigo() << " - "
			 << " Producto: " << vectorpro.get(i).getproducto() << " - "
			 << " Precio: S/." << vectorpro.get(i).getprecio() << endl;
	}
	cout << "------------------------------------------------------" << endl;
	system("pause");
	system("cls");
	menunormal();
}

void comprando()
{

	cout << "-----------------------LISTA--------------------------" << endl;
	for (int i = 0; i < vectorpro.rows(); i++)
	{
		cout << "Codigo: " << vectorpro.get(i).getcodigo() << " - "
			 << " Producto: " << vectorpro.get(i).getproducto() << " - "
			 << " Precio: S/." << vectorpro.get(i).getprecio() << endl;
	}
	cout << "------------------------------------------------------" << endl;
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

	do
	{
		cout << "Ingrese el codigo que quiere comprar" << endl;
		cin >> codigo;
		cout << "Cuantos?" << endl;
		cin >> cantidad;
		cout << "Usted selecciono: " << endl;
		cout << "Producto: " << vectorpro.get(codigo - 1).getproducto() << " - "
			 << "S/. " << vectorpro.get(codigo - 1).getprecio() * cantidad << endl; // listando la lista encontrada SIN BUSQUEDA BINARIA
		if (codigo > vectorpro.rows())
		{
			system("cls");
			cout << "ingrese numero valido" << endl;
			exit(-1);
		}
		else
		{
			precio = vectorpro.get(codigo - 1).getprecio(); // codigo-1 para hallar la pos correcta
			pxc = precio * cantidad;						// cantidad
			ptotal += pxc;									// total
		}
		vectorcantidad.push_back(cantidad); // guardando en memoria(vector) lo que seleccionaste
		vectorregistro.push_back(codigo);	// guardando en memoria(vector) lo que seleccionaste cantidad edition
		cout << "Desea continuar? (SI O NO)" << endl;
		cin >> rpta;
	} while (rpta == "SI");
	system("cls");
	cout << "Presione cualquier letra para ver su factura!" << endl;
	system("pause");

	for (unsigned int i = 0; i < vectorregistro.size(); i++)
	{
		cout << "Producto: " << vectorpro.get(vectorregistro[i] - 1).getproducto() << " - "
			 << "S/. " << vectorpro.get(vectorregistro[i] - 1).getprecio() * vectorcantidad[i] << endl;
	}
	cout << "Total = S/. " << ptotal << endl;
	cout << "Desea regresar (SI/NO)?" << endl;
	cin >> rpta2;
	if (rpta2 != "SI")
	{
		system("cls");
		comprando2();
	}
	else
	{
		system("cls");
		menunormal();
	}
}

void pagar() // necesito datos de otra parte
{
	int rpta;
	cout << "¿Desea pagar con efectivo(1) o Tarjeta Venta+ (2)? "
		 << "\n";
	cout << "Ingrese 1 o 2: "
		 << "\n";
	cin >> rpta;
	switch (rpta)
	{
	case 1:
		cout << "Dinero recibido correctamente" << endl;
		cout << "**** Gracias por su compra ****" << endl;
		break;
	case 2:
		cout << "Tarjeta detectada!! Aplicando 15% de descuento"
			 << "\n";
		cout << "Total sin descuento: " << ptotal << endl;
		;
		nuevot = ptotal * 0.85;
		cout << "Nuevo total: " << nuevot << "\n";
		cout << "**** Gracias por su compra ****" << endl;
		break;
	default:
		cout << "Ingrese 1 o 2!!";
		system("pause");
		system("cls");
		pagar();
		break;
	}
}

void factura()
{
	string salir;
	for (unsigned int i = 0; i < vectorregistro.size(); i++)
	{
		cout << "Producto: " << vectorpro.get(vectorregistro[i] - 1).getproducto() << " - "
			 << "S/. " << vectorpro.get(vectorregistro[i] - 1).getprecio() * vectorcantidad[i] << endl;
	}
	cout << "Total descuento: "<<nuevot<<endl;
	cout << "Total = S/. " << ptotal << endl;

	cout << "Escriba SALIR para regresar: " << endl;
	cin >> salir;

	if (salir != "SALIR")
	{
		system("cls");
		factura();
	}
	else
	{
		system("cls");
		menunormal();
	}
}

/*
#########################################################################
-------------------------FIN DE VENTAS--------------------------------
#########################################################################
*/

/*
#########################################################################
-------------------------INICIO DE CLIENTES--------------------------------
#########################################################################
*/

void menu_clientes()
{
	int opcion;
	do
	{
		std::cout << "1. Agregar cliente"
				  << "\n";
		std::cout << "2. Modificar cliente"
				  << "\n";
		std::cout << "3. Eliminar cliente"
				  << "\n";
		std::cout << "4. Buscar clientes"
				  << "\n";
		std::cout << "5. Salir"
				  << "\n";
		std::cout << "Ingrese una opcion: ";
		std::cin >> opcion;
		std::cout << "\n";
		switch (opcion)
		{
		case 1:
			cliente_vector.cliente_agregar();
			break;
		case 2:
			cliente_vector.cliente_modificar();
			break;
		case 3:
			cliente_vector.cliente_consultar();
			break;
		case 4:
			cliente_vector.cliente_eliminar();
			break;
		case 5:
			std::cout << "Saliendo..."
					  << "\n";
			/*Volver al inicio*/
			tipoDeUsuario();
			break;
		default:
			std::cout << "Opcion no valida"
					  << "\n";
			break;
		}
	} while (opcion != 4);
}
