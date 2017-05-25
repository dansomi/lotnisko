#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>

using namespace std;

class Customer
{
private:
    string name;
//    float value; // jak cenna jest ta osoba np jesli jest znana to moze byc cenna
//to bedziemy liczyc w samolocie
	usefullness level;
	int experience; // który lot i czy bedzie panikował
	bool known; //czy znana osoba
	float levelOfKnown;
public:

    Customer (string name, bool known, usefullness level);
    void changeUsefullnes();
    void addExperience(); //jak leci ktorys raz to jest bardziej doswiadczony
    float generateFame(bool known); //generator slawy
    string story();


    //akcesory

    string getName();
    usefullness getLevel();
    bool isKnown();
    int getExperience();
    float getLevelOfKnown();


};
