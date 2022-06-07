#include <iostream>

#include "CLIENTES_V.h"

CLIENTES_V cliente_vector;

void MENU_CLIENTES()
{
	Beep(480, 200);
	system("cls");

	Cliente cliente;

	int rpta;
	do
	{
		system("cls");
		rpta = cliente.pantalla_cliente();
		Cliente *cliente = new Cliente();

		switch (rpta)
		{
		case 1:
			char rpta_1;
			do
			{
				system("cls");
				Beep(480, 200);
				cliente_vector.vector_add(*cliente->cliente_agregar());
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_1;
			} while (std::toupper(rpta_1) == 'S');
			break;
		case 2:
			char rpta_2;
			do
			{
				system("cls");
				Beep(480, 200);
				cliente_vector.cliente_modificar();
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_2;
			} while (std::toupper(rpta_2) == 'S');
			break;
		case 3:
			char rpta_3;
			do
			{
				system("cls");
				Beep(480, 200);
				cliente_vector.cliente_eliminar();
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_3;
			} while (std::toupper(rpta_3) == 'S');
		case 4:
			char rpta_4;
			do
			{
				system("cls");
				Beep(480, 200);
				cliente_vector.cliente_consultar();
				std::cout << "Desea continuar? (S/N)\n";
				std::cin >> rpta_4;
			} while (std::toupper(rpta_4) == 'S');
			break;

		default:
			break;
		}

		std::cout << "Regresando al inicio";
		for (int i = 0; i < 3; i++)
		{
			std::cout << ".";
			Sleep(100);
		}
		system("cls");
	} while (rpta != 5);
	/*VOLVER A LA PANTALLA DE INICIO*/
}

int main()
{
	MENU_CLIENTES();
}