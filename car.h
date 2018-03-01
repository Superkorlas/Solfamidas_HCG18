#ifndef _CAR_
#define _CAR_
#include "point.h"
#include "ride.h"
#include "stdlib.h"
#include <vector>

int row_limit;
int column_limit;
int step;

class Car {

	Ride ride;
	point pos;
	bool busy;
	int  numRide;
	bool pick_up;

	bool _rand;

	public:
		vector<int> travels;
		Car();
		void Move();
		void Update();
		int WhenFree();
		void SetRide(Ride newRide);
		bool GetBusy();
		point GetPosition();
		static void SetRowLimit(int new_row_limit);
		static void SetColumnLimit(int new_column_limit);
		int GetNumRides();


};

Car::Car() {
	busy = false;
	_rand = false;
	numRide = 0;
}

void Car::Move() {
	if (busy) {
		if (!pick_up) {
			if (pos.x < ride.GetFinish().x) {
				pos.x++;
			} else if (pos.y < ride.GetFinish().y) {
				pos.y++;
			} else {
				busy = false;
				travels.push_back(ride.code);
			}
		} else {
			if (pos.x < ride.GetStart().x) {
				pos.x++;
			} else if (pos.y < ride.GetStart().y) {
				pos.y++;
			} else {
				pick_up = false;
			}
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
	busy = true;
	if (pos.x == ride.GetStart().x && pos.y == ride.GetStart().y) {
		pick_up = true;
	} else {
		pick_up = false;
	}
}

point Car::GetPosition() {
	return pos;
}

int Car::GetNumRides(){
	return numRide;
}

#endif
