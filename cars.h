#ifndef _CARS_
#define _CARS_
#include "point.h"
#include "car.h"
#include "rides.h"
#include "ride.h"

class Cars {
    std::vector<Car> cars;
    Rides rides;

    Cars(int numberCars){
        cars.resize(numberCars);
    }


    Point Cars::GetCarPosition(int carIndex){
        cars[carIndex].getPosition();
    }

    void Cars::Update(){
        for (int i = 0; i < cars.size(); i++){
            if(cars[i].GetBusy() == false){
                //TODO set Ride to a car
                cars[i].SetRide(rides.something);
            }
        }
    }


};

#endif