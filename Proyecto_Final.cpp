#include "CLIENTES_V.h"
#include "PRODUCTOS.h"
#include "VENDEDORES.h"
#include <iostream>
#include <vector>
#include <Windows.h>

CLIENTES_V cliente_vector;

char check_char(char check, char VALIDO1, char VALIDO2) {
	std::cin >> check;
	while (toupper(check) != VALIDO1 && toupper(check) != VALIDO2) {
		std::cout << "Opcion invalida, intente de nuevo: ";
		std::cin >> check;
	}
	return toupper(check);
}

void adicionar_clientes() {
	char rpta;
	do {
		char codigo[10] = "";
		char nombre[51] = "";
		char apellido[51] = "";
		char sexo = 0;
		char tarjeta_ventaPlus = 0;
		char registrado_web = 0;
		char correo[101] = "";
		char contrasena[10] = "";
		char celular[10] = "";
		int DNI = 0;
		int monto_consumido_semanal = 0;

		std::cout << "Ingrese el nombre del cliente: ";
		std::cin >> nombre;
		std::cout << "Ingrese el apellido del cliente: ";
		std::cin >> apellido;
		std::cout << "Ingrese el sexo del cliente (M/F): ";
		sexo = check_char(sexo, 'M', 'F');
		std::cout << "¿El cliente cuenta con una tarjeta VENTA+? (S/N): ";
		tarjeta_ventaPlus = check_char(tarjeta_ventaPlus, 'S', 'N');
		if (tarjeta_ventaPlus == 'S') {
			std::cout << "Ingrese el DNI del cliente para verificacion: ";
			std::cin >> DNI;
		}
		std::cout << "¿El cliente esta registrado en la web? (S/N)";
		registrado_web = check_char(registrado_web, 'S', 'N');
		
		Cliente cliente(codigo, nombre, apellido, sexo, tarjeta_ventaPlus, registrado_web, correo, contrasena, celular, DNI, monto_consumido_semanal);
		cliente_vector.vector_add(cliente);

		std::cout << "¿Desea seguir? (S/N)\n";
		std::cin >> rpta;
		system("cls");
	} while (toupper(rpta) == 'S');
}

int main()
{
	adicionar_clientes();
	
	for (int i = 0; i < cliente_vector.rows(); i++) {
		std::cout << "Codigo: " << cliente_vector.get(i).get_codigo() << "\n";
		std::cout << "Nombre: " << cliente_vector.get(i).get_nombre() << "\n";
		std::cout << "Apellido: " << cliente_vector.get(i).get_apellido() << "\n";
		std::cout << "Sexo: " << cliente_vector.get(i).get_sexo() << "\n";
		std::cout << "Tarjeta VENTA+: " << cliente_vector.get(i).get_tarjeta() << "\n";
		std::cout << "Registrado en la web: " << cliente_vector.get(i).get_registrado_web() << "\n";
		std::cout << "Correo: " << cliente_vector.get(i).get_correo() << "\n";
		std::cout << "Contrasena: " << cliente_vector.get(i).get_contrasena() << "\n";
		std::cout << "Celular: " << cliente_vector.get(i).get_celular() << "\n";
		std::cout << "DNI: " << cliente_vector.get(i).get_DNI() << "\n";
		std::cout << "Monto consumido semanal: " << cliente_vector.get(i).get_monto_semanal() << "\n";
		std::cout << "----------------------------------------------------\n";
	}
}
