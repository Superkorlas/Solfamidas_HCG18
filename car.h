#ifndef _CAR_
#define _CAR_
#include "point.h"
#include "ride.h"
#include "stdlib.h"

int row_limit;
int column_limit;

class Car {

	Ride ride;
	point pos;
	bool busy;

	bool _rand;

	public:

		Car();
		void Move();
		void Update();
		int WhenFree();
		void SetRide(Ride newRide);
		bool GetBusy();
		point GetPosition();
		static void SetRowLimit(int new_row_limit);
		static void SetColumnLimit(int new_column_limit);

};

Car::Car() {
	busy = false;
	_rand = false;
}

void Car::Move() {
	if (busy) {
		if (pos.x < ride.GetFinish().x) {
			pos.x++;
		} else if (pos.y < ride.GetFinish().y) {
			pos.y++;
		} else {
			busy = false;
		}
	} else if (_rand){
		if (pos.x < column_limit) {
			pos.x++;
		}
		_rand = !_rand;
	} else {
		if (pos.y < row_limit) {
			pos.y++;
		}
		_rand = !_rand;
	}
}

void Car::Update() {
	Move();
}

bool Car::GetBusy() {
	return busy;
}

int Car::WhenFree() {
	return (abs(pos.x - ride.GetFinish().x) + abs(pos.y - ride.GetFinish().y));
}

void Car::SetRide(Ride newRide) {
	ride = newRide;
}

point Car::GetPosition() {
	return pos;
}

#endif
