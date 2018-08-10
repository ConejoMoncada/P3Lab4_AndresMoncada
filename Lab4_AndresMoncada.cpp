#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void ej1();
int** genMatriz(int);
void print(int**,int);
void print(char**);
void ej2();
char** genChar();

int main(){
	srand(time(NULL));
	int op;
	do{
		cout << "1. Cofactores" << endl << "2. Reversi" << endl << "0. Salir" << endl << "Ingrese una opción: ";
		cin >> op;
		switch (op){
			case 1: ej1();
				break;
			case 2: ej2();
				break;	
		}
	}while(op != 0);
	return 0;
}

void ej1(){
	int n,f,c;
	cout << "Ingrese un entero positivo: ";
	cin >> n;
	if (n > 1){
		int** matriz = genMatriz(n);
		char resp;
		print(matriz,n);
		do{//para usar la misma matriz
			bool loop = true;
			//validar fila y columna
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
			bool s; //símbolo +-
			if(f % 2 == 0){
				if(c % 2 == 0)
					s = true;
				else
					s = false;
			}
			else{
				if(c % 2 == 0)
					s = false;
				else
					s = true;
			}
			cout << endl;
			//imprimir matriz nueva
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (i != f){
						if (j != c){
							cout << matriz[i][j] << " ";
						}
					}
				}
				if(i != f)
					cout << endl;
			}
			cout << endl;
			if(s)
				cout << "+";
			else
				cout << "-";
			cout << matriz[f][c] << endl;
			cout << "Continuar con la misma matriz? [S/N]: ";
			cin >> resp;
		}while (resp == 's' || resp == 'S');
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

void print(char** mc){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << mc[i][j] << " ";
		}
		cout << endl;
	}
}

void ej2(){
	char** mc; //matriz de char
	mc = genChar();
	print(mc);
	for(int i = 0; i < 9; i++){
		delete[] mc[i];
	}
	delete[] mc;
}

char** genChar(){
	char ** mc = new char* [9];
	for (int i = 0; i < 9; i++){
		mc[i] = new char[9];
	}
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			mc[i][j] = '.';
		}
	}
	mc[0][1] = 'a';
	mc[0][2] = 'b';
	mc[0][3] = 'c';
	mc[0][4] = 'd';
	mc[0][5] = 'e';
	mc[0][6] = 'f';
	mc[0][7] = 'g';
	mc[0][8] = 'h';
	mc[1][0] = '1';
	mc[2][0] = '2';
	mc[3][0] = '3';
	mc[4][0] = '4';
	mc[5][0] = '5';
	mc[6][0] = '6';
	mc[7][0] = '7';
	mc[8][0] = '8';
	mc[4][4] = 'N';
	mc[5][5] = 'N';
	mc[4][5] = 'B';
	mc[5][4] = 'B';

	return mc;
}
