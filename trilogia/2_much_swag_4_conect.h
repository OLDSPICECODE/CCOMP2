#include<iostream>
#include<random>
#include<time.h>

using namespace std;

bool empate(char* tablero) {
	char* safe = &tablero[0];
	char* end = &tablero[41];
	bool emp = false;
	while (safe <= end) {
		if (*safe == 'X' || *safe == 'O') {
			emp = true;
		}
		else {
			emp = false;
			break;
		}
		safe += 1;
	}
	return emp;
}

bool validar_X(char* tablero) {
	char* safe = &tablero[0];
	char* end = &tablero[41];
	int columnas = 0;
	bool win = true;
	while (safe < &tablero[3]) {
		if (*(safe + columnas) == 'X' && *(safe + 1 + columnas) == 'X' && *(safe + 2 + columnas) == 'X' && *(safe + 3 + columnas) == 'X') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas > 35) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	if (win) {
		return win;
	}
	safe = &tablero[0];
	while (safe + 21 <= end) {
		if (*(safe) == 'X' && *(safe + 7) == 'X' && *(safe + 14) == 'X' && *(safe + 21) == 'X') {
			win = true;
			break;
		}
		else {
			win = false;
		}
		safe += 1;
	}
	if (win) {
		return win;
	}
	safe = &tablero[0];
	while (safe <= &tablero[3]) {
		if (*(safe + columnas) == 'X' && *(safe + columnas + 8) == 'X' && *(safe + columnas + 16) == 'X' && *(safe + columnas + 24) == 'X') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas >= 21) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	if (win) {
		return win;
	}
	columnas = 0;
	safe = &tablero[3];
	while (safe < &tablero[7]) {
		if (*(safe + columnas) == 'X' && *(safe + columnas + 6) == 'X' && *(safe + columnas + 12) == 'X' && *(safe + columnas + 18) == 'X') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas >= 21) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	return win;
}

bool validar_O(char* tablero) {
	char* safe = &tablero[0];
	char* end = &tablero[41];
	int columnas = 0;
	bool win = true;
	while (safe < &tablero[3]) {
		if (*(safe + columnas) == 'O' && *(safe + 1 + columnas) == 'O' && *(safe + 2 + columnas) == 'O' && *(safe + 3 + columnas) == 'O') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas > 35) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	if (win) {
		return win;
	}
	safe = &tablero[0];
	while (safe + 21 <= end) {
		if (*(safe) == 'O' && *(safe + 7) == 'O' && *(safe + 14) == 'O' && *(safe + 21) == 'O') {
			win = true;
			break;
		}
		else {
			win = false;
		}
		safe += 1;
	}
	if (win) {
		return win;
	}
	safe = &tablero[0];
	while (safe <= &tablero[3]) {
		if (*(safe + columnas) == 'O' && *(safe + columnas + 8) == 'O' && *(safe + columnas + 16) == 'O' && *(safe + columnas + 24) == 'O') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas >= 21) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	if (win) {
		return win;
	}
	columnas = 0;
	safe = &tablero[3];
	while (safe < &tablero[7]) {
		if (*(safe + columnas) == 'O' && *(safe + columnas + 6) == 'O' && *(safe + columnas + 12) == 'O' && *(safe + columnas + 18) == 'O') {
			win = true;
			break;
		}
		else {
			win = false;
			columnas += 7;
			if (columnas >= 21) {
				columnas = 0;
				safe += 1;
			}
		}
	}
	return win;
}


void conecta_cuatro() {
	int momento;
	bool turno = true;
	char* tablero = new char[42];
	char* end = &tablero[42];
	char* safe = &tablero[0];
	for (int i = 0; i < 42; i++) {
		*safe = ' ';
		safe += 1;
	}
	while (true) {
		safe = &tablero[0];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				cout << "[" << *safe << "]";
				safe += 1;
			}
			cout << endl;
		}
		cout << " 0  1  2  3  4  5  6 " << endl;
		if (validar_X(tablero)) {
			cout << "X gana FELICIDADES" << endl;
			break;
		}
		if (validar_O(tablero)) {
			cout << "O gana FELICIDADES" << endl;
			break;
		}
		if (empate(tablero)) {
			cout << "empate intentar otra vez" << endl;
			break;
		}
		safe = &tablero[0];
		if (turno) {
			cout << "X juega ingresa el lugar: ";
			cin >> momento;
			while (true) {
				if ((safe + momento + 7) >= end) {
					break;
				}
				if (*(safe + momento + 7) == 'X') {
					break;
				}
				if (*(safe + momento + 7) == 'O') {
					break;
				}
				else {
					safe += 7;
				}
			}
			if (*(safe + momento) != 'O')
				*(safe + momento) = 'X';
			turno = false;
		}
		else {
			cout << "O juega ingresa el lugar: ";
			cin >> momento;
			while (true) {
				if ((safe + momento + 7) >= end) {
					break;
				}
				if (*(safe + momento + 7) == 'X') {
					break;
				}
				if (*(safe + momento + 7) == 'O') {
					break;
				}
				else {
					safe += 7;
				}
			}
			if (*(safe + momento) != 'X')
				*(safe + momento) = 'O';
			turno = true;
		}
	}
}
#pragma once
