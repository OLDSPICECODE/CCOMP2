#include<iostream>
#include<random>
#include<time.h>

using namespace std;

void solution(int* tablero, int tam) {
	int* safe = &tablero[0];
	int* end = &tablero[(tam * tam) - 1];
	int ord = 1;
	while (safe < end) {
		*safe = ord;
		safe += 1;
		ord += 1;
	}
	*safe = NULL;
}

void desordenar(int* tablero, int tam) {
	srand(time(NULL));
	int* safe = &tablero[0];
	int* comprobar = &tablero[0];
	int* end = &tablero[(tam * tam) - 1];
	bool validar = false;
	while (safe < end) {
		*safe = (rand() % ((tam * tam) - 1)) + 1;
		while (comprobar < safe) {
			while (*comprobar == *safe) {
				*safe = (rand() % ((tam * tam) - 1)) + 1;
				validar = true;
			}
			comprobar += 1;
			if (validar) {
				comprobar = &tablero[0];
				validar = false;
			}

		}
		comprobar = &tablero[0];
		safe += 1;
	}
	*safe = NULL;
}

void mojang() {
	bool gano = false;
	int num = 1;
	int tam;
	char mov;
	cout << "dificultad del 1 al 10 escriba el numero: ";
	cin >> tam;
	int* tablero = new int[tam * tam];
	int* sol = new int[tam * tam];
	solution(sol, tam);
	int* safe_sol = &sol[0];
	int* safe = &tablero[0];
	int* end = &tablero[(tam * tam) - 1];
	int aux;
	int index = 0;
	desordenar(tablero, tam);
	while (!gano) {
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam; j++) {
				cout << "[" << *safe << "]";
				safe += 1;
			}
			cout << endl;
		}
		cout << "movimiento: [w/a/s/d] ";
		cin >> mov;
		safe = &tablero[0];
		while (*safe != NULL) {
			safe += 1;
			index += 1;
		}
		if (mov == 'w') {
			if (tablero <= (tablero + (index - tam))) {
				*safe = *(tablero + (index - tam));
				*(tablero + (index - tam)) = NULL;
			}
		}
		if (mov == 's') {
			if ((tablero + (index + tam)) <= end) {
				*safe = *(tablero + (index + tam));
				*(tablero + (index + tam)) = NULL;
			}
		}
		if (mov == 'a') {
			if (index % tam != 0) {
				*safe = *(tablero + (index - 1));
				*(tablero + (index - 1)) = NULL;
			}
		}
		if (mov == 'd') {
			if (((index + 1) % tam) != index % tam != 0) {
				*safe = *(tablero + (index + 1));
				*(tablero + (index + 1)) = NULL;
			}
		}
		safe = &tablero[0];
		index = 0;
		while (safe <= (tablero + ((tam * tam) - 1))) {
			if (*safe == *sol) {
				gano = true;
			}
			else {
				gano = false;
				break;
			}
			safe += 1;
			sol += 1;
		}
		safe = &tablero[0];
		index = 0;
		sol = safe_sol;
		if (gano) {
			cout << endl << "GANASTE DUDE" << endl;
		}
	}
}