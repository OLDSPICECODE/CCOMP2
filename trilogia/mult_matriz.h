#include <iostream>

using namespace std;

void print_matriz(float a[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << "[";
		for (int j = 0; j < 3; j++) {
			cout << " " << a[i][j] << " ";
		}
		cout << "]" << endl;
	}
}

void multp_matrices(float a[3][3], float b[3][3]) {
	float result[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result[i][j] = (result[i][j] + (a[i][k] * b[k][j]));
			}
		}
	}
	print_matriz(result);
}

int prior() {
	float a[3][3] = { {5,-1,1},{0,4,1},{4,1,-2}};
	float b[3][3] = { {0,-2,1},{2,0,-1},{-1,1,0} };
	multp_matrices(a, b);
	return 0;
}