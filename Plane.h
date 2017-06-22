#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>
#include "Customer.h"
#include "Pilot.h"
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Plane
{
private:
    string planeNumber;
	float condition;
  int fuel;
	int neededFuel;
	int maxPassenger;
	bool kidnaped;
	Customer * passengers;
	int numPassenger;
	bool flying;
	Pilot pilot;
  bool isPilot;
	bool destroy;

public:
	Plane(string planeNumber, float condition, int fuel, int maxPassenger);
  Plane();

  bool getDestroy();
  bool isTerroristInside(); //terrorysci na pokladzie
	bool isFuelEnd();
	void fly(int amountOfFuel, int f);
	void addPilot(Pilot p);
	void addPassenger(Customer c);
	void land();
	bool isTrouble();
	bool tryRescuePlane();
	void crash();
	string story();
	float countStrenght();

    //akcesory
  string getName();
	float getCondition();
	int getFuel();
	int getNeededFuel();
	int getMaxPassenger();
	bool isKidnaped();
	Customer * getPassengerList();
	int getNumberOfPassengers();
	bool isFlying();



};
