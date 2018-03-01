
#include <vector>
#include <stdlib.h>
#include <utility>
#include "point.h"

using namespace std;


class Rides {

	vector<pair<point, point>> rides; //Viajes inicio - destino
	vector<point>  cars;// Coches posicion

	vector< pair<bool, int> > car_aviability; //Coche disponibilidad -  tiempo hasta desponible
	vector< pair<int, int> > travel ;   // Viaje tiempo inicio tiempo fin

	vector< bool >  travel_aviability;

	public:

		Rides( int amount );


		void Car_Selection(/* arguments */);

		int distance(point a, point b);



};


int Rides::distance( point a, point b ){

	return abs( a.x - b.x ) + abs( a.y - b.y );
}
