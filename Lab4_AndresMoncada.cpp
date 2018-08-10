#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void ej1();
int** genMatriz(int);
void print(int**,int);

int main(){
	srand(time(NULL));
	int op;
	do{
	cout << "1. Cofactores" << endl << "2. Reversi" << endl << "0. Salir" << endl;
	cin >> op;
	ej1();
	}while(op != 0);
	return 0;
}

void ej1(){
	int n,f,c;
	cout << "Ingrese un entero positivo: ";
	cin >> n;
	if (n > 1){
		int** matriz = genMatriz(n);
		int cf[n-1][n-1];
		bool loop = true;
		print(matriz,n);
		while(loop){
			cout << "Ingrese un número de fila: ";
			cin >> f;
			cout << "Ingrese un número de columna: ";
			cin >> c;
			if(f >= 0 && f < n && c >= 0 && c < n)
				loop = false;
			else
				cout << "Fila o columa fuera del rango 0-" << (n-1) << endl;
		}
		for (int i = 0; i < n; i++){
			delete[] matriz[i];
		}
		delete[] matriz;
	}
	else
		cout << "Valor no válido" << endl;
}

int** genMatriz(int n){
	int** m = new int*[n];
	for(int i = 0; i < n; i++){
		m[i] = new int[n];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			m[i][j] = rand() % 6 + 1;
		}
	}
	return m;
}

void print(int** m, int n){
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
