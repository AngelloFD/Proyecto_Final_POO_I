#pragma once
#include <iostream>

class Encriptscii {
public:
	Encriptscii();
	
	std::string encriptar(std::string texto){
		// Reemplazar cada letra con su valor numerico ascii y cada numero con su valor de letra ascii
		std::string new_texto;
		for (char c : texto) {
			if (isalpha(c)) {
				c = (c - 'a' + 13) % 26 + 'a';
				new_texto += c;
			}
			else if (isdigit(c)) {
				c = (c - '0' + 13) % 10 + '0';
				new_texto += c;
			}
		}
		return new_texto;
	}

	std::string desencriptar(std::string encript_texto) {
		std::string old_texto;
		for (char c : encript_texto) {
			if (isalpha(c)) {
				c = (c - 'a' - 13) % 26 + 'a';
				old_texto += c;
			}
			else if (isdigit(c)) {
				c = (c - '0' - 13) % 10 + '0';
				old_texto += c;
			}
		}
		return old_texto;
	}
};
