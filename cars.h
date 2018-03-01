#ifndef _CARS_
#define _CARS_
#include "point.h"
#include "car.h"

class Cars {
    std::vector<Car> cars;

    Cars(int numberCars){
        cars.resize(numberCars);
    }


    Point getCarPosition(int carIndex){
        cars[carIndex].getPosition();
    }


};

#endif