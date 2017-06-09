#include "Plane.h"
#include "Pilot.h"

#pragma mark [ Metody obiektu ]
using namespace std;
//getter do destroy
Plane::Plane(string planeNumber, float condition, float fuel, int maxPassenger)
{
	this -> planeNumber = planeNumber;
	this -> condition = condition;
	this -> fuel = fuel;
	this -> maxPassenger = maxPassenger;
	neededFuel = 0;
	kidnaped = false;
	pilot = NULL;
	flying = false;
	numPassenger = 0;
	passengers = (Customer*)malloc(sizeof(Customer) * maxPassenger);
	destroy = false;
}


//    bool isBigPlane(); //du¿y czy ma³y samolot - liczba pasazerow
bool Plane::isTerroristInside() //terrorysci na pokladzie
{
	int x = rand() % 101;
	if(x <= 5)
	{
		kidnaped = true;
		return true;
	}
	else return false;
}

bool Plane::isFuelEnd()
{
	if(fuel <= neededFuel)
		return true;
	return false;
}

void Plane::fly()
{
	if(pilot == NULL)
	{
		printf("Plane without pilot cant fly.\n");
		return;
	}
	if(flying)
	{
		printf("The plane is flying so there is some mistake\n");
		return;
	}
	flying = true;
	printf("Plane %s starts flying.\n", planeNumber);
}
void Plane::addPilot(Pilot p)
{
	if(flying)
	{
		printf("The plane is flying so there is some mistake\n");
		return;
	}
	if(pilot != NULL)
	{
		printf("The plane has a pilot.\n");
		return;
	}
	pilot = &p;
}
void Plane::addPassenger(Customer c)
{
	if(flying)
	{
		printf("The plane is flying so there is some mistake\n");
		return;
	}
	if(maxPassenger == numPassenger)
	{
		printf("There is no place in this plane.\n");
		return;
	}
	passengers[numPassenger] = c;
	numPassenger+=1;
}

void Plane::land()
{
	if(flying == false)
	{
		printf("The plane hasnt started his fly yet.\n");
		return;
	}
	printf("The plane %s is landing.\n", planeNumber);
	flying = false;
}
//



bool Plane::tryRescuePlane()
{
	printf("Dupa\n" );
	//LOSUJEMY liczbe z jakiegos zakresu jesli iles tam wieksza to samolot uratowany wiec zmienna na true a w przeciwnym false
	//+ wypisujemy komunikat ze jest proba uratowania samolotu a przed zwroceniem wartosci jeszcze piszemy czy sie nam udalo czy nie ;p

}

bool Plane::isTrouble()
{
	bool trouble = false;
	float weatherCondition = -200 + rand() / (RAND_MAX + 1.0) * 600;
	if(Plane::isTerroristInside())
	{
		trouble = true;
		printf("The plane was kidnaped. Let's see if it survived.\n");
		neededFuel+=rand()%31; // neededFuel = neededFuel + rand...
		if(Plane::isFuelEnd())
		{
			printf("The plane %s hasnt fuel.\n",planeNumber );
			Plane::crash();
			return true;
		}

	}
	else if(weatherCondition < -180)
	{
		trouble = true;
		printf("The weather is bad. The plane can crash.\n");
		neededFuel+=rand()%71; // neededFuel = neededFuel + rand...
		if(Plane::isFuelEnd())
		{
			printf("The plane %s hasnt fuel.\n",planeNumber );
			//Plane::crash();
			return true;
		}
	}
	else if(condition <0.07){
		trouble = true;
		printf("The plane %s is in bad condition.\n",planeNumber );
		//Plane::crash(); - jednak chyba wszystkie crash beda w main dla kazdego true -> crash()
		return true;
	}
	if(trouble){
		int counter = countStrenght();
		if(counter > 6)
			trouble = Plane::tryRescuePlane(); //probujemy uratowac samolot zobaczymy czy sie nam uda

	}
	return trouble;
	//przed returnem mozna jeszcze zrobic losowanie jakiejs liczby i jeslii wieksza/mniejsza to brzoza i samochod sie crashuje
	//TRUE - CRASH W MAINIE
}


void Plane::crash()
{
	printf("The plane %s ends his life with %d passangers on board.\n", planeNumber, numPassenger);
	destroy = true;

}
string Plane::story() //historia do zaimplementowania
{
}

int Plane::countStrenght()
{
	int counter = 0;
	int help=0;
	for(int i= 0; i<numPassenger; i++)
	{
		counter+=passengers[i].getExperience();
		if((int)passengers[i].getLevel() != 0)
			help++; //za kazda osobe ktora jest uzyteczna dodajemy +1;
	}
	counter/=numPassenger; // liczymy srednie doswiadczenie na jednego pasazera
	help/=numPassenger;
	counter+=help;

	counter+= pilot->getExperience();
	return counter;
//pod uwage bierzemy experience każdego pasazera, experience pilota, usefullness pasazerow
}


    //akcesory
	#pragma mark [ Akcesory ]
float Plane::getCondition()
{
	return condition;
}

float Plane::getFuel()
{
	return fuel;
}

float Plane::getNeededFuel()
{
	return neededFuel;
}

int Plane::getMaxPassenger()
{
	return maxPassenger;
}

bool Plane::isKidnaped()
{
	return kidnaped;
}
Customer * Plane::getPassengerList()
{
	for(int i =0; i< numPassenger; i++)
		printf("Passenger number %d is %s", i, passengers[i].getName());
	return passengers;
}

int Plane::getNumberOfPassengers()
{
	return numPassenger;
}
bool Plane::isFlying()
{
	return flying;
}
