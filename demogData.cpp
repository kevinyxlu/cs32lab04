#include "demogData.h"
#include <sstream>
#include <cmath>
#include <iostream>
#include <iomanip>

/* print county demographic data */
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    int popOver65Count = DD.getpopOver65Count();
    int popUnder18Count = DD.getpopUnder18Count();
    int popUnder5Count = DD.getpopUnder5Count();
    int BAupCount = DD.getBAupCount();
    int HSupCount = DD.getHSupCount();

    out << "County Demographics Info: " << DD.name << ", " << DD.state << " total population: " << DD.totalPopulation2014;
    out << "\nPopulation info: \n(\% over 65): " << DD.popOver65 << " Count: " << popOver65Count;
    out << "\n(\% under 18): " << DD.popUnder18 << " Count: " << popUnder18Count;
    out << "\n(\% under 5): " << DD.popUnder5 << " Count: " << popUnder5Count;
    out << "\nEducation info: ";
    out << "\n(% Bachelor degree or more): " << DD.popBachelorEduPlus << " Count: " << BAupCount;
    out << "\n(% high school or more): " << DD.popHighSchoolEduPlus << " Count: " << HSupCount;
    out << "\ncommunity racial demographics: ";

    out << "Racial Demographics Info: ";
    out << std::setprecision(2) << std::fixed;
    out << "\n\% American Indian and Alaska Native";
    out << " percent: " << DD.popFirstNation;
    out << " count: " << DD.getFirstNationCount();
    out << "\n\% Asian American";
    out << " percent: " << DD.popAsian;
    out << " count: " <<  DD.getAsianCount();
    out << "\n\% Black/African American";
    out << " percent: " << DD.popBlack;
    out << " count: " << DD.getBlackCount();
    out << "\n\% Hispanic or Latinx";
    out << " percent: " << DD.popLatinx;
    out << " count: " << DD.getLatinxCount();
    out << "\n\% Native Hawaiian and Other Pacific Islander";
    out << " percent: " << DD.popHIPacificIsle;
    out << " count: " << DD.getHIPacificIsleCount();
    out << "\n\% Two or More Races";
    out << " percent: " << DD.popMultiRace;
    out << " count: " << DD.getMultiRaceCount();
    out << "\n\% White (inclusive)";
    out << " percent: " << DD.popWhite;
    out << " count: " << DD.getWhiteCount();
    out << "\n\% White (nonHispanic)";
    out << " percent: " << DD.popWhiteNH;
    out << " count: " << DD.getWhiteNHCount();
    out << "\ntotal Racial Demographic Count: " << DD.totalPopulation2014;

    return out;
}

int demogData::getpopOver65Count() const
{
    int count;
    count = round((popOver65 / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getpopUnder18Count() const
{
    int count;
    count = round((popUnder18 / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getpopUnder5Count() const
{
    int count;
    count = round((popUnder5 / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getBAupCount() const
{
    int count;
    count = round((popBachelorEduPlus / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getHSupCount() const
{
    int count;
    count = round((popHighSchoolEduPlus / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getPovertyCount() const
{
    int count;
    count = round((popInPoverty / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getFirstNationCount() const
{
    int count;
    count = round((popFirstNation / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getAsianCount() const
{
    int count;
    count = round((popAsian / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getBlackCount() const
{
    int count;
    count = round((popBlack / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getLatinxCount() const
{
    int count;
    count = round((popLatinx / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getHIPacificIsleCount() const
{
    int count;
    count = round((popHIPacificIsle / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getMultiRaceCount() const
{
    int count;
    count = round((popMultiRace / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getWhiteCount() const
{
    int count;
    count = round((popWhite / 100) * totalPopulation2014); //calculate the count
    return count;
}

int demogData::getWhiteNHCount() const
{
    int count;
    count = round((popWhiteNH / 100) * totalPopulation2014); //calculate the count
    return count;
}
