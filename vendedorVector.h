#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include"vendedor.h"

using namespace std;

class VendedorVector
{
	private:
		vector<Vendedor> vectorVendedor;
	public:
		VendedorVector()
		{
			cargarDatosDelArchivoAlVector();
			vector<Vendedor> vectorVendedor;
		}
		
		void add(Vendedor obj)
		{
			vectorVendedor.push_back(obj);
		}
		
		Vendedor get(int pos)
		{
			return vectorVendedor[pos];
		}
		
		int rows()
		{
			return vectorVendedor.size();
		}
		
		
		
		
		Vendedor buscarPorCodigo(int codigo)
		{
			for(Vendedor x:vectorVendedor)
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
		}
		Vendedor buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<rows();i++)			
			{
				if(codigo == get(i).getCodigo())
				{
					return get(i);
				}
			}
		}
		
		int getPostArray(Vendedor obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					return i;
				}
			}
			return -1;
		}
		
		void remove(Vendedor obj)
		{
			vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));	
		}

    bool modificar(Vendedor obj, string nom)
    {
       for(int i=0;i<rows();i++)
       {
           if(obj.getCodigo() == get(i).getCodigo())
           {
               vectorVendedor[i].setNombre(nom);
               return true;
           }
       }
       return false;
    }


    void grabarEnArchivo(Vendedor vendedor)
		{
			try
			{
				fstream archivoVendedor;
				archivoVendedor.open("vendedores.csv",ios::app);
				if(archivoVendedor.is_open())
				{
					archivoVendedor<<vendedor.getCodigo()<<";"<<vendedor.getNombre()<<";"<<endl;
					archivoVendedor.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el registro!!!";
			}
		}

    void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int i;
				size_t posi;//Cantidad maxima
				string linea;
				string temporal[2];//Cantidad de columnas
				fstream archivoVendedor;
				archivoVendedor.open("vendedores.csv", ios::in);
				if (archivoVendedor.is_open())
				{
					while (!archivoVendedor.eof()) 
					{
						while (getline(archivoVendedor, linea))
						{
							i = 0;
							while ((posi = linea.find(";")) != string::npos) 
							{
								temporal[i] = linea.substr(0, posi);
								linea.erase(0, posi + 1);
								i++;
							}

						Vendedor vendedor;
						vendedor.setCodigo(std::stoi(temporal[0]));
						vendedor.setNombre(temporal[1]);
						add(vendedor);
						}
					}
				}	
					archivoVendedor.close();
			}
			catch (exception e)
			{	
				cout << "Ocurrio un error al leer el archivo";
			}
		}

    void grabarModificarEliminarArchivo()
    {
        try
        {
            fstream archivoVendedor;
            archivoVendedor.open("vendedores.csv", ios::out);
                  if (archivoVendedor.is_open())
                {
                    for (Vendedor x : vectorVendedor)
                {
                archivoVendedor << x.getCodigo() << ";" << x.getNombre() << ";" << "\n";
                }
                archivoVendedor.close();
                }
        }
        catch (exception e)
        {   
        cout << "Ocurrio un error al grabar en el archivo";
        }       
    }
};
