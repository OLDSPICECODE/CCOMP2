#include<time.h>
#include<iostream>

using namespace std;

void show_me_the_move(int* puntero, int tam) {
	int* finto = &puntero[tam - 1];
	for (puntero; puntero <= finto; puntero++) {
		cout << *(puntero) << " ";
	}
	cout << endl;
}

void control(int* el_int, int* el_Ou1, int* el_ou2, int tam) {
	int* fin_1 = &el_int[tam - 1];
	int* fin_2 = &el_Ou1[tam - 1];
	int* fin_3 = &el_ou2[tam - 1];
	int* safe_1 = &el_Ou1[0];
	int* safe_2 = &el_ou2[0];
	for (el_int; el_int <= fin_1; el_int++) {
		if (*(el_int) % 2 == 0) {
			*(el_Ou1) = *(el_int);
			el_Ou1 += 1;
		}
		else {
			*(el_ou2) = *(el_int);
			el_ou2 += 1;
		}
	}
	for (el_Ou1; el_Ou1 <= fin_2; el_Ou1++) {
		*(el_Ou1) = 0;
	}
	for (el_ou2; el_ou2 <= fin_3; el_ou2++) {
		*(el_ou2) = 0;
	}
	el_Ou1 = safe_1;
	el_ou2 = safe_2;
	show_me_the_move(el_Ou1, 5);
	show_me_the_move(el_ou2, 5);
}

void run() {
	srand(time(NULL));
	int input[5];
	int* p_input = &input[0];
	int* fin = &input[4];
	for (p_input; p_input <= fin; p_input++) {
		*(p_input) = rand();
	}
	p_input = &input[0];
	show_me_the_move(p_input, 5);
	int output_1[5];
	int* p_out_1 = &output_1[0];
	int output_2[5];
	int* p_out_2 = &output_2[0];
	int tam = (sizeof(input) / sizeof(int));
	control(p_input, p_out_1, p_out_2, 5);

}
