#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include "VENTAS.h"
#include "CLIENTES_V.h"

using std::stoi;
using namespace std;

ventas ven;

CLIENTES_V clt_vector;

class ventasvector
{
private:
	vector<ventas> vectorventas;
	vector<Cliente> cliente_vector;

public:
	ventasvector()
	{
		cargarDatosDelArchivoAlVector();
		vector<ventas> vectorventas;
	}
	void add(ventas obj) // A�ade los objectos a una casilla del vector dinamico
	{
		vectorventas.push_back(obj);
	}

	ventas get(int pos) // entregar el objeto actual, seg�n la posicion pasada como par�metro
	{
		return vectorventas[pos];
	}

	int rows() // regresa el tama�o actual del vector
	{
		return vectorventas.size();
	}

	int getPostArray(ventas obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getcodigopersona() == get(i).getcodigopersona())
			{
				return i;
			}
		}
		return -1;
	}

	ventas error()
	{
		return vectorventas[0];
	}

	Cliente busquedaBinariacliente(int cod_a_buscar)
	{
		int superior;
		int inferior;
		int mitad;

		// setting flag para acabar
		bool flag = false;

		inferior = 0;
		superior = cliente_vector.size(); // numero máximo del vector

		mitad = (inferior + superior) / 2;
		while (inferior <= superior)
		{
			if (cliente_vector[mitad].get_codigo() == cod_a_buscar)
			{
				flag = true;
				break;
			}
			if (cliente_vector[mitad].get_codigo() > cod_a_buscar)
			{
				superior = mitad - 1;
			}
			if (cliente_vector[mitad].get_codigo() < cod_a_buscar)
			{
				inferior = mitad + 1;
			}
			mitad = (inferior + superior) / 2;
		}
		if (flag == true)
		{
			cout << "El dato pedido fue: "
				 << "PERSONA ID: " << mitad + 1 << " - " <<"TARJETA: " <<clt_vector.get(mitad).get_tarjeta_ventaPlus()<<"\n";
			return clt_vector.get(mitad);
		}
		else
		{
			cout << "NO encontrado!!! - Defaulteando al ultimo!"
				 << "\n";
		}
	}

	void eliminar(ventas ven) // elimina los archivos
	{
		vectorventas.erase(vectorventas.begin() + getPostArray(ven));
	}

	/* No es necesario
	bool modificar(ventas obj, string prod, float pre) //modifica
	{
		for(int i=0;i<rows();i++)
		{
			if(obj.getcodigopersona() == get(i).getcodigopersona())
			{
				vectorventas[i].setcodigoproducto(prod);
				vectorventas[i].setprecio(pre);

				return true;
			}
		}
		return false;
	}
	*/

	/*
	bool modificarcodigo(ventas obj, int cod) //modifica
	{
		for(int i=0;i<rows();i++)
		{
			if(obj.getcodigopersona() == get(i).getcodigopersona())
			{
				vectorventas[i].setcodigopersona(cod-1);
				return true;
			}
		}
		return false;
	}
	*/

	/*
	void grabarEnArchivo(ventas ven)
	{
		try // metodo para agarra errores
		{
			fstream archivoclientes; 																		//creando instancia para fstream
			archivoclientes.open("ventas.csv",ios::app); 													//iso::app segun documentacion no borra ni sobreescribe data existente el archivo
			if(archivoclientes.is_open())  																//confirmo si esta abierto o no
			{
				archivoclientes<<ven.getcodigopersona()<<";"<<ven.getcodigoproducto()<<"-"<<";"<<ven.getprecio()<<"/"<<";"<<ven.getcantidad()<<"*"<<";"<<"\n";   //creando una linea en string para que luego sea puesto en un vector temporal
				archivoclientes.close(); //cerrado
			}
		}
		catch(exception e)
		{
			cout<<"No s� como, pero hay un error";
		}
	}

	void grabarModificarEliminarArchivo(ventas ven) //necesita re-write
	{
		string linea;
		try // metodo para agarrar errores
		{
			fstream archivoclientes;																			//creando instancia para fstream
			archivoclientes.open("ventas.csv", ios::out);													//ios::out segun documentacion es para escribir data en el archivo
			if (archivoclientes.is_open())																	//confirmo si esta abierto o no
			{
				for (ventas si : vectorventas)													//loop para encontrar todos las casillas en el vector
				{
					archivoclientes<<si.getcodigopersona()<<";"<<si.getcodigoproducto()<<"-"<<";"<<si.getprecio()<<"/"<<";"<<si.getcantidad()<<"*"<<";"<<"\n";  //grabo los parametros introducidos dejando una ; entre cada uno
				}
				archivoclientes.close();//cierra
			}
		}
		catch (exception e)
		{
			cout << "Error en el grabado :(";  //:((((
		}
	}*/

	void add(Cliente obj)
	{
		cliente_vector.push_back(obj);
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;
			std::string linea;
			std::string temporal[7];
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::in);
			if (archivo_cliente.fail())
			{
				throw std::exception();
			}

			if (archivo_cliente.is_open())
			{
				while (!archivo_cliente.eof())
				{
					i = 0;
					while ((posi = linea.find(",")) != std::string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						i++;
					}
					Cliente clt;
					clt.set_codigo(std::stoi(temporal[0]));
					clt.set_nombre(temporal[1]);
					clt.set_apellido(temporal[2]);
					clt.set_tarjeta_ventaPlus(std::stoi(temporal[3]));
					clt.set_registrado_web(std::stoi(temporal[4]));
					clt.set_correo(temporal[5]);
					clt.set_contrasena(temporal[6]);
					clt.set_celular((temporal[7]));
					add(clt);
				}
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	void cargarclientes()
	{
		try
		{
			int i;
			size_t posi; // Cantidad maxima
			string linea;
			string temporal[8]; // Cantidad de columnas, IMPORTANTE: CAMBIA TUS COLUMNAS DEPENDIENDO DE CUANTAS VARIABLES TIENES (ACTUAL 3: COD,PRO,PRE)
			fstream archivoclientes;
			archivoclientes.open("ventas.csv", ios::in); // ios::in seg�n documentaci�n es para extraer y leer data
			if (archivoclientes.is_open())
			{

				while (!archivoclientes.eof()) // eof = end of the file, "!" significa lo contrario a lo escrito ah� (~)
				{

					while (getline(archivoclientes, linea)) // MIENTRAS encuentra la linea en ventas.csv con la string linea
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos) // MIENTRAS que posicion no sea "stringnpos" (que es -1).
						{
							temporal[i] = linea.substr(0, posi); // posi = Es la cantidad de caracteres antes del ;
							linea.erase(0, posi + 1);			 // Borra toda la palabra de la pos que se encontr�, uso el "+1" para incluir el ";" y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso ,
							i++;								 // aumenta i para que pase a la siguiente casilla
						}
						// Asignando los valores al vector
						ventas ven;
						ven.setcodigopersona(std::stoi(temporal[0])); // uso std::stoi (C++11 btw) para convertir el string que tengo a int

						// uso std::stof (C++11 btw) para convertir el string que tengo a float
						ven.setcantidad(std::stoi(temporal[3]));
						add(ven); // agrego al vector antes de todo
					}
				}
			}
			archivoclientes.close(); // cerrar
		}
		catch (exception e)
		{
			cout << "No se pudo leer el archivo"; // por si acaso falla y no crashea ( no probable )
		}
	}
};
