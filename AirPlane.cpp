#include "AirPlane.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

#pragma mark [ Metody obiektu ]

bool AirPlane::isBigPlane()
{

}

bool AirPlane::terrorists(int  numPassengers, Customer*Passengers)
{
  for(int i=0; i<numPassengers; i++)
  {
    int t = Passengers[i].experience;
    int y = (((rand() % 101) + t)*t)/(rand() % 39)
  }

}
