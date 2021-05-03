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
            

            // possible race char values: 
            // W for White, A for Asian, B for Black, H for Latinx, O for Other, N for Native American
            int raceW(0), raceA(0), raceB(0), raceH(0), raceO(0), raceN(0), communityCount(0);
            if(psData[i]->getRace() == 'W') // white
            {
                raceW = raceW + 1;
            }
            else if(psData[i]->getRace() == 'A') // asian
            {
                raceA = raceA + 1;
            }
            else if(psData[i]->getRace() == 'B') // black
            {
                raceB = raceB + 1;
            }
            else if(psData[i]->getRace() == 'H') // latinx
            {
                raceH = raceH + 1;
            }
            else if(psData[i]->getRace() == 'O') // other
            {
                raceO = raceO + 1;
            }
            else if(psData[i]->getRace() == 'N') // native american
            {
                raceN = raceN + 1;
            }

            racialData.addWhiteCount(raceW);
            racialData.addWhiteNHCount(raceW);
            racialData.addAsianCount(raceA);
            racialData.addBlackCount(raceB);
            racialData.addLatinxCount(raceH);
            racialData.addOtherCount(raceO);
            racialData.addFirstNationCount(raceN);
        }
        // otherwise, skip over and go next
    }
}

/* print state data - as aggregate of all incidents in this state */
//fill in for lab4
std::ostream& operator<<(std::ostream &out, const psState& PD) {
    out << "**Police shooting incidents:State Info: " << PD.state;
    out << "\nNumber of incidents: " << PD.numCases;
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.casesOver65;
    out << "\n(19 to 64): " << PD.numCases - PD.casesOver65 - PD.casesUnder18;
    out << "\n(under 18): " << PD.casesUnder18;
    out << "\nIncidents involving fleeing: " << PD.fleeingCount;
    out << "\nIncidents involving mental illness: " << PD.numMentalIllness;
    out << "\nMale incidents: " << PD.numMales <<  " female incidents: " << PD.numFemales;
    out << "\nRacial demographics of state incidents: " << PD.racialData;
    return out;
}