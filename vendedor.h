#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

using namespace std;
class Vendedor
{
private:
	int 	codigo;
	string	nombre;

public:
	Vendedor()
	{

	}

	~Vendedor()
	{

	}
	void	setCodigo(int cod)
	{
		codigo = cod;
	}
	void	setNombre(string nom)
	{
		nombre = nom;
	}

	int 	getCodigo()
	{
		return this->codigo;
	}
	string 	getNombre()
	{
		return this->nombre;
	}
};
