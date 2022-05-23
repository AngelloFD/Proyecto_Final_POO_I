#include "CLIENTES.h"
#include "PRODUCTOS.h"
#include "VENDEDORES.h"
#include <iostream>
#include <vector>
#include <Windows.h>

int main()
{
	char codigo[10] = "";
	char nombre[51] = "test_nombre";
	char apellido[51] = "test_apellido";
	char sexo = 'T';
	char tarjeta_ventaPlus = 'X';
	char registrado_web = 'X';
	char correo[101] = "";
	char contra[10] = "";
	char celular[10] = "";
	int DNI = 0;
	int monto_consumido_semanal = 0;
	
	Cliente cl(codigo, nombre, apellido, sexo, tarjeta_ventaPlus, registrado_web, correo, contra, celular, DNI, monto_consumido_semanal);
	
	while (true) {
		std::cout << cl.get_codigo() << "\n";
		std::cout << cl.get_celular() << "\n";
		std::cout << cl.get_correo() << "\n";
		std::cout << cl.get_contrasena() << "\n";
		Sleep(1000);
	}
	
	
}
