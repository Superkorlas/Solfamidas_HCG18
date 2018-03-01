
#ifndef _RIDES_
#define _RIDES_

#include <vector>
#include <stdlib.h>
#include <utility>
#include "point.h"
#include "ride.h"

using namespace std;


class Rides {

	vector<Ride> rides; //Viajes inicio - destino

	public:

		Rides();
		Rides( int amount );

		pair<Ride,bool> Travel_Search(point p);
		void push_back(Ride& r){
			return rides.push_back(r);
		}

		int Distance(point a, point b);

};

Rides::Rides(){}

Rides::Rides( int amount ){
	vector<Ride> rides(amount, Ride());
}


pair<Ride,bool> Rides::Travel_Search(point p){
	vector<Ride>::iterator best_Ride= rides.begin();
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
	rides.erase( best_Ride );

	return make_pair( (*best_Ride), rides.size() > 0 );
}

int Rides::Distance( point a, point b ){

	return abs( a.x - b.x ) + abs( a.y - b.y );
}


#endif
