#pragma once

#include <random>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

class Cliente {
private:
	char codigo[10];
	char* generar_codigo() {
		srand(time(0));
		Sleep(1000);
		char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		char* codigo = new char[10];
		for (int i = 0; i < 9; i++) {
			codigo[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
		}
		codigo[9] = '\0';
		return codigo;
	}

	char nombre[51];
	char apellido[51];
	char sexo;
	char tarjeta_ventaPlus;
	char registrado_web;

	char correo[101];
	char* generar_correo() {
		if (registrado_web == 'S') {
			strcpy_s(correo, apellido);
			strcat_s(correo, ".");
			strcat_s(correo, nombre);
			strcat_s(correo, "@hotmail.com");
			return correo;
		}
		char* err = new char[2];
		err[0] = '-';
		err[1] = '\0';
		return err;
	}

	char contrasena[10];
	char* generar_contrasena() {
		if (registrado_web == 'S') {
			char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			char* contrasena = new char[10];
			for (int i = 0; i < 3; i++) {
				contrasena[i] = apellido[i];
			}
			for (int i = 3; i < 6; i++) {
				contrasena[i] = nombre[i - 3];
			}
			for (int i = 6; i < 9; i++) {
				contrasena[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
			}
			contrasena[9] = '\0';
			return contrasena;
		}
		char* err = new char[2];
		err[0] = '-';
		err[1] = '\0';
		return err;
	}

	char celular[10];
	char* generar_celular() {
		if (registrado_web == 'S') {
			char numeros[] = "0123456789";
			char* celular = new char[10];
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					celular[i] = '9';
				}
				else {
					celular[i] = numeros[rand() % (sizeof(numeros) - 1)];
				}
			}
			celular[9] = '\0';
			return celular;
		}
		char* err = new char[2];
		err[0] = '-';
		err[1] = '\0';
		return err;
	}

	int DNI;
	int monto_consumido_semanal;

public:
	
	Cliente(char codigo[10], char nombre[50], char apellido[51], char sexo, char tarj_vp, char registrado_web, char correo[101], char contrasena[10], char celular[10], int DNI, int monto_sem) {
		strcpy_s(this->codigo, codigo);
		strcpy_s(this->nombre, nombre);
		strcpy_s(this->apellido, apellido);
		this->sexo = sexo;
		tarjeta_ventaPlus = tarj_vp;
		this->registrado_web = registrado_web;
		strcpy_s(this->correo, correo);
		strcpy_s(this->contrasena, contrasena);
		strcpy_s(this->celular, celular);
		this->DNI = DNI;
		monto_consumido_semanal = monto_sem;
	}
	
	//Setters
	void set_nombre(char nombre[51]) {
		strcat_s(this->nombre, nombre);
	}
	
	void set_apellido(char apellido[51]) {
		strcat_s(this->apellido, apellido);
	}

	void set_sexo(char sexo) {
		this->sexo = sexo;
	}
	
	void set_tarjeta(char tj_vp) {
		tarjeta_ventaPlus = tj_vp;
	}
	
	void set_registrado(char registrado_web) {
		this->registrado_web = registrado_web;
	}

	void set_DNI(int DNI) {
		this->DNI = DNI;
	}

	void set_monto_semanal(int monto_s) {
		monto_consumido_semanal = monto_s;
	}

	//Getters
	char* get_nombre() { return nombre; }
	
	char* get_apellido() { return apellido; }

	char get_sexo() { return sexo; }
	
	char get_tarjeta() { return tarjeta_ventaPlus; }

	char get_registrado_web() { return registrado_web; }

	char* get_correo() { return generar_correo(); }
	
	char* get_contrasena() { return generar_contrasena(); }

	char* get_celular() { return generar_celular(); }
	
	int get_DNI() { return DNI; }

	int get_monto_semanal() { return monto_consumido_semanal; }
	
	char* get_codigo() { return generar_codigo(); }
};