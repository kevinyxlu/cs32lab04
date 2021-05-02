#include <iomanip>
#include "psState.h"

/* print state data - as aggregate of all incidents in this state */
//fill in for lab4
std::ostream& operator<<(std::ostream &out, const psState& PD) {
    out << "State Info: " << PD.state;
    out << "\nNumber of incidents: ";
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