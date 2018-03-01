

#include "point.h"


class Car {

	Ride ride;
	point pos;
	bool busy;

	public:

		Car() {}
};

Car::Car() {
	busy = false;
	pos.x = 0;
	pos.y = 0;

}