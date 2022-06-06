#include <string>
#pragma once
using namespace std;

class productos
{
	private:
		string producto;
		int cantidad;
		float precio,descuento_fijo;
		bool admin;
	public:
		//constructor
		productos(string prod, int cant, float pre, float desf, bool admin)
		{
			producto = prod;
			cantidad = cant;
	
			precio = pre;
			descuento_fijo = desf;
			this->admin = admin;
		}
		productos()
		{
		}
		//sets
		void setproducto ( string prod )
		{
			producto = prod;
		}
		void setcantidad ( int cant )
		{
			cantidad = cant;
		}
		void setprecio(float pre)
		{
			precio = pre;
		}
		void setdescuento(float desf)
		{
			descuento_fijo = desf;
		}
		void setadmin(bool admin)
		{
			this->admin = admin;
		}
		//gets (scando de private)
		string getproducto()
		{
			return producto;
		}
		int getcantidad()
		{
			return cantidad;
		}
		
		float getprecio()
		{
			return precio;
		}
		float getdescuento()
		{
			return descuento_fijo;
		}
		bool getadmin()
		{
			return admin;
		}
		//operaciones
};
