#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void imprimirMatriz(int**, int);
void Ruffini();
void Hamming();
int** inicializarMatriz(int);

int main ()
{
	int opcion;
	char resp = 'y';
	while (resp == 'y' || resp == 'Y')
	{
		cout << "Laboratorio 3" << endl << "Calvin Espinoza" << endl << endl;
		cout << "MENU" << endl << "1. Codigo de Hamming\n2. Teorema de Ruffini\n";
		cin >> opcion;
		
		if (opcion == 1)
		{
			cout << "CODIGO DE HAMMING\n\n";
			Hamming();			
		}
		
		if (opcion == 2){
			cout << "TEOREMA DE RUFFINI\n\n";
			Ruffini();
		}
	
		cout << "Desea continuar[y/n]: ";
		cin >> resp;	
	}
	
}

void Hamming()
{

	string bits;
	int d = 0;
	cout << "Introduzca los bits: ";
	cin >> bits;
	int P = 0;
	cout << bits;
	

	for (int i = 0; i < bits.size(); i++)
	{
		d++;
	} 
	cout << d;


	bool boolean = false;
	while (boolean == false){
		if (pow(2,P) >= d + P +1){
			boolean = true;
		} else {
			boolean = false;
		}	
		P++;

	}
	cout << P;

	cout << "Ya\n";
}

void Ruffini()
{
	int grado = 0;
	int valor;
	cout << "Ingrese el grado mas alto del polinomio: ";
	cin >> grado;
	vector <int**> vector;
	int num;

	int** mat = NULL;
	mat = inicializarMatriz(grado + 1);


	for(int j = 0; j < grado + 1; j++)
	{
		int value;
		if (j == 0)
		{
			for(int i = grado; i >= 0; i--)
			{
				
				cout << "Ingrese el polinomio x^" << i << endl;
				cin >> num;
				mat[0][grado - i] = num;
				mat[grado - i][1] = 0;
			}
			cout << "Ingrese a: ";
			cin >> valor;

			imprimirMatriz(mat, grado + 1);
			vector.push_back(mat);
		}
		else {
			for(int k = 0; k <= grado; k++)
			{
				if (k == 0)
				{
					mat[2][k] = mat[0][k];
				}
				else {
					mat[1][k] = mat[2][k-1] * valor;
					mat[2][k] = mat[0][k] + mat[1][k];
					
				}
				imprimirMatriz(mat, grado + 1);	
				cout << endl;
				
				vector.push_back(mat);	
			}
			cout << endl;
			
		}
					
		
	}
	cout << "El residuo es: " << mat[2][grado] << endl;

	for (int l = 0; l < vector.size(); l++)
	{
		imprimirMatriz(vector.at(l), grado + 1);
		cout << endl;
	}
}

void imprimirMatriz(int** mat, int size){
	for(int i = 0; i < 3; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << mat[i][j];
		}
		cout << endl;
	}
}

int** inicializarMatriz(int size){
	
	int** matriz = new int*[size];
	
	for (int i = 0; i < size; i++)
	{
		matriz[i] = new int[3];
	}
	return matriz;
}

