#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include "VENTAS.h"
using std::stoi;
using namespace std;


class ventasvector
{
	private:
		vector<ventas> vectorventas;
	public:
		ventasvector()
		{
			cargarDatosDelArchivoAlVector();
			vector<ventas> vectorventas;
		}
		int getCorrelativo()
		{
			if(vectorventas.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorventas[vectorventas.size() - 1].getcodigo() + 1;
			}
		}
		void add( ventas obj ) // A�ade los objectos a una casilla del vector dinamico
		{
			vectorventas.push_back(obj);
		}
		
		ventas get( int pos ) //entregar el objeto actual, seg�n la posicion pasada como par�metro
		{
			return vectorventas[pos];
		}
		ventas at( int pos )
		{
			return vectorventas.at(pos);
		}
		int rows() //regresa el tama�o actual del vector
		{
			return vectorventas.size();
		}
		
		int getPostArray(ventas obj) 
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
		
		void eliminar(ventas ven) //elimina los archivos
		{
			vectorventas.erase(vectorventas.begin() + getPostArray(ven));	
		}
		
		bool modificar(ventas obj, string prod, float pre) //modifica
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					vectorventas[i].setproducto(prod);
					vectorventas[i].setprecio(pre);
					
					return true;
				}
			}
			return false;
		}
		
		bool modificarcodigo(ventas obj, int cod) //modifica
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getcodigo() == get(i).getcodigo())
				{
					vectorventas[i].setcodigo(cod-1);
					return true;
				}
			}
			return false;
		}
		
		void grabarEnArchivo(ventas ven)
		{
			try // metodo para agarra errores
			{
				fstream archivoven; 																		//creando instancia para fstream
				archivoven.open("ventas.csv",ios::app); 													//iso::app segun documentacion no borra ni sobreescribe data existente el archivo
				if(archivoven.is_open())  																//confirmo si esta abierto o no
				{
					archivoven<<ven.getcodigo()<<";"<<ven.getproducto()<<";"<<ven.getprecio()<<";"<<ven.getcantidad()<<"\n";   //creando una linea en string para que luego sea puesto en un vector temporal
					archivoven.close(); //cerrado
				}
			}			
			catch(exception e)
			{
				cout<<"No s� como, pero hay un error";
			}
		}
		
		void grabarModificarEliminarArchivo(ventas ven)
		{
			try // metodo para agarrar errores
			{
				fstream archivoven;																			//creando instancia para fstream
				archivoven.open("ventas.csv", ios::out);													//ios::out segun documentacion es para escribir data en el archivo
				if (archivoven.is_open())																	//confirmo si esta abierto o no
				{
					for (ventas si : vectorventas)													//loop para encontrar todos las casillas en el vector
					{
						archivoven<<si.getcodigo()<<";"<<si.getproducto()<<";"<<si.getprecio()<<";"<<si.getcantidad()<<"\n";  //grabo los parametros introducidos dejando una ; entre cada uno
					}
					archivoven.close();//cierra
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
				string temporal[4];																			//Cantidad de columnas, IMPORTANTE: CAMBIA TUS COLUMNAS DEPENDIENDO DE CUANTAS VARIABLES TIENES (ACTUAL 3: COD,PRO,PRE)
				fstream archivoven;
				archivoven.open("ventas.csv", ios::in);													//ios::in seg�n documentaci�n es para extraer y leer data
				if (archivoven.is_open())
				{
					
					while (!archivoven.eof()) 																//eof = end of the file, "!" significa lo contrario a lo escrito ah� (~)
					{
					
						while (getline(archivoven, linea))													//MIENTRAS encuentra la linea en ventas.csv con la string linea
						{
							i = 0;
							while ((posi = linea.find(";")) != string::npos)                     			//MIENTRAS que posicion no sea "stringnpos" (que es -1). 
							{
								temporal[i] = linea.substr(0, posi);										//posi = Es la cantidad de caracteres antes del ;
								linea.erase(0, posi + 1);													//Borra toda la palabra de la pos que se encontr�, uso el "+1" para incluir el ";" y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
								i++;																		//aumenta i para que pase a la siguiente casilla
							}
							//Asignando los valores al vector
							ventas ven;
							ven.setcodigo(std::stoi(temporal[0]));											//uso std::stoi (C++11 btw) para convertir el string que tengo a int
							ven.setproducto(temporal[1]);
							ven.setprecio(std::stof(temporal[2]));	                                        //uso std::stof (C++11 btw) para convertir el string que tengo a float
                            ven.setcantidad(std::stoi(temporal[3]));											
							add(ven);																		//agrego al vector antes de todo
						}
					}
				}
				archivoven.close(); //cerrar
			}
			catch (exception e)
			{
				cout << "No se pudo leer el archivo";														//por si acaso falla y no crashea ( no probable ) 
			}
		}
		
		ventas busquedaBinaria(int cod_a_buscar)
		{
			int superior;
			int inferior;
			int mitad;
			
			//setting flag para acabar
			bool flag = false;
			
			inferior 	= 0;
			superior	= vectorventas.size(); //numero máximo del vector
			
			mitad = ( inferior + superior )/2;
			while( inferior <= superior )
			{
				if( vectorventas[mitad].getcodigo() == cod_a_buscar )
				{
					flag = true;
					break;
				}
				if( vectorventas[mitad].getcodigo() > cod_a_buscar )
				{
					superior = mitad - 1;
				}
				if( vectorventas[mitad].getcodigo() < cod_a_buscar )
				{
					inferior = mitad + 1;
				}
				mitad = (inferior + superior) / 2;
			}
			if(flag == true)
			{
				cout<<"El dato pedido fue: "<<mitad+1<<" - "<<get(mitad).getproducto()<<" - "<<"S/."<<get(mitad).getprecio()<<" - "<<get(mitad).getcantidad()<<"\n";
				return get(mitad);
			}
			else
			{
				cout<<"NO encontrado!!! - Defaulteando al ultimo!"<<"\n";
			}
			return get(mitad); //DEFAULT
		}
	};
