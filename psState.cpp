#include <iomanip>
#include <memory>
#include "psState.h"
#include "parse.h"

psState::psState(string inS, vector<shared_ptr<psData>> psData)
{
    state = inS;
    for(int i = 0; i < psData.size(); i++)
    {
        if(psData[i]->getState() == state)
        {
            if(psData[i]->getSignsMentalIllness() == true)
            {
                numMentalIllness = numMentalIllness + 1;
            }
            if(psData[i]->getFlee() == true)
            {
                fleeingCount = fleeingCount + 1;
            }

            if(psData[i]->getAge() >= 65)
            {
                casesOver65 = casesOver65 + 1;
            }
            else if(psData[i]->getAge() <= 18)
            {
                casesUnder18 = casesUnder18 + 1;
            }

            if(psData[i]->getGender() == 'M')
            {
                numMales = numMales + 1;
            }
            else if(psData[i]->getGender() == 'F')
            {
                numFemales = numFemales + 1;
            }

            numCases = numCases + 1;
        }
        // otherwise, skip over and go next
    }
}

/* print state data - as aggregate of all incidents in this state */
//fill in for lab4
std::ostream& operator<<(std::ostream &out, const psState& PD) {
    out << "State Info: " << PD.state;
    out << "\nNumber of incidents: " << PD.numCases;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): ";
    out << "\n(19 to 64): ";
    out << "\n(under 18): ";
    out << "\nIncidents involving fleeing: ";
    out << "\nIncidents involving mental illness: ";
    out << "\nMale incidents: " <<  " female incidents: ";
    out << "\nRacial demographics of state incidents: ";
    return out;
}