#ifndef _CAR_
#define _CAR_
#include "point.h"


class Car {

	Ride ride;
	point pos;
	bool busy;

	public:
		Car();
		Move();
		Update();
		WhenFree();
		SetRide(Ride newRide);
};

Car::Car() {
	busy = false;
}

void Car::Move() {
	if (busy) {

	} else {

	}
}

void Car::Update() {
	Move();
}

bool Car::GetBusy() {
	return busy;
}

int Car::WhenFree() {

}

void Car::SetRide(Ride newRide) {
	ride = newRide;
}

#endif