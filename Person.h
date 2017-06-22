
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>


using namespace std;
class Person
{
	private:
		int experience;
		bool mood;
		string name;
	public:

		virtual string getName() = 0;
		virtual bool getMood() = 0;
    virtual int getExperience() = 0;
		virtual void addExperience() = 0;
		virtual string story()=0;
		virtual void changeMood(bool newMood)=0;
};
