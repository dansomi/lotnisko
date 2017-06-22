#include "Plane.h"
#include "Pilot.h"

#pragma mark [ Metody obiektu ]
using namespace std;
//getter do destroy
Plane::Plane(string planeNumber, float condition, int fuel, int maxPassenger)
{
	this -> planeNumber = planeNumber;
	this -> condition = condition;
	this -> fuel = fuel; //max paliwa
	this -> maxPassenger = maxPassenger;
	neededFuel = 0;
	kidnaped = false;
	isPilot = false;
	flying = false;
	numPassenger = 0;
	passengers = new Customer[maxPassenger];
	destroy = false;
}

Plane::Plane()
{

}

bool Plane::isTerroristInside() //terrorysci na pokladzie
{
	int x = rand() % 101;
	if(x <= 7)
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

void Plane::fly(int amountOfFuel, int f )
{
	if(!isPilot)
	{
		std::cout << "Plane "<<planeNumber<<" without pilot cant fly.\n";
		return;
	}
	if(flying)
	{
		std::cout << "Plane "<<planeNumber<<" is flying.\n";

		return;
	}
	flying = true;
	neededFuel = amountOfFuel;
	fuel = f;
	std::cout << "Plane "<<planeNumber<<" starts flying.\n";
}
void Plane::addPilot(Pilot p)
{
	if(flying)
	{
		std::cout << "Plane "<<planeNumber<<" is flying so there is some mistake.\n";
		return;
	}
	if(isPilot)
	{
		std::cout << "Plane "<<planeNumber<<" has a pilot.\n";

		return;
	}
	pilot = p;
	isPilot = true;
	std::cout << "Pilot was added to plane "<<planeNumber<<" .\n";
}
void Plane::addPassenger(Customer c)
{
	if(flying)
	{
		std::cout << "Plane "<<planeNumber<<" is flying so there is some mistake.\n";
		return;
	}
	if(maxPassenger == numPassenger)
	{
		std::cout << "There is no place in plane "<<planeNumber<<".\n";
		return;
	}
	passengers[numPassenger] = c;
	numPassenger+=1;
}

void Plane::land()
{
	if(flying == false)
	{
		std::cout << "Plane "<<planeNumber<<"  hasnt started his fly yet.\n";
		return;
	}

	int birch = rand()%101; //brzoza
	if(birch < 8)
	{
		std::cout << "The birch during the landing plane number "<<planeNumber<<" .\n";
		Plane::crash();

	}
	else
	{
		std::cout << "Plane "<<planeNumber<<" is landing.\n";
		flying = false;
		condition -=0.0026;
		neededFuel = 0;
		fuel = 0;
		kidnaped = false;
		numPassenger = 0;
		pilot.addExperience();
		for(int i =0; i<numPassenger; i++)
			passengers[i].addExperience();

	}
}

bool Plane::tryRescuePlane()
{
	std::cout << "The crew "<<planeNumber<<" is trying to save the plane.\n";

	if(rand()%100 < 44)
	{
		std::cout << "Plane "<<planeNumber<<" is rescued\n";
		return false;
	}

	std::cout << "Plane "<<planeNumber<<" isn't rescued\n";
	return true;

}

float Plane::countStrenght()
{

	float counter = 0;
	float help=0;

	for(int i= 0; i<numPassenger; i++)
	{

		counter+=passengers[i].getExperience();
		if((int)passengers[i].getLevel() != 0)
			help++; //za kazda osobe ktora jest uzyteczna dodajemy +1;
	}
	if(numPassenger != 0)
	{
		counter/=numPassenger; // liczymy srednie doswiadczenie na jednego pasazera
		help/=numPassenger;
	}

	counter+=help;
	counter+= pilot.getExperience();
	if(pilot.getExhausted())
		counter -=1;
	return counter;

}

bool Plane::isTrouble()
{
	bool trouble = false;
	float weatherCondition = -200 + rand() / (RAND_MAX + 1.0) * 600;
	std::cout << "The plane "<<planeNumber<<" has some trouble.\n";
	if(Plane::isTerroristInside())
	{
		trouble = true;
		std::cout << "The plane "<<planeNumber<<" was kidnaped. Let's see if it survived.\n";
		neededFuel+=rand()%45; // neededFuel = neededFuel + rand...
		if(Plane::isFuelEnd())
		{
			std::cout << "Plane "<<planeNumber<<" hasnt fuel.\n";
			return true;
		}

	}
	if(weatherCondition < -100)
	{
		trouble = true;
		std::cout << "The weather is bad. The plane "<<planeNumber<<" can crash.\n";
		neededFuel+=rand()%40; // neededFuel = neededFuel + rand...
		if(Plane::isFuelEnd())
		{
			std::cout << "Plane "<<planeNumber<<" hasnt fuel.\n";
			return true;
		}
		condition-=0.006; //zla pogoda troche niszczy nam samolot
	}
	if(condition <0.03){
		trouble = true;
			std::cout << "Plane "<<planeNumber<<"is in bad condition.\n";
		return true;
	}
	if(trouble)
	{
		float counter =Plane::countStrenght();
		if(counter > 0.9)
			trouble = Plane::tryRescuePlane(); //probujemy uratowac samolot zobaczymy czy sie nam uda

	}

	return trouble;

	//TRUE - CRASH W MAINIE
}




void Plane::crash()
{
	std::cout << "Plane "<<planeNumber<<" ends his life with "<<numPassenger<<" passangers on board.";
	std::cout << " CRASH! " << '\n';
	destroy = true;
	for( int i =0; i< numPassenger; i++)
	{
		passengers[i].setDead();
	}

}


///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


string Plane::story() //historia do zaimplementowania
{
}

    //akcesory
	#pragma mark [ Akcesory ]
float Plane::getCondition()
{
	return condition;
}

int Plane::getFuel()
{
	return fuel;
}

string Plane::getName()
{
	return planeNumber;
}

int Plane::getNeededFuel()
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

bool Plane::getDestroy()
{
	return destroy;
}
