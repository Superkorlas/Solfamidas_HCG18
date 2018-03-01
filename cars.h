#ifndef _CARS_
#define _CARS_
#include "point.h"
#include "car.h"
#include "rides.h"
#include "ride.h"

class Cars {
    public:
        std::vector<Car> cars;
        Rides rides;

        Cars(int numberCars, Rides &theRides){
            cars.resize(numberCars);
            rides = theRides;
        }


        point Cars::GetCarPosition(int carIndex){
            cars[carIndex].getPosition();
        }

        void Cars::Update(){
            for (int i = 0; i < cars.size(); i++){
                if(cars[i].GetBusy() == false){
                    //Setting new destination to the car
                    cars[i].SetRide(rides.Travel_Search(cars[i].GetPosition()));
                }
                else{
                    cars[i].Update();
                }
            }
        }




};

#endif
