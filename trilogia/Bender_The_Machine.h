#include <iostream>

using namespace std;


void bender(float a) {
	float centavos[3] = { 0.50,0.20,0.10 };
	int soles_S[3] = { 5,2,1 };
	int soles_M[3] = { 50,20,10 };
	int soles_L[2] = { 200,100 };
	int avaritia = 0;
	cout << "cambio:" << endl;
	for (int i = 0; i < 2; i++) {
		avaritia = 0;
		while (a >= soles_L[i]) {
			a -= soles_L[i];
			avaritia += 1;
		}
		cout << "en billetes de " << soles_L[i] << " son " << avaritia << endl;
	}

	for (int i = 0; i < 3; i++) {
		avaritia = 0;
		while (a >= soles_M[i]) {
			a -= soles_M[i];
			avaritia += 1;
		}
		cout << "en billetes de " << soles_M[i] << " son " << avaritia << endl;
	}

	for (int i = 0; i < 3; i++) {
		avaritia = 0;
		while (a >= soles_S[i]) {
			a -= soles_S[i];
			avaritia += 1;
		}
		cout << "en monedas de " << soles_S[i] << " son " << avaritia << endl;
	}

	for (int i = 0; i < 3; i++) {
		avaritia = 0;
		while (a >= centavos[i]) {
			a -= centavos[i];
			avaritia += 1;
		}
		cout << "en monedas de " << centavos[i] << " son " << avaritia << endl;
	}
}

void change() {
	float lana;
	cout << "ingrese el monto: ";
	cin >> lana;
	bender(lana);
}