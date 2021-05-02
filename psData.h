#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "raceDemogData.h"


using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inState, string inName, int inAge, string inGender, string inRace, string inCounty, string inSignsMentalIllness, string inFlee);

    //add getters
    string getName() const { return name; }
    int getAge() const {return age; }
    char getGender() const { return gender; }
    char getRace() const { return race; }
    string getCounty() const { return county; }
    string getState() const { return state; }
    bool getSignsMentalIllness() const { return signsMentalIllness; }
    bool getFlee() const { return flee; }

   friend std::ostream& operator<<(std::ostream &out, const psData &PD);

private:
    string name;
    int age;
    char gender;
    char race;
    string county;
    string state;
    bool signsMentalIllness = false;
    bool flee = true;
};

#endif
