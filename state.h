#ifndef STATE_H
#define STATE_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "list.h"


class State
{
public:

    std::string countryName, capitalName, language;
    int population;
    float territoryArea;
    std::string monetaryUnit, politicalSystem; 

    //for sorting and getting an element by value of some field
   static int compareCountryName(const State& s1, const State& s2);
   static int compareCapitalName(const State& s1, const State& s2);
   static int compareLanguage(const State& s1, const State& s2);
   static int comparePopulation (const State& s1, const State& s2);
   static int compareTerrritoryArea(const State& s1, const State& s2);
   static int compareMonetaryUnit(const State& s1, const State& s2);
   static int comparePoliticalSystem(const State& s1, const State& s2);

   static void writeToFile (std::ofstream &ofs, List<State>& list);
   static void readFromFile (std::ifstream &ifs, List<State>& list);
   static void readFromKeyboard(List<State>&list);

    State();
};







#endif // STATE_H

