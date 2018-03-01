// g++ -g -o pichalol pizza.cpp
// Subido a github 13:38
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "rides.h"
#include "car.h"
#include "cars.h"

using namespace std;


const string
	Black = "\033[30m",
	Red = "\033[31m",
	Green = "\033[32m",
	Yellow = "\033[33m",
	Blue = "\033[34m",
	Magenta = "\033[35m",
	Cyan = "\033[36m",
	White = "\033[37m",
	BrightBlack = "\033[30;1m",
	BrightRed = "\033[31;m1",
	BrightGreen = "\033[2;1m",
	BrightYellow = "\033[33;1m",
	BrightBlue = "\033[34;1m",
	BrightMagenta = "\033[35;1m",
	BrightCyan = "\033[36;1m",
	BrightWhite = "\033[37;1m",
	Default = "\033[0m";



int main(){


	srand( time( NULL ) );
	ifstream in( "example.in" );
	int rows, cols, vehicles, num_rides, startTime, finishTime, bonus;
	int tmp1, tmp2;
	bool end = true;
	point start, finish;

	cin >> rows
		>> cols
		>> vehicles
		>> num_rides
		>> bonus
		>> steps;


	Rides rides(num_rides);

	// Read the data

	for ( int i = 0; i < num_rides; i++ ){
		cin >> tmp1 >> tmp2;
		start = point( tmp1, tmp2 );
		cin >> tmp1 >> tmp2;
		finish = point( tmp1, tmp2 );
		cin >> startTime >> finishTime;
		Ride ride(start,finish,startTime,finishTime);
		rides.push_back(ride);
	}

	Cars cars(vehicles, rides);

	for(int t = 0; t < steps && end; t++){
		end = cars.Update();
	}
}
