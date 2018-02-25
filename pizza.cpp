// g++ -g -o pichalol pizza.cpp
// Subido a github 13:38
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

typedef int ingredient;

struct point {
	int x;
	int y;
};


const ingredient mushroom = 0;
const ingredient tomato = 1;

vector<vector<ingredient> > pizza;
vector<vector<point> > positions( 2, vector<point>() );
int rows, cols, minIngredients, biggestSlice;
vector<int> ingredientCount( 2, 0 );
ingredient lessCount;


// Self-explanatory HAHAHAHAHAHAHAHAH

inline ingredient charToInt( char c ){

	return c == 'T';
}


void init(){

}

inline void findSmaller(){

	lessCount = ingredientCount[mushroom] > ingredientCount[tomato];
}


/** Devuelve la distancia entre dos objetos (tomato, mushroom) */
int distance( point obj1, point obj2 ){

	int dist_horizontal = abs(obj1.x - obj2.x) + 1;
	int dist_vertical = abs(obj1.y - obj2.y) + 1;
	return dist_horizontal * dist_vertical;
}


/** Devuelve vector con las posiciones de los elementos cercanos que no sobrepasan el limite de distancia.
 * obj -> elemento del que queremos buscar los vecinos
 * pos -> posicion del elemento en el vector del ingrediente (mushroomPositions, tomatoPositions)
 */

vector<point> buscar_cercanos ( point obj, int pos ) {

	vector<point> pos_cercanos;


	//Trabajamos con Tomates
	if ( pizza[obj.x][obj.y] == tomato ) {
		for (int i = pos; i < positions[tomato].size(); i++){}
	} else {  //Trabajamos con Champiñones
		
	}
	return pos_cercanos;


}

vector<int> b_and_b(vector<point> & posiciones, int poda){
	
}

/**
 * Devuelve el vector solucion, calcula la poda, por la cual el algoritmo parará
 * cuando sobrepase ese número. También elige qué elemento está en minoría para
 * pasarselo al algorimo.
 */
vector<int> BRNO_MAGIK(){


	int poda, best_case, worst_case, dimensiones = rows * cols;

	//( dimensiones / biggestSlice ) / ( ingredientCount[lessCount] * biggestSlice )

	best_case = ( ingredientCount[lessCount] * biggestSlice) / minIngredients;			// Maximun amount of valid slices
	best_case = ( best_case > dimensiones ) ? dimensiones : best_case;	// Adjust to reality
	worst_case = ingredientCount[lessCount] * 2;
	poda = ( best_case + worst_case ) / 2;

	return b_and_b( positions[ 1 - lessCount ], poda );


	/*if (tomatoCount >= mushroomCount) {
		best_case = (mushroomCount * biggestSlice) / minIngredients;
		best_case = (best_case > dimensiones) ? dimensiones : best_case;
		worst_case = (mushroomCount * 2);
		poda = (best_case + worst_case) / 2;
		return b_and_b(tomatoPositions, poda);
	} else {
		best_case = (tomatoCount * biggestSlice) / minIngredients;
		best_case = (best_case > dimensiones) ? dimensiones : best_case;
		worst_case = (tomatoCount * 2);
		poda = (best_case + worst_case) / 2;
		return b_and_b(mushroomPositions, poda);
	}*/
}


int main(){


	char c;
	ifstream in( "example.in" );
	ingredient newIngredient;
	point newIngredientPosition;

	in >> rows;
	in >> cols;
	in >> minIngredients;
	in >> biggestSlice;
	vector<ingredient> newLine( cols );
	

	// Read the data and write the matrix

	for ( int i = 0; i < rows; i++ ){
		for ( int j = 0; j < cols; j++ ){

			in >> c;
			newIngredient = charToInt( c );
			newLine[j] = newIngredient;
			newIngredientPosition.x = i;
			newIngredientPosition.y = j;

			ingredientCount[newIngredient]++;
			positions[newIngredient].push_back( newIngredientPosition );



			/*if ( c == mushroom ) {
				mushroomCount++;
				mushroomPositions.push_back( newIngredientPosition );
			}
			else {
				tomatoCount++;
				tomatoPositions.push_back( newIngredientPosition );
			}*/
		}

		pizza.push_back( newLine );
	}

	findSmaller();


	// 

	for ( int i = 0; i < positions[lessCount]; i++ );


	for ( int i = 0; i < rows; i++ ){
		for ( int j = 0; j < cols; j++ )
			cout << pizza[i][j];
		cout << endl;
	}
}
