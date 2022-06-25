#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include "prevector.h"
using std::stoi;
using namespace std;


class Productosvector
{
	private:
		vector<productos> vectorproductos;
	public:
		Productosvector()
		{
			cargarDatosDelArchivoAlVector();
			vector<productos> vectorproductos;
		}
		int getCorrelativo()
		{
			if(vectorproductos.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorproductos[vectorproductos.size() - 1].getcodigo() + 1;
			}
		}
		void add( productos obj ) // Añade los objectos a una casilla del vector dinamico
		{
			vectorproductos.push_back(obj);
		}
		
		productos get( int pos ) //entregar el objeto actual, según la posicion pasada como parámetro
		{
			return vectorproductos[pos];
		}
		productos at( int pos )
		{
			return vectorproductos.at(pos);
		}
		int rows() //regresa el tamaño actual del vector
		{
			return vectorproductos.size();
		}
		
		int getPostArray(productos obj) 
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					return i;
				}
			}
			return -1;
		}
		
		void eliminar(productos pro) //elimina los archivos
		{
			vectorproductos.erase(vectorproductos.begin() + getPostArray(pro));	
		}
		
		bool modificar(productos obj, string prod, float pre) //modifica
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					vectorproductos[i].setproducto(prod);
					vectorproductos[i].setprecio(pre);
					
					return true;
				}
			}
			return false;
		}
		
		bool modificarcodigo(productos obj, int cod) //modifica
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					vectorproductos[i].setcodigo(cod-1);
					return true;
				}
			}
			return false;
		}
		
		void grabarEnArchivo(productos pro)
		{
			try // metodo para agarra errores
			{
				fstream archivopro; 																		//creando instancia para fstream
				archivopro.open("productos.csv",ios::app); 													//iso::app segun documentacion no borra ni sobreescribe data existente el archivo
				if(archivopro.is_open())  																//confirmo si esta abierto o no
				{
					archivopro<<pro.getcodigo()<<";"<<pro.getproducto()<<";"<<pro.getprecio()<<";"<<endl;   //creando una linea en string para que luego sea puesto en un vector temporal
					archivopro.close(); //cerrado
				}
			}			
			catch(exception e)
			{
				cout<<"No sé como, pero hay un error";
			}
		}
		
		void grabarModificarEliminarArchivo(productos pro)
		{
			try // metodo para agarrar errores
			{
				fstream archivopro;																			//creando instancia para fstream
				archivopro.open("productos.csv", ios::out);													//ios::out segun documentacion es para escribir data en el archivo
				if (archivopro.is_open())																	//confirmo si esta abierto o no
				{
					for (productos og : vectorproductos)													//loop para encontrar todos las casillas en el vector
					{
						archivopro<<og.getcodigo()<<";"<<og.getproducto()<<";"<<og.getprecio()<<";"<<"\n";  //grabo los parametros introducidos dejando una ; entre cada uno
					}
					archivopro.close();//cierra
				}
			}
			catch (exception e)
			{
				cout << "Error en el grabado :(";  //:((((
			}
		}
		
		void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int i;
				size_t posi;																				//Cantidad maxima
				string linea;
				string temporal[3];																			//Cantidad de columnas, IMPORTANTE: CAMBIA TUS COLUMNAS DEPENDIENDO DE CUANTAS VARIABLES TIENES (ACTUAL 3: COD,PRO,PRE)
				fstream archivopro;
				archivopro.open("productos.csv", ios::in);													//ios::in según documentación es para extraer y leer data
				if (archivopro.is_open())
				{
					
					while (!archivopro.eof()) 																//eof = end of the file, "!" significa lo contrario a lo escrito ahí (~)
					{
					
						while (getline(archivopro, linea))													//MIENTRAS encuentra la linea en productos.csv con la string linea
						{
							i = 0;
							while ((posi = linea.find(";")) != string::npos)                     			//MIENTRAS que posicion no sea "stringnpos" (que es -1). 
							{
								temporal[i] = linea.substr(0, posi);										//posi = Es la cantidad de caracteres antes del ;
								linea.erase(0, posi + 1);													//Borra toda la palabra de la pos que se encontró, uso el "+1" para incluir el ";" y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
								i++;																		//aumenta i para que pase a la siguiente casilla
							}
							//Asignando los valores al vector
							productos pro;
							pro.setcodigo(std::stoi(temporal[0]));											//uso std::stoi (C++11 btw) para convertir el string que tengo a int
							pro.setproducto(temporal[1]);
							pro.setprecio(std::stof(temporal[2]));											//uso std::stof (C++11 btw) para convertir el string que tengo a float
							add(pro);																		//agrego al vector antes de todo
						}
					}
				}
				archivopro.close(); //cerrar
			}
			catch (exception e)
			{
				cout << "No se pudo leer el archivo";														//por si acaso falla y no crashea ( no probable ) 
			}
		}
		
		productos busquedaBinaria(int cod_a_buscar)
		{
			int superior;
			int inferior;
			int mitad;
			
			
			bool flag = false;
			
			inferior 	= 0;
			superior	= vectorproductos.size();
			
			mitad = ( inferior + superior )/2;
			while( inferior <= superior )
			{
				if( vectorproductos[mitad].getcodigo() == cod_a_buscar )
				{
					flag = true;
					break;
				}
				if( vectorproductos[mitad].getcodigo() > cod_a_buscar )
				{
					superior = mitad - 1;
				}
				if( vectorproductos[mitad].getcodigo() < cod_a_buscar )
				{
					inferior = mitad + 1;
				}
				mitad = (inferior + superior) / 2;
			}
			if(flag == true)
			{
				cout<<"El dato pedido fue: "<<mitad+1<<" - "<<get(mitad).getproducto()<<" - "<<"S/."<<get(mitad).getprecio()<<endl;
				return get(mitad);
			}
			else
			{
				cout<<"NO encontrado!!! - Defaulteando al último!"<<endl;
			}
			return get(mitad);
		}
	};
