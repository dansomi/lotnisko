
#include "Customer.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>

#pragma mark [ Metody obiektu ]
using namespace std;
Customer::Customer(string name, bool f, usefullness l)
{
    this -> name = name;
    this -> known = f;
    this -> level = l;
    alive = true;
    experience = 0;
    mood = true;
    levelOfKnown = Customer::generateFame(known);
}

Customer::Customer()
{
}

float Customer::generateFame(bool known)
{
    srand(time(NULL));
    float level;
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

void Customer::changeUsefullness(usefullness newUse)
{
    level = newUse;
}
void Customer::changeMood(bool newone)
{
	mood = newone;
}

string Customer::story()
{
    ostringstream ss;
    ss << name;
    if(known)
    {
        ss <<" is famous. ";
        ss<<" His/Her level of famous is ";
        ss<< levelOfKnown;
    }
    else
        ss<<" isn't famous at all. ";
    ss <<" He/She is ";
    if(level == 0)
        ss <<"no one special. ";
    if(level == 1)
        ss <<"police officer . ";
    if(level == 2)
        ss <<"soldier. ";
    if(level == 3)
        ss <<"firefighter. ";
    if(level == 4)
        ss <<"negotiator. ";
    if(level == 5)
        ss <<"doctor. ";
    if(level == 6)
        ss <<"politician. ";
      if(mood)
      {
          ss<<" He/She is in good mood ";
      }
      else
      {
        ss<<" He/She isn't in good mood. ";
      }
    if(experience < 5)
        ss << " He/She isn't experienced in flying by airplane. Can panic. \n";
    else
        ss <<"He/She is experienced in flying by airplane. \n";



    return ss.str();
}


#pragma mark [ Akcesory ]
bool Customer::getMood()
{
	return mood;
}
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
void Customer::setDead()
{
  alive = false;
}
bool Customer::getAlive()
{
  return alive;
}
int Customer::getExperience()
{
    return experience;
}

float Customer::getLevelOfKnown()
{
    return levelOfKnown;
}
