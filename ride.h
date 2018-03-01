
#ifndef _RIDE_
#define _RIDE_

#include "point.h"


class Ride {

	bool assigned;
	point start, finish;
	int startTime, finishTime;

	public:

		Ride(){
			assigned = false;
		}

		Ride( point start, point finish, int startTime, int finishTime ){

			this->start = start;
			this->finish = finish;
			this->startTime = startTime;
			this->finishTime = finishTime;
			assigned = false;
		}

		Ride( Ride & r ){
			start = r.start;
			finish = r.finish;
			startTime = r.startTime;
			finishTime = r.finishTime;
			assigned = r.assigned;
		}

		point GetStart(){
			return start;
		}

		point GetFinish(){
			return finish;
		}

		void Assign(){
			assigned = true;
		}
};

#endif