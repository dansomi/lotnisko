#include "Customer.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

#pragma mark [ Metody obiektu ]

Customer::Customer(string name, bool known, usefullness level)
{
    this -> name = name;
    this -> known = known;
    this -> level = level;

    experience = 0;
    levelOfKnown = Customer::generateFame(known);
}

float Customer::generateFame(bool known)
{
    srand(time(NULL));
    flaot level;
    if(known)
    {
        level = rand() / (RAND_MAX + 1.0);
    }
    else
    {
        return 0.0;
        }

    return level;

}

void Customer::addExperience()
{
    experience++;
}

void Customer::changeUsefullnes(usefullness newUse)
{
    level = newUse;
}


string Customer::story()
{
    ostringstream ss;
    ss << name;
    if(known)
    {
        ss <<"is famous.\n";
        ss<<"His/Her level of famous is";
        ss<< levelOfKnown;
    }
    else
        ss<<"isn't famous at all.\n";
    ss <<"He/She is";
    if(level = 0)
        ss <<"no one special.\n";
    if(level = 1)
        ss <<"police officer .\n";
    if(level = 2)
        ss <<"soldier.\n";
    if(level = 3)
        ss <<"firefighter.\n";
    if(level = 4)
        ss <<"negotiator\n";
    if(level = 5)
        ss <<"doctor.\n";
    if(level = 6)
        ss <<"politician.\n";
    if(experience < 5)
        ss << " He/She isn't experienced in flying by airplane. Can panic. ";
    else
        ss <<"He/She is experienced in flying by airplane.";



    return ss.str();
}

#pragma mark [ Akcesory ]

string Customer::getName()
{
    return name;
}

usefullness Customer::getLevel()
{
    return level;
}

bool Customer::isKnown()
{
    return known;
}

int Customer::getExperience()
{
    return experience;
}

float Customer::getLevelOfKnown()
{
    return levelOfKnown;
}
