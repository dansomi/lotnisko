#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>

using namespace std;

class AirPlane
{
private:
    string planeNumber;
	float condition, fuel;
	int maxPassenger;
	bool kidnaped; //czy jest porwany
	bool pilotDay; //true = good day, false = bad day
  int numPassengers; //ile aktualnie pasazerow w samolocie

  Customer*Passengers;  //lista pasazerow
public:

    bool isBigPlane(); //duzy czy maly samolot - liczba pasazerow
    bool terrorists(); //terrorysci na pokladzie

	void crash();
	string story();


};
