
#ifndef _RIDE_
#define _RIDE_

#include "point.h"


class Ride {

	bool assigned;
	point start, finish;
	int startTime, finishTime;

	public:

		int code;

		Ride(){
			assigned = false;
		}

		Ride( point start, point finish, int startTime, int finishTime, int c ){

			this->start = start;
			this->finish = finish;
			this->startTime = startTime;
			this->finishTime = finishTime;
			assigned = false;
			code = c;
		}

		Ride(const Ride & r ){
			start = r.start;
			finish = r.finish;
			startTime = r.startTime;
			finishTime = r.finishTime;
			assigned = r.assigned;
			code = r.code;
		}

		point GetStart(){
			return start;
		}

		point GetFinish(){
			return finish;
		}

		bool GetAssigned(){
			return assigned;
		}

		void Assign(){
			assigned = true;
		}
};

#endif
