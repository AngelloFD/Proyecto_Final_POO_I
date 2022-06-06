#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include "prevector.h"
using namespace std;


class Productosvector
{
	private:
		vector<productos> vectorproductos;
	public:
		void add(productos obj)
		{
			vectorproductos.push_back(obj);
		}
		int getCorrelativo()
		{
			if(vectorproductos.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorproductos[vectorproductos.size()-1].getcantidad()+1;
			}
		}
		productos get(int pos) 
		{
			return vectorproductos[pos];
		}
		int rows()
		{
			return vectorproductos.size();
		}
		int getPostArray(productos obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getproducto() == get(i).getproducto())
				{
					return i;
				}
			}
			return -1;
		}
		void remove(productos obj)
		{
			vectorproductos.erase(vectorproductos.begin() + getPostArray(obj));	
		}
		void grabarEnArchivo(productos probj)
		{
			try
			{
				fstream archivoproducto;
				archivoproducto.open("alumnos.csv",ios::app);
				if(archivoproducto.is_open())
				{
					archivoproducto<<probj.getproducto()<<";"<<probj.getprecio()<<";"<<endl;
					archivoproducto.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Error!";
			}
		}
		void grabarModificarEliminarArchivo()
		{
			try
			{
				fstream archivoproducto;
				archivoproducto.open("alumnos.csv", ios::out);
				if (archivoproducto.is_open())
				{
					for (productos pro : vectorproductos)
					{
						archivoproducto<< pro.getproducto()<<";"<<pro.getprecio()<<";"<<endl;
						
					}
					archivoproducto.close();
				}
			}
			catch (exception e)
			{
				cout << "error";
			}
		}
		
		
};

