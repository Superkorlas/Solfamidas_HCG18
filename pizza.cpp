// g++ -g -o pichalol pizza.cpp
// Subido a github 13:38
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char> > pizza;
vector<pair<int, int> > pos_mushroom, pos_tomato;
int filas, columnas, ingredientes_minimos, cacho_maximo, num_mushroom = 0, num_tomato = 0;

/** Devuelve la distancia entre dos objetos (tomato, mushroom) */
int calcular_distancia(pair<int, int> obj1, pair<int, int> obj2) {
	int dist_horizontal = abs(obj1.first - obj2.first);
	int dist_vertical = abs(obj1.second - obj2.second);
	return dist_horizontal + dist_vertical;
}

/** Devuelve vector con las posiciones de los elementos cercanos que no sobrepasan el limite de distancia.
 * obj -> elemento del que queremos buscar los vecinos
 * pos -> posicion del elemento en el vector del ingrediente (pos_mushroom, pos_tomato)
 */
vector<pair<int, int> > buscar_cercanos (pair<int, int> obj, int pos) {
	vector<pair<int, int> > pos_cercanos;
	//Trabajamos con Tomates
	if (pizza[pos.first][pos.second] == 'T') {
		for (int i = pos; i < pos_tomato.size())
	} else {  //Trabajamos con Champiñones
		
	}
	return pos_cercanos;
}

vector<int> b_and_b(vector<pair<int, int>> & posiciones, int poda){
	
}

/**
 * Devuelve el vector solucion, calcula la poda, por la cual el algoritmo parará
 * cuando sobrepase ese número. También elige qué elemento está en minoría para
 * pasarselo al algorimo.
 */
vector<int> solucionar_problema(){
	int poda, best_case, worst_case, dimensiones = filas*columnas;
	if (num_tomato >= num_mushroom) {
		best_case = (num_mushroom * cachos_maximos) / ingredientes_minimos;
		best_case = (best_case > dimensiones) ? dimensiones : best_case;
		worst_case = (num_mushroom * 2);
		poda = (best_case + worst_case) / 2;
		return b_and_b(pos_tomato, poda);
	} else {
		best_case = (num_tomato * cachos_maximos) / ingredientes_minimos;
		best_case = (best_case > dimensiones) ? dimensiones : best_case;
		worst_case = (num_tomato * 2);
		poda = (best_case + worst_case) / 2;
		return b_and_b(pos_mushroom, poda);
	}
}

int main(){
	char c;
	ifstream in( "example.in" );

	in >> filas;
	in >> columnas;
	in >> ingredientes_minimos;
	in >> cacho_maximo;
	
	vector<char> linea(columnas);

	for ( int i = 0; i < filas; i++ ){
		for ( int j = 0; j < columnas; j++ ){
			in >> c;
			if (c == 'M') {
				num_mushroom++;
				pos_mushroom.push_back(make_pair(i,j));
			}
			else {
				num_tomato++;
				pos_tomato.push_back(make_pair(i,j));
			}
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
