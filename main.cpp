
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

using namespace std;
int main()
{
	cout<<"udalo sie"<<endl;
	Customer ludz1("Daniel", true, doctor);
	Pilot pilot1("Daniel", true, true);
	Plane sDaniel("dDaniel", 0.89, 151, 10);
	sDaniel.addPilot(pilot1);
	//sDaniel.addPassenger(ludz1);
	pilot1.addExperience();
	int n = pilot1.getExperience();
	printf("%s\n",pilot1.story().c_str());
	cout<<"wyswietl "<<n<<endl;
	cout<<"jesy ok"<<endl;
}
