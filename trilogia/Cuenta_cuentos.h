#include <iostream>

using namespace std;

void cookie_monster(long long int cookie) {
	//no quiero hacer tantos ifs pero no encuentro otra manera T_T
	string numeros[19] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez","once","doce","trece","catorce","quince","dieziseis","diesisiete","diesiocho","diesinueve" };
	string completos[8] = { "veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa" };
	string faltante[8] = { "veinti","treinta y ","cuarenta y ","cincuenta y ","sesenta y ","setenta y ", "ochenta y ","noventa y " };
	string centenares[8] = { "dosientos ","tresientos ","cuatrocientos ","quinientos ","seisientos ","setecientos ","ochocientos ","novecientos " };
	int aux = 0;
	while (cookie > 0) {
		if (cookie < 20) {
			cout << numeros[(cookie - 1)];
			cookie = 0;
		}
		if (cookie >= 20 && cookie < 100) {
			while (cookie > 10) {
				cookie -= 10;
				aux += 1;
			}
			if (cookie == 0) {
				cout << completos[aux - 2];
			}
			else if (cookie != 0) {
				cout << faltante[aux - 2] << numeros[cookie - 1];
			}
			cookie = 0;
			aux = 0;
		}
		if (cookie == 100) {
			cout << "cien";
			cookie -= 100;
		}
		if (cookie > 100 && cookie < 200) {
			cout << "ciento ";
			cookie -= 100;
		}
		if (cookie >= 200 && cookie < 1000) {
			while (cookie >= 100) {
				cookie -= 100;
				aux += 1;
			}
			cout << centenares[aux - 2];
			aux = 0;
		}
		if (cookie == 1000) {
			cout << "mil";
			cookie -= 1000;
		}
		if (cookie > 1000 && cookie < 20000) {
			while (cookie >= 1000) {
				cookie -= 1000;
				aux += 1;
			}
			if (aux == 1) {
				cout << "un mil ";
			}
			else {
				cout << numeros[aux - 1] << "mil ";
				aux = 0;
			}
		}
		if (cookie >= 20000 && cookie < 100000) {
			while (cookie >= 10000) {
				cookie -= 10000;
				aux += 1;
			}
			if (cookie < 1000) {
				cout << completos[aux - 2] << "mil ";
				aux = 0;
			}
			else if (cookie >= 1000) {
				cout << faltante[aux - 2];
				aux = 0;
				while (cookie >= 1000) {
					cookie -= 1000;
					aux += 1;
				}
				if (aux == 1) {
					cout << "un mil ";
				}
				else {
					cout << numeros[aux - 1] << "mil ";
					aux = 0;
				}
			}
		}
		if (cookie >= 100000 && cookie < 200000) {
			cookie -= 100000;
			if (cookie < 1000) {
				cout << "cien mil ";
			}
			else {
				cout << "ciento ";
			}
		}
		if (cookie >= 200000 && cookie < 1000000) {
			while (cookie >= 100000) {
				cookie -= 100000;
				aux += 1;
			}
			if (cookie < 1000) {
				cout << centenares[aux - 2] << " mil ";
			}
			else {
				cout << centenares[aux - 2];
			}
			aux = 0;
		}
		if (cookie >= 1000000 && cookie < 20000000) {
			while (cookie >= 1000000) {
				cookie -= 1000000;
				aux += 1;
			}
			if (aux == 1) {
				cout << "un millon ";
			}
			else {
				cout << numeros[aux - 1] << "millones ";
			}
			aux = 0;
		}
		if (cookie >= 20000000 && cookie < 100000000) {
			while (cookie >= 10000000) {
				cookie -= 10000000;
				aux += 1;
			}
			if (cookie < 1000000) {
				cout << completos[aux - 2] << "mil ";
				aux = 0;
			}
			else if (cookie >= 1000000) {
				cout << faltante[aux - 2];
				aux = 0;
				while (cookie >= 1000000) {
					cookie -= 1000000;
					aux += 1;
				}
				if (aux == 1) {
					cout << "un millones ";
				}
				else {
					cout << numeros[aux - 1] << " millones ";
					aux = 0;
				}
			}
		}
		if (cookie >= 100000000 && cookie < 1000000000) {
			while (cookie >= 100000000) {
				cookie -= 100000000;
				aux += 1;
			}
			if (aux == 1) {
				if (cookie >= 1000000) {
					cout << "ciento ";
				}
				else {
					cout << "cien millones ";
				}
			}
			else {
				if (cookie >= 1000000) {
					cout << centenares[aux - 2];
				}
				else {
					cout << centenares[aux - 2] << " millones";
				}
			}
			aux = 0;
		}
		if (cookie >= 1000000000 && cookie < 20000000000) {
			while (cookie >= 1000000000) {
				cookie -= 1000000000;
				aux += 1;
			}
			if (aux == 1) {
				cout << "un billon ";
			}
			else {
				cout << numeros[aux - 1] << "billones ";
			}
			aux = 0;
		}
		if (cookie >= 20000000000 && cookie < 100000000000) {
			while (cookie >= 10000000000) {
				cookie -= 10000000000;
				aux += 1;
			}
			if (cookie >= 1000000000) {
				cout << faltante[aux - 2];
			}
			else {
				cout << completos[aux - 2] << " billones ";
			}
			aux = 0;
		}
		if (cookie >= 100000000000 && cookie < 1000000000000) {
			while (cookie >= 100000000000) {
				cookie -= 100000000000;
				aux += 1;
			}
			if (aux == 1) {
				if (cookie > 1000000000) {
					cout << "ciento ";
				}
				else {
					cout << "cien billones ";
				}
			}
			else {
				if (cookie > 1000000000) {
					cout << centenares[aux - 2];
				}
				else {
					cout << centenares[aux - 2] << "billones";
				}
			}
			aux = 0;
		}
	}

}

int pot_of_cookies() {
	long long int cookie;
	cout << "ingresa el numero: ";
	cin >> cookie;
	cookie_monster(cookie);
	return 0;
}