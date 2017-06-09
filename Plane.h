#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>
#include "Customer.h"
#include "Pilot.h"
#include <string>
using namespace std;

class Plane
{
private:
    string planeNumber;
	float condition, fuel;
	float neededFuel;
	int maxPassenger;
	bool kidnaped;
	Customer * passengers;
	int numPassenger;
	bool flying;
	Pilot *pilot;
	bool destroy;

public:
	Plane(string planeNumber, float condition, float fuel, int maxPassenger);

    bool isBigPlane(); //du¿y czy ma³y samolot - liczba pasazerow
    bool isTerroristInside(); //terrorysci na pokladzie
	bool isFuelEnd();
	void fly();
	void addPilot(Pilot p);
	void addPassenger(Customer c);
	void land();
	bool isTrouble();
	bool tryRescuePlane();

	void crash();
	string story();
	int countStrenght();
    //akcesory
	float getCondition();
	float getFuel();
	float getNeededFuel();
	int getMaxPassenger();
	bool isKidnaped();
	Customer * getPassengerList();
	int getNumberOfPassengers();
	bool isFlying();



};
