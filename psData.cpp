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
    if(inFlee == "Not fleeing")
    {
        flee = false;
    }
}

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, const psData &PD) {
    out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " ;
    out << "\nAge: " ;
    out << "\nGender: " ;
    out << "\nRace:" ;
    out << "\nMental Illness:" ;
    out << "\nFleeing:" ;
    return out;
}
