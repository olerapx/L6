#include "state.h"

State::State()
{
    capitalName="";
    countryName="";
    language="";
    population=0;
    territoryArea=0.0;
    monetaryUnit="";
    politicalSystem="";
}


int compareCountryName(const State& s1, const State& s2)
{
    return strcmp(s1.countryName.c_str(), s2.countryName.c_str());
}

int compareCapitalName(const State& s1, const State& s2)
{
     return strcmp(s1.capitalName.c_str(), s2.capitalName.c_str());
}

int compareLanguage(const State& s1, const State& s2)
{
     return strcmp(s1.language.c_str(), s2.language.c_str());
}

int comparePopulation (const State& s1, const State& s2)
{
    if (s1.population<s2.population) return -1;
    if(s1.population==s2.population) return 0;
    return 1;
}

int compareTerrritoryArea(const State& s1, const State& s2)
{
    if (s1.territoryArea<s2.territoryArea) return -1;
    if(s1.territoryArea==s2.territoryArea) return 0;
    return 1;
}

int compareMonetaryUnit(const State& s1, const State& s2)
{
    return strcmp(s1.monetaryUnit.c_str(), s2.monetaryUnit.c_str());
}

int comparePoliticalSystem(const State& s1, const State& s2)
{
   return strcmp(s1.politicalSystem.c_str(), s2.politicalSystem.c_str());
}

