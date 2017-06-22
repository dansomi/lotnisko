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
Pilot::Pilot()
{
}
void Pilot::addExperience(){
	experience++;
}
string Pilot::story()
{
    ostringstream ss;
		ss <<"Pilot ";
    ss << name;
    ss <<" is in ";
    if(mood)
    {
        ss <<"good mood. ";
    }
    else
       ss <<"bad mood. ";
    ss <<"Pilot is ";
    if(exhausted)
    {
        ss <<"exhausted. ";
    }
    else{
        ss <<"not exhausted. ";
    }

    if(experience < 5)
        ss << "He isn't experienced in flying by airplane. Can panic.\n";
    else
        ss <<"He is experienced in flying by airplane.\n";

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
void Pilot::changeMood(bool newone)
{
	mood = newone;
}
bool Pilot::getExhausted()
{
	return mood;
}
int Pilot::getExperience()
{
    return experience;
}
