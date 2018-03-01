
#ifndef _CARS_
#define _CARS_

#include <vector>
#include <stdlib.h>
#include <utility>
#include "point.h"
#include "ride.h"

using namespace std;


class Rides {

	vector<Ride> rides; //Viajes inicio - destino

	public:

		Rides( int amount );

		Ride Travel_Search(point p);

		int Distance(point a, point b);

		void update();



};


Ride Rides::Travel_Search(point p){
	vector<Ride>::iterator best_Ride;
	int best_distance=0;

	vector<Ride>::iterator it;

	for(it = rides.begin(); it != rides.end(); it++){
		if(!(*it).GetAssigned()){
		  if( best_distance < Distance(it->GetStart(),p)){
				best_distance = Distance(it->GetStart(),p);
				best_Ride      = it;
			}
		}
	}

	(*best_Ride).Assign();

	return (*best_Ride);
}

int Rides::Distance( point a, point b ){

	return abs( a.x - b.x ) + abs( a.y - b.y );
}


#endif
