#include<string>
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
