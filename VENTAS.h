#include <iostream>
#include <string>
#include <vector>

class ventas
{
private:
   // codigopersona;codigoproducto-codigoproducto-;precio*cantidad-precio*cantidad-;cantidad (x-x-x-x-)

   int codigopersona = 0;  // vendedores.csv
   int codigoproducto = 0; // productos.csv
   float precio = 0;       // precio*cantidad
   int cantidad = 0;       // en main.cpp
   char tarjeta = 'N';

public:
   ventas(int codper, int codpro, float pre, int can, char tar)
   {
      codigopersona = codper;
      codigoproducto = codpro;
      precio = pre;
      cantidad = can;
      tarjeta = tar;
   }
   ventas() {} // constructor vacío

   // sets
   void setcodigopersona(int codper)
   {
      codigopersona = codper;
   }

   void setcodigoproducto(int codpro)
   {
      codigoproducto = codpro;
   }

   void setprecio(float pre)
   {
      precio = pre;
   }

   void setcantidad(int can)
   {
      cantidad = can;
   }

   void setcantidad(int can)
   {
      cantidad = can;
   }

   void settarjeta(char tar)
   {
      tarjeta = tar;
   }

   // get
   int getcodigopersona()
   {
      return codigopersona;
   }

   int getcodigoproducto()
   {
      return cantidad;
   }

   float getprecio()
   {
      return precio;
   }

   float getcantidad()
   {
      return cantidad;
   }

   char gettarjeta()
   {
      return tarjeta;
   }

   // para errores en busqueda
};