#include "CLIENTES_V.h"
#include "PRODUCTOS.h"
#include "VENDEDORES.h"

#include <iostream>
#include <vector>
#include <Windows.h>

CLIENTES_V cliente_vector;

void MENU_CLIENTES() {
	Beep(480, 200);
	system("cls");
	
	Cliente cliente;

	int rpta;
	do {
		rpta = cliente.pantalla_cliente();
		Cliente* cliente = new Cliente();

		switch (rpta) {
		case 1:
			char rpta_1;
			do {
				Beep(480, 200);
				cliente_vector.vector_add(*cliente->cliente_agregar());
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_1;
			} while (std::toupper(rpta_1) == 'S');
			break;
		case 2:
			char rpta_2;
			do {
				Beep(480, 200);
				cliente_vector.cliente_modificar();
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_2;
			} while (std::toupper(rpta_2) == 'S');
			break;
		case 3:
			for (int i = 0; i < cliente_vector.rows(); i++) {
				std::cout << "codigo: " << cliente_vector.get(i).get_codigo() << '\n';
				std::cout << "nombre: " << cliente_vector.get(i).get_nombre() << '\n';
				std::cout << "apellido: " << cliente_vector.get(i).get_apellido() << '\n';
				std::cout << "sexo: " << cliente_vector.get(i).get_sexo() << '\n';
				std::cout << "con tarjeta: " << cliente_vector.get(i).get_tarjeta() << '\n';
				std::cout << "esta registrado: " << cliente_vector.get(i).get_registrado_web() << '\n';
				std::cout << "correo: " << cliente_vector.get(i).get_correo() << '\n';
				std::cout << "contra: " << cliente_vector.get(i).get_contrasena() << '\n';
				std::cout << "celular: " << cliente_vector.get(i).get_celular() << '\n';
				std::cout << "dni: " << cliente_vector.get(i).get_DNI() << '\n';
				std::cout << "monto: " << cliente_vector.get(i).get_monto_semanal() << '\n';
				std::cout << "-------------------------------------------------------\n";
			}
		default:
			break;
		}

		std::cout << "Regresando al inicio";
		for (int i = 0; i < 3; i++) {
			std::cout << ".";
			Sleep(100);
		}
	} while (rpta != 5);
	/*VOLVER A LA PANTALLA DE INICIO*/
}

int main() {
	/*PANTALLA DE INICIO*/
	MENU_CLIENTES();
	
	
	

}
