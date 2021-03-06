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
bool validar(char**,int,int);
//para las siguientes funciones c = cambiar, ar = arriba, ab = abajo, d = derecha, i = izquierda
bool car(char**,int,int,bool);
bool cab(char**,int,int,bool);
bool cd(char**,int,int,bool);
bool ci(char**,int,int,bool);
bool card(char**,int,int,bool);
bool cari(char**,int,int,bool);
bool cabd(char**,int,int,bool);
bool cabi(char**,int,int,bool);

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
	bool turno = true;
	bool fin = false;
	int f, c; //fila y columna
	int el = 60;//espacios libres
	while (!fin){
		print(mc);
		cout << "Ingrese 0 y 0 para terminar el juego"<< endl << "Turno de ";
		if(turno)
			cout << "X";
		else
			cout << "O";
		cout << endl << "Ingrese una fila: ";
		cin >> f;
		cout << "Ingrese una columna: ";
		cin >> c;
		if (f == 0 && c == 0)
			fin = true;
		if(validar(mc,f,c)){
			if(turno)
				mc[f][c] = 'X';
			else
				mc[f][c] = 'O';
			car(mc,f-1,c,turno);
			cab(mc,f+1,c,turno);
			cd(mc,f,c+1,turno);
			ci(mc,f,c-1,turno);
			card(mc,f-1,c+1,turno);
			cari(mc,f-1,c-1,turno);
			cabd(mc,f+1,c+1,turno);
			cabi(mc,f+1,c-1,turno);
			turno = !turno;
			el--;
		}
		if(el == 0)
			fin = true;
		else if(!fin)
			cout << "Posición no válida";
	}
	int cx = 0;
	int co = 0;
	for(int i = 1; i < 9; i++){
		for (int j = 1; j < 9; j++){
			if(mc[i][j] == 'X')
				cx++;
			if(mc[i][j] == 'O')
				co++;
		}
	}
	if(cx > co)
		cout << "Ganó X";
	if(co > cx)
		cout << "Gano O";
	if(co == cx)
		cout << "Empate";
	cout << endl;
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
	mc[0][0] = ' ';
	mc[0][1] = '1';
	mc[0][2] = '2';
	mc[0][3] = '3';
	mc[0][4] = '4';
	mc[0][5] = '5';
	mc[0][6] = '6';
	mc[0][7] = '7';
	mc[0][8] = '8';
	mc[1][0] = '1';
	mc[2][0] = '2';
	mc[3][0] = '3';
	mc[4][0] = '4';
	mc[5][0] = '5';
	mc[6][0] = '6';
	mc[7][0] = '7';
	mc[8][0] = '8';
	mc[4][4] = 'X';
	mc[5][5] = 'X';
	mc[4][5] = 'O';
	mc[5][4] = 'O';

	return mc;
}

bool validar(char** mc, int f, int c){
      bool v = false;
      if (f > 0 && c > 0 && f <= 8 && c <= 8){
	      if(mc[f][c] == '.'){
		      if(f < 8){
			      if(mc[f+1][c] == 'X' || mc[f+1][c] == 'O'){
				      v = true;
			      }//abajo
			      else if(c < 8){
				      if(mc[f+1][c+1] == 'X' || mc[f+1][c+1] == 'O')
					      v = true;
			      }//abajo derecha
			      else if(c > 1){
				      if(mc[f+1][c-1] == 'X' || mc[f+1][c-1] == 'O')
					      v = true;
			      }//abajo izquierda
		      }//no está en la fila de abajo
		      if(f > 1){
			      if(mc[f-1][c] == 'X' || mc[f-1][c] == 'O'){
				      v =true;
			      }//arriba
			      else if(c < 8){
				      if(mc[f-1][c+1] == 'X'|| mc[f-1][c+1] == 'O')
					      v = true;
			      }//arriba derecha
			      else if(c > 1){
				      if(mc[f-1][c-1] == 'X'|| mc[f-1][c-1] == 'O')
					      v = true;
			      }//arriba izquierda
		      }//no está en la fila de arriba
		      if(c < 8){
			      if(mc[f][c+1] == 'X' || mc[f][c+1] == 'O')
				      v = true;
		      }//derecha
		      if(c > 1){
			      if(mc[f][c-1] == 'X' || mc[f][c-1] == 'O')
				      v = true;
		      }//izquierda
	      }//espacio no ocupado
      }//f,c {1-8}
      else
	      cout << "Fila o columna fuera de rango" << endl;
      return v;
}

bool car(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f > 1){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = car(mc,f-1,c,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = car(mc,f-1,c,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}

bool cab(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f < 8){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = cab(mc,f+1,c,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = cab(mc,f+1,c,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}
bool ci(char** mc, int f, int c, bool t){
	bool ret = false;
	if (c > 1){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = ci(mc,f,c-1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = ci(mc,f,c-1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}

bool cd(char** mc, int f, int c, bool t){
	bool ret = false;
	if (c < 8){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = cd(mc,f,c+1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = cd(mc,f,c+1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}

bool cari(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f > 1 && c > 1){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = cari(mc,f-1,c-1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = cari(mc,f-1,c-1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}
bool card(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f > 1 && c < 8){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = card(mc,f-1,c+1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = card(mc,f-1,c+1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}
bool cabi(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f < 8 && c > 1){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = cabi(mc,f+1,c-1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = cabi(mc,f+1,c-1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}
bool cabd(char** mc, int f, int c, bool t){
	bool ret = false;
	if (f < 8 && c < 8){
		if (t){
			if(mc[f][c] == 'X')
				ret = true;
			else if(mc[f][c] == 'O')
				ret = cabd(mc,f+1,c+1,t);
			if(ret)
				mc[f][c] = 'X';
		}
		else{
			if(mc[f][c] == 'O')
				ret = true;
			else if(mc[f][c] == 'X')
				ret = cabd(mc,f+1,c+1,t);
			if(ret)
				mc[f][c] = 'O';
		}
	}
	return ret;
}

