#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<windows.h>
#include<locale.h>
#include"vendedorVector.h"
using namespace std;
//Crear un Objeto
VendedorVector vendedorVector;

void	tipoDeUsuario();
void	inicio();
void 	inicioAdmin();
void	loginUsuario();
void	recuperarCuenta();
void 	menuDeOpciones();
void 	adicionarVendedores();
void 	eliminarVendedores();
void	modificarVendedores();
void	buscarVendedor();
void	listarVendedores();
	void gotoxy(int, int);
int main()
{	
setlocale(LC_CTYPE, "Spanish");

tipoDeUsuario();
}

void tipoDeUsuario()
{
	int rpta;
	string admin;
	string vendedor;
	gotoxy(30,8);cout<<"******************** Bienvenido, Cajero ********************"<<endl;
	gotoxy(50,10);cout<<"[1]. Usuario(VENDEDOR)"<<endl;
	gotoxy(50,12);cout<<"[2]. Admin"<<endl;
	gotoxy(50,14);cout<<"Ingresa tu opcion:";
	cin>>rpta;
	
	switch(rpta)
	{
		case 1:
			system("cls");
			inicio();
			gotoxy(50,10);cout<<"---FALTA COMPLETAR CON CLIENTES----";
			//FALTA CLIENTES
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
		
	gotoxy(30,8); cout<<"******************** Bienvenido, Cajero ********************"<<endl;
	gotoxy(50,10);cout<<" Ingrese su contraseña:";
	cin>>cod;
	gotoxy(50,12);cout<<" Ingrese su nombre:";
	cin>>nom;
	
	if(cod == "ADMIN" && nom == "ADMIN")
	{
		system("cls");
		menuDeOpciones();
	}
	else
	{
		cout<<"No tienes permiso de administrador";
		system("pause");
		tipoDeUsuario();
	}
}


void inicio()
{
	int choice;
//	system("COLOR 80");
	
	gotoxy(30,8); cout<<"******************** Bienvenido, Cajero ********************"<<endl;
	gotoxy(50,10);cout<<"[1]. Ingresar"<<endl;
	gotoxy(50,12);cout<<"[2]. Recuperar contraseña"<<endl;
	gotoxy(50,14);cout<<"Ingresa tu opcion:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			loginUsuario();
			break;
		
		case 2:
			recuperarCuenta();
			break;
		
		default:cout<<"Ingrese una opcion correcta[1-2]"<<endl;
			
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
	
	gotoxy(30,6);cout<<"============================================================"<<endl;
	gotoxy(50,8);cout<<"Ingrese su contraseña:";
	cin>>cod;
	cout<<endl;
	gotoxy(30,10);cout<<"============================================================"<<endl;
	gotoxy(50,12);cout<<"Ingrese su usuario:";
	cin>>nom;
		
		ifstream fe("Vendedores.csv", ios::in);
			
		while(!fe.eof()){
				for( i=0;i<vendedorVector.rows();i++)
	{
		c[i] = vendedorVector.get(i).getCodigo();	
	
		n[i] = vendedorVector.get(i).getNombre();		

			if(cod == c[i]&& nom ==  n[i])
			{
		system("cls");
		gotoxy(30,6);cout<<"============================================================"<<endl;
		gotoxy(50,8);	cout<<"Bienvenido, "<<nom<<endl;
		gotoxy(30,10);cout<<endl;
		gotoxy(45,12);system("pause");
		system("cls");
		//menuDeOpciones();
		cout<<"COMPLETAR CON CLIENTES O VENTAS"<<endl;
		system("pause");
		system("cls");
		tipoDeUsuario();//REEMPLAZAR PROXIMAMENTE-------
			}
		
	}
	system("cls");
	main();
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
	gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
	gotoxy(50,8);cout<<"[1]. Recuperar por nombre de usuario "<<endl;
	gotoxy(50,10);cout<<"[2]. Recuperar po contraseña"<<endl;
	gotoxy(50,12);cout<<"[3]. Volver al menu"<<endl;
	gotoxy(50,14);cout<<"Ingresa tu opcion:";
	cin>>opcion;
	
	ifstream fe("Vendedores.csv", ios::in);
					while(!fe.eof()){
	
	switch(opcion)
	{
		case 1:
				system("cls");
				gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
				gotoxy(50,8);cout<<"Ingresa tu nombre de usuario:";
				cin>>nom;
				
			
				for( i=0;i<vendedorVector.rows();i++)
			{
				c[i] = vendedorVector.get(i).getCodigo();	
	
				n[i] = vendedorVector.get(i).getNombre();	
				
				if(nom ==  n[i])
				{
				gotoxy(50,10);cout<<"Se encontró tu cuenta"<<endl;
				gotoxy(45,12);system("pause");
				system("cls");
				gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
				gotoxy(50,8);cout<<"Tu contraseña es: "<< c[i]<<endl;
				gotoxy(45,10);system("pause");
				system("cls");
				main();
				}
			
			}
			gotoxy(50,10);cout<<"El usuario no existe"<<endl;
			gotoxy(45,12);system("pause");
			system("cls");
			recuperarCuenta();
			
		
	
		case 2:
				system("cls");
				gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
				gotoxy(50,8);cout<<"Ingresa tu contraseña:";
				cin>>cod;
			
				for( i=0;i<vendedorVector.rows();i++)
			{
				c[i] = vendedorVector.get(i).getCodigo();	
	
				n[i] = vendedorVector.get(i).getNombre();	
				
				if(cod ==  c[i])
				{
				gotoxy(50,10);cout<<"Se encontró tu cuenta"<<endl;
				gotoxy(45,12);system("pause");
				system("cls");
				gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
				gotoxy(50,8);cout<<"Tu usuario es: "<< n[i]<<endl;
				gotoxy(45,10);system("pause");
				system("cls");
				main();
				}
			}
			gotoxy(50,10);cout<<"El usuario no existe"<<endl;
			gotoxy(45,12);system("pause");
			system("cls");
			recuperarCuenta();
			
		case 3:
			gotoxy(30,6);cout<<"======================== Recupera tu cuenta ========================";
			gotoxy(50,8);system("pause");
			system("cls");
			main();		
			
		default:cout<<"Ingrese una opcion correcta[1-3]"<<endl;
		}		
	}
}


void gotoxy(int x, int y)
	{
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y= y;
		SetConsoleCursorPosition(hcon,dwPos);
	}
	
	
void menuDeOpciones()
{
	//Declarar Variables
	int opt;
	string rpta;
	do
	{
		gotoxy(30,6); cout<<"================== MENU DE REGISTRO DE VENDEDORES ==================\n";
		gotoxy(30,8); cout<<"[1].Ingresar Nuevos Vendedores\n";
		gotoxy(30,10);cout<<"[2].Eliminar Nuevos Vendedores\n";
		gotoxy(30,12);cout<<"[3].Modificar Nuevos Vendedores\n";
		gotoxy(30,14);cout<<"[4].Buscar Nuevos Vendedores\n";
		gotoxy(30,16);cout<<"[5].Listar Vendedores\n";
		gotoxy(30,18);cout<<"[6].Cerrar sesión\n";
		gotoxy(30,20);cout<<"[7].Salir\n";
		gotoxy(30,22);cout<<"Ingrese una opcion[1-7]:";
		cin>>opt;
		switch(opt)
		{
			case 1:	system("cls");
					adicionarVendedores();
					break;
			case 2:system("cls");
					eliminarVendedores();
					break;
			case 3:system("cls");
					modificarVendedores();
					break;
			case 4:system("cls");
					buscarVendedor();
					break;
			case 5:	system("cls");
					listarVendedores();
					break;
			case 6: system("cls");
					gotoxy(30,6); cout<<"================== MENU DE REGISTRO DE VENDEDORES ==================\n";
					gotoxy(45,8);cout<<"¿Esta seguro de cerrar sesión(SI/si)?:";
					cin>>rpta;
					if(rpta == "SI" || rpta == "si")
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
			case 7:	system("cls");
					gotoxy(30,6);cout<<"************************ Vuelve Pronto !!! ************************\n";
					exit(0);
					break;
			default:cout<<"Ingrese una opcion correcta[1-7]"<<endl;
		}
	}
	while(opt!=7);
	
}

void adicionarVendedores()
{
	//Crear Variables
	int 	cod;
	string 	nom,
			rpta;
	//Crear el Objeto de la clase alumno
	do
	{	
	system("cls");
	gotoxy(30,6); cout<<"==================== INGRESAR NUEVOS VENDEDORES ====================\n";
	
	srand(time(0));
		for (int i = 0; i < 1; i++) {
			cod = 100000 + (rand() % 999999);
		}
		gotoxy(50,8);cout<<"La contraseña generada es:";
		gotoxy(50,10);cout<<cod<<endl;
		cin.ignore();
		
		gotoxy(50,12);cout<<"Ingresar Nombre:";
		getline(cin,nom);
		
		Vendedor vendedor;/*Crear el Objeto*/
		
		vendedor.setCodigo(cod);
		vendedor.setNombre(nom);
		
		vendedorVector.add(vendedor);//Agregar el Objeto al vector dinamico
		
		vendedorVector.grabarEnArchivo(vendedor);
		gotoxy(50,14);cout<<"Para continuar pulsar(SI o si):";
		cin>>rpta;
		system("cls");//Limpiar
	}
	while(rpta=="SI" || rpta=="si");
	main();

}

void listarVendedores()
{
	cout<<"======================= LISTA DE VENDEDORES =======================\n";
	for(int i=0;i<vendedorVector.rows();i++)
	{
		cout<<"Codigo:"<<vendedorVector.get(i).getCodigo()<<"\n";	
		cout<<"Nombre:"<<vendedorVector.get(i).getNombre()<<"\n";	
	}	
	system("pause");
	system("cls");
}


void eliminarVendedores()
{
	int cod;
	gotoxy(30,6);cout<<"======================= ELIMINAR VENDEDOR(ES) =======================\n";
   	gotoxy(50,8); cout<<"Ingresar el codigo del vendedor a eliminar:";
    cin>>cod;
    
    Vendedor SellerDelete = vendedorVector.buscarPorCodigo(cod);
    vendedorVector.remove(SellerDelete);
    
    gotoxy(50,10);system("pause");
    gotoxy(40,12);cout<<"******** Vendedor Eliminado Satisfactoriamente ********";

    //ACTUALIZAR ARCHIVO 
    vendedorVector.grabarModificarEliminarArchivo();
}

void modificarVendedores()
{
    int code;
    gotoxy(30,6);cout<<"======================= MODIFICAR VENDEDOR(ES) =======================\n";
    gotoxy(50,8);cout<<"Ingresar el codigo del vendedor:";
    cin>>code;
    
    Vendedor vendModificar = vendedorVector.buscarPorCodigo(code);
    
	system("pause");
	system("cls");
	gotoxy(30,6);cout<<"======================= MODIFICAR VENDEDOR(ES) =======================\n";
    gotoxy(50,8);cout<<"**** Registro encontrado ****"<<endl;
    gotoxy(50,10);cout<<"Codigo:"<<vendModificar.getCodigo()<<endl;
    gotoxy(50,12);cout<<"Nombre:"<<vendModificar.getNombre()<<endl;
    cin.ignore();
	system("pause");
    string nomModificado;
    cout<<endl;
    gotoxy(50,14);cout<<"Modificar Vendedor:";
    getline(cin,nomModificado);
    bool estado = vendedorVector.modificar(vendModificar,nomModificado);

    if(estado = true)
    {
    	
        gotoxy(40,16);cout<<"**** Registro modificado satisfactoriamente ****";
        //Grabar archivo modificado
        vendedorVector.grabarModificarEliminarArchivo();
    }
    else
    {
        gotoxy(45,16);cout<<"**** No se modificó el registro *****";
        gotoxy(40,18);system("pause");
        menuDeOpciones();
    }
    gotoxy(40,18);system("pause");
    system("cls");
}
void buscarVendedor()
{
	int code;
	gotoxy(30,6);cout<<"======================= BUSCAR AL VENDEDOR =======================\n";
    gotoxy(30,8);cout<<"Ingresar el codigo del vendedor:";
    cin>>code;
    Vendedor vend = vendedorVector.buscarPorCodigo(code);
    gotoxy(30,10); system("pause");
    if(vend.getNombre() != "Error")
    {	
   	 	system("cls");
   	 	gotoxy(30,6);cout<<"======================= BUSCAR AL VENDEDOR =======================\n";
    	gotoxy(30,8);cout<<"**** Registro encontrado ****"<<endl;
    	gotoxy(30,10);cout<<"Codigo:"<<vend.getCodigo()<<endl;
    	gotoxy(30,12);cout<<"Nombre:"<<vend.getNombre()<<endl;
    }
    else
    {
    	system("cls");
   	 	gotoxy(30,6);cout<<"======================= BUSCAR AL VENDEDOR =======================\n";
        gotoxy(30,8);cout<<"No se encontro el registro\n";
        gotoxy(30,10);system("pause");
        menuDeOpciones();
    }
    gotoxy(30,14);system("pause");
}
