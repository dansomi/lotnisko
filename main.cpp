
#include "Customer.h"
#include "Pilot.h"
#include "structs.h"
#include "Plane.h"
#include <string>
#include <stdio.h>
#include  <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <cstdlib>

using namespace std;
int main()
{
	printf("Welcome to airport!\n\n");
	srand(time(NULL));
	bool exists = true;
	Plane *listOfPlane = new Plane[2000];  //iczba samolotow
	for( int i =0; i< 500; i++)
	{
		string name= "plane" + to_string(i) + to_string(rand()%10000);
		float x =  rand() / (RAND_MAX + 1.0);
		if(x < 0.8)
			x +=0.2;
		int y = rand() % 100 + 100;//paliwo w baku 100-200
		int place = rand() %50 + 10; //liczba osob na pokladzie 10-60
		Plane tmp(name, x, y, place);
		listOfPlane[i] = tmp;

		string pilotName = "pilot" + to_string(rand()%28765);
		bool mood = rand() %2;
		bool ex =  rand()%2;
		Pilot tmpPilot(pilotName, mood, ex);
		listOfPlane[i].addPilot(tmpPilot);
	}
	Customer * passengers = new Customer[100000];
	for(int i = 0; i< 100000; i++)
	{
		string passangerName= "passanger" + to_string(i);
		bool fame = rand() %2;
		int l = rand() %7;
		Customer c(passangerName,fame, (usefullness)l);
		passengers[i] =c;
	}

	int year =1;
	while(exists){

			printf("--------------------------------------------------\n" );
			printf("YEAR: %d\n", year);
			printf("--------------------------------------------------\n" );
			int checker = 0;
			for(int i =0; i<500; i++) //liczba samolotu
			{
				if(!listOfPlane[i].getDestroy())
				{
					int fuel = rand() % 100 + 100;
					int neededFuel = fuel-50;
					int number = rand() % listOfPlane[i].getMaxPassenger() +1; //losujemy ile pasazerow w tym samolocie bedzie lecialo

					int x = 0;
					for (int j =0; j < 100000 && x<number; j++)
					{
						if(passengers[j].getAlive()){
							x++;
							listOfPlane[i].addPassenger(passengers[j]);
						}
					}
					listOfPlane[i].fly(neededFuel, fuel); //ile paliwa na droge i ile mamy w baku
					bool accident = listOfPlane[i].isTrouble();
					if(accident)
					{
						listOfPlane[i].crash();
					}
					else
					{
						listOfPlane[i].land();
					}


				}
				else
				{
					checker++;
				}

			}
			year++;
			if(checker == 500) //liczba samolotow
				exists = false; //wszystkie samoloty zostaly zniszczone wiec przestaje dzialac lotnisko
	}

	if(!exists) printf("Airport is end\n"); printf("--------------------------------------------------\n" );

}
