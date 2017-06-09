#pragma once
#include <string>
#include "structs.h"
#include <stdio.h>
#include "Person.h"

using namespace std;

class Pilot : public Person
{
private:
   	string name;
	bool mood;
	int experience;
	bool exhausted;
public:

    Pilot (string name, bool mood, bool exhausted);
    void addExperience();
    string story();
    void changeMood(bool newMood);


    //akcesory

    string getName();
    int getExperience();
    void metoda();
    bool getMood();



};
