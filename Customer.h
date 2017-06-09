#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>
#include  <iostream>
#include "Person.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>

using namespace std;

class Customer : public Person
{
private:
   	string name;
	bool mood;
	usefullness level;
	int experience; // który lot i czy bedzie panikował
	bool known; //czy znana
	float levelOfKnown;
public:

    Customer (string name, bool known, usefullness level);
    void changeUsefullness(usefullness newone);
    void addExperience();
    float generateFame(bool known);
    string story();
    void changeMood(bool newmood);


    //akcesory

    string getName();
    usefullness getLevel();
    bool isKnown();
    int getExperience();
    float getLevelOfKnown();
	void metoda();
	bool getMood();

};


