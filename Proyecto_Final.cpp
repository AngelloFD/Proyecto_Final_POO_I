#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"vendedorVector.h"

using namespace std;

VendedorVector vendedorVector;

void	loginUsuario();
void 	menuDeOpciones();
void 	adicionarVendedores();
void 	eliminarVendedores();
void	modificarVendedores();
void	buscarVendedor();
void	listarVendedores();
	void gotoxy(int, int);
int main()
{
	
	
	int choice;
//	system("COLOR 80");
	
	gotoxy(30,8); cout<<"******************** Bienvenido, Cajero ********************"<<endl;
	gotoxy(50,10);cout<<"[1]. Ingresar"<<endl;
	gotoxy(50,12);cout<<"[2]. Registrar"<<endl;
	gotoxy(50,14);cout<<"Ingresa tu opcion: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			loginUsuario();
			break;
		case 2:
			
			adicionarVendedores();
			break;
			
	}
	

}

void loginUsuario()
{
	int exist;
	string nom,n;
	int cod,c;
	system("cls");
	gotoxy(30,6);cout<<"============================================================"<<endl;
	gotoxy(50,8);cout<<"Ingrese su contraseña:";
	cin>>cod;
	cout<<endl;
	gotoxy(30,10);cout<<"============================================================"<<endl;
	gotoxy(50,12);cout<<"Ingrese su usuario:";
	cin>>nom;
		
	
		for(int i=0;i<vendedorVector.rows();i++)
	{
		c = vendedorVector.get(i).getCodigo();	
		n = vendedorVector.get(i).getNombre();		
}
	
		if(c == cod && n == nom )
		{
		system("pause");	
			system("cls");
		gotoxy(30,6);cout<<"============================================================"<<endl;
		gotoxy(50,8);	cout<<"Bienvenido, "<<nom<<endl;
		gotoxy(30,10);cout<<endl;
		gotoxy(45,12);	cout<<"Presionar enter para continuar..."<<endl;
		system("pause");
		system("cls");
		
		menuDeOpciones();
	}
	else
	{
			system("cls");
		cout<<"No se encuentra registrado";
	
		main();
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
	do
	{
		cout<<"MENU DE REGISTRO DE VENDEDORES\n";
		cout<<"Ingresar Nuevos Vendedores	[1]\n";
		cout<<"Eliminar Nuevos Vendedores	[2]\n";
		cout<<"Modificar Nuevos Vendedores	[3]\n";
		cout<<"Buscar Nuevos Vendedores		[4]\n";
		cout<<"Listar Vendedores			[5]\n";
		cout<<"Cerrar sesión				[6]\n";
		cout<<"Salir						[7]\n";
		cout<<"Ingrese una opcion[1-7]:";
		cin>>opt;
		switch(opt)
		{
			case 1:	system("cls");
					adicionarVendedores();
					break;
			case 2:system("cls");eliminarVendedores();break;
			case 3:system("cls");modificarVendedores();break;
			case 4:system("cls");buscarVendedor();break;
			case 5:	system("cls");
					listarVendedores();
					break;
			case 6: system("cls");
					main();
					break;
			case 7:	system("cls");cout<<"###########Gracias por tu compra##########\n";
					exit(0);
					break;
			default:cout<<"Ingrese una opcion correcta[1-6]"<<endl;
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
		//Entrada de datos
	srand(time(0));
		for (int i = 0; i < 1; i++) {
			cod = 100000 + (rand() % 999999);
		}
		cout<<"La contraseña generada es:";
		cout<<cod<<endl;
		
		cout<<"Ingresar Nombre:";
		getline(cin,nom);
		
		Vendedor vendedor;/*Crear el Objeto*/
		
		vendedor.setCodigo(cod);
		vendedor.setNombre(nom);
		
		vendedorVector.add(vendedor);//Agregar el Objeto al vector dinamico
		
		vendedorVector.grabarEnArchivo(vendedor);
		cout<<"Para continuar pulsar(SI o si):";
		cin>>rpta;
		system("cls");//Limpiar
	}
	while(rpta=="SI" || rpta=="si");
	main();

}

void listarVendedores()
{
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
    cout<<"Ingresar el codigo del vendedor a eliminar:";
    cin>>cod;
    Vendedor SellerDelete = vendedorVector.buscarPorCodigo(cod);
    vendedorVector.remove(SellerDelete);
    cout<<"==Registro eliminado satisfactoriamente==";

    //ACTUALIZAR ARCHIVO ( FALTA COMPLETAR )-----
    vendedorVector.grabarModificarEliminarArchivo();
    
    
}
void modificarVendedores()
{
    int code;
    cout<<"Ingresar el codigo del vendedor:";
    cin>>code;
    Vendedor vendModificar = vendedorVector.buscarPorCodigo(code);

    cout<<"Registro encontrado"<<endl;
    cout<<"Codigo:"<<vendModificar.getCodigo()<<endl;
    cout<<"Nombre:"<<vendModificar.getNombre()<<endl;
    cin.ignore();

    string nomModificado;
    cout<<"Modificar campos\n";
    getline(cin,nomModificado);
    bool estado = vendedorVector.modificar(vendModificar,nomModificado);

    if(estado = true)
    {
        cout<<"Registro modificado satisfactoriamente";
        //Grabar archivo modificado( Falta completar)------
        vendedorVector.grabarModificarEliminarArchivo();
    }
    else
    {
        cout<<"No se modifico el registro";
        system("pause");
        menuDeOpciones();
    }
    system("pause");
    system("cls");
}
void buscarVendedor()
{
	int code;
    cout<<"Ingresar el codigo del vendedor:";
    cin>>code;
    Vendedor vend = vendedorVector.buscarPorCodigo(code);
    if(vend.getNombre() != "Error")
    {
    cout<<"Registro encontrado"<<endl;
    cout<<"Codigo:"<<vend.getCodigo()<<endl;
    cout<<"Nombre:"<<vend.getNombre()<<endl;
    }
    else
    {
        cout<<"No se encontro el registro\n";
        system("pause");
        menuDeOpciones();
    }
    system("pause");
}
