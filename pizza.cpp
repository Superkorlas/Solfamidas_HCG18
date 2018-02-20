#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
	
	vector<vector<char> > pizza;
	vector<char> linea;
	char c;
	int filas, columnas, minimo, maximo;
	ifstream in( "example.in" );


	in >> filas;
	in >> columnas;
	in >> minimo;
	in >> maximo;

	for ( int i = 0; i < filas; i++ ){
		linea.clear();
		for ( int j = 0; j < columnas; j++ ){
			in >> c;
			linea.push_back( c );
		}
		pizza.push_back( linea );
	}


	for ( int i = 0; i < filas; i++ ){
		for ( int j = 0; j < columnas; j++ )
			cout << pizza[i][j];
		cout << endl;
	}
}