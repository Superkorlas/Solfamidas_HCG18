#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
	
	vector<vector<char> > pizza;
	char c;
	int filas, columnas, minimo, maximo;
	ifstream in( "example.in" );


	in >> filas;
	in >> columnas;
	vector<char> linea(columnas);
	in >> minimo;
	in >> maximo;

	for ( int i = 0; i < filas; i++ ){
		for ( int j = 0; j < columnas; j++ ){
			in >> c;
			linea[j] = c;
		}
		pizza.push_back( linea );
	}


	for ( int i = 0; i < filas; i++ ){
		for ( int j = 0; j < columnas; j++ )
			cout << pizza[i][j];
		cout << endl;
	}
}
