#include <iostream>
#include <string>
#include <vector>

class ventas
{
private:
   //
   int codigo;
   int cantidad = 0;
   string producto = "NaN";
   float precio = 0;

public:
   ventas(int cod, int can, string pro, float pre)
   {
      codigo = cod;  
      cantidad = can;
      producto = pro;
      precio = pre;
   }
   ventas() {} // constructor vacío

   // sets
    void setcodigo(int cod)
   {
      codigo = cod;
   }

   void setcantidad(int can)
   {
      cantidad = can;
   }

   void setproducto(string pro)
   {
      producto = pro;
   }
   void setprecio(float pre)
   {
      precio = pre;
   }

   // get
    int getcodigo()
    {
        return codigo;
    }

   int getcantidad()
   {
      return cantidad;
   }

   string getproducto()
   {
      return producto;
   }

   float getprecio()
   {
      return precio;
   }
};