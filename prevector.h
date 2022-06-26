#include <string>
#pragma once
using namespace std;

class productos
{
	private:
		int codigo;
		string producto;
		int cantidad;
		float precio,descuento_fijo;
		bool admin;
		float total;
	public:
		//constructor
		productos(int cod,string prod, int cant, float pre, float desf, bool admin,float total)
		{
			codigo = cod;
			producto = prod;
			cantidad = cant;
			precio = pre;
			descuento_fijo = desf;
			this->admin = admin;
			this->total = total;
		}
		productos()
		{
		}
		//sets
		void setcodigo(int cod)
		{
			codigo = cod;
		}
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
		void settotal(float total)
		{
			this->total = total;
		}
		//gets (scando de private)
		int getcodigo()
		{
			return codigo;
		}
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
		float gettotal()
		{
			return total;
		}
		//operaciones
		float descuento()
		{
			return total - ( total * 0.15 );
		}
};
