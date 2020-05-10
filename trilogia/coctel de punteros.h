#include"punt.h"
//#include"es_hora_del_du_du_du_dueloooo.h"

void coctel(int* arr, int tam) {
	bool swamper = true;
	int aux;
	int* start = &arr[0];
	int* safe = &arr[0];
	int* fin = &arr[tam - 1];
	int con = 0;
	while (swamper) {
		swamper = false;
		for (arr; arr < fin; arr++) {
			if (*(arr) >= *(arr + 1)) {
				aux = *(arr);
				*(arr) = *(arr + 1);
				*(arr + 1) = aux;
				swamper = true;
			}
		}
		if (!swamper) {
			break;
		}
		arr -= 1;
		swamper = false;
		for (arr; arr >= start; arr--) {
			if (*(arr) > * (arr + 1)) {
				aux = *(arr);
				*(arr) = *(arr + 1);
				*(arr + 1) = aux;
				swamper = true;
			}
		}
		start += 1;
	}
}

void mesero() {
	srand(time(NULL));
	int tam = 10;
	int* pa_ordenar = new int[tam];
	int* fin_1 = &pa_ordenar[tam];
	for (pa_ordenar; pa_ordenar < fin_1; pa_ordenar++) {
		*(pa_ordenar) = rand() % 100;
	}
	int cont = 0;
	while (cont != tam) {
		pa_ordenar -= 1;
		cont += 1;
	}
	for (pa_ordenar; pa_ordenar < fin_1; pa_ordenar++) {
		cout << *(pa_ordenar) << " ";
	}
	cont = 0;
	while (cont != tam) {
		pa_ordenar -= 1;
		cont += 1;
	}
	cout << endl;
	coctel(pa_ordenar, tam);

}