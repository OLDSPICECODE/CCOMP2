#include"coctel de punteros.h"

void polimerizacion(int* par, int* impar, int* completo, int tam) {
	int* fin = &par[tam - 1];
	int* fin_2 = &impar[tam - 1];
	int* fin_3 = &completo[(tam * 2) - 1];
	while (completo < fin_3) {
		if (*(par) < *(impar)) {
			*(completo) = *(par);
			par += 1;
		}
		else {
			*(completo) = *(impar);
			impar += 1;
		}
		cout << *completo << " ";
		completo += 1;
		if (par > fin) {
			while (completo <= fin_3) {
				*(completo) = *(impar);
				impar += 1;
				cout << *completo << " ";
				completo += 1;
			}
		}
		if (impar > fin_2) {
			while (completo <= fin_3) {
				*(completo) = *(par);
				par += 1;
				cout << *completo << " ";
				completo += 1;
			}
		}
	}
}

void yugi_oh() {
	srand(time(NULL));
	int tam = 8;
	int num;
	int* par = new int[tam];
	int cont = 0;
	int* aux = &par[0];
	int* fin = &par[tam - 1];
	while (par <= fin) {
		num = rand();
		while (num % 2 != 0) {
			num = rand();
		}
		if (cont > 0) {
			while (aux != NULL) {
				if (aux < par) {
					num = rand();
					while (num % 2 != 0) {
						num = rand();
					}
				}
				aux += 1;
			}
		}
		*(par) = num;
		par += 1;
		cont += 1;
	}
	cont = 0;
	while (cont != tam - 1) {
		par -= 1;
		cont += 1;
	}
	//la funcion coctel es el cocktail sort que esta en el archivo coctel de punteros.h 
	coctel(par, tam);
	cout << endl;
	cont = 0;
	int* impar = new int[tam];
	aux = &impar[0];
	fin = &impar[tam - 1];
	while (impar <= fin) {
		num = rand();
		while (num % 2 < 1) {
			num = rand();
		}
		if (cont > 0) {
			while (aux < par) {
				if (*aux == num) {
					num = rand();
					while (num % 2 < 1) {
						num = rand();
					}
				}
				aux += 1;
			}
		}
		*(impar) = num;
		impar += 1;
		cont += 1;
	}
	cont = 0;
	while (cont != tam - 1) {
		impar -= 1;
		cont += 1;
	}
	//la funcion coctel es el cocktail sort que esta en el archivo coctel de punteros.h 
	coctel(impar, tam);
	cout << endl;
	int* los_zetas = new int[tam * 2];

	polimerizacion(par, impar, los_zetas, tam);
}