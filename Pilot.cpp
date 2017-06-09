#include <string>
#include "Pilot.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#pragma mark [ Metody obiektu ]
Pilot::Pilot(string name, bool mood, bool exhausted)
{
	this -> name = name;
	this -> mood = mood;
	this -> exhausted = exhausted;
	experience = 0;
}
void Pilot::addExperience(){
	experience++;
}
string Pilot::story()
{
    ostringstream ss;
    ss << name;
    ss <<"Pilot is in";
    if(mood)
    {
        ss <<"good mood.\n";
    }
    else
       ss <<"bad mood.\n";
    ss <<"Pilot is";
    if(exhausted)
    {
        ss <<"exhausted.\n";
    }
    else{
        ss <<"not exhausted.\n";
    }

    if(experience < 5)
        ss << " He isn't experienced in flying by airplane. Can panic. ";
    else
        ss <<"He is experienced in flying by airplane.";

    return ss.str();
}
bool Pilot::getMood()
{
	return mood;
}
string Pilot::getName()
{
    return name;
}
void Pilot::metoda()
{
	printf("pilot");
}
void Pilot::changeMood(bool newone)
{
	mood = newone;
}
int Pilot::getExperience()
{
    return experience;
}



