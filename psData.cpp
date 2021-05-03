#include <sstream>
#include <string>
#include "psData.h"
using namespace std;

psData::psData(string inState, string inName, int inAge, string inGender, string inRace, string inCounty, string inSignsMentalIllness, string inFlee)
{
    name = inName;
    age = inAge;
    gender = inGender[0];
    race = inRace[0];
    county = inCounty;
    state = inState;
    if(inSignsMentalIllness == "TRUE")
    {
        signsMentalIllness = true;
    }
    else if(inSignsMentalIllness == "FALSE")
    {
        signsMentalIllness = false;
    }

    if((inFlee == "Not fleeing") || inFlee == "")
    {
        flee = false;
    }
}

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, const psData &PD) {
    out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " << PD.name;
    out << "\nAge: " << PD.age;
    out << "\nGender: " << PD.gender;
    out << "\nRace:" << PD.race;
    out << "\nMental Illness:" << PD.signsMentalIllness;
    out << "\nFleeing:" << PD.flee;
    return out;
}
