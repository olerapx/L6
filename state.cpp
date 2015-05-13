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


int State::compareCountryName(const State& s1, const State& s2)
{
    return strcmp(s1.countryName.c_str(), s2.countryName.c_str());
}

int State::compareCapitalName(const State& s1, const State& s2)
{
     return strcmp(s1.capitalName.c_str(), s2.capitalName.c_str());
}

int State::compareLanguage(const State& s1, const State& s2)
{
     return strcmp(s1.language.c_str(), s2.language.c_str());
}

int State::comparePopulation (const State& s1, const State& s2)
{
    if (s1.population<s2.population) return -1;
    if(s1.population==s2.population) return 0;
    return 1;
}

int State::compareTerrritoryArea(const State& s1, const State& s2)
{
    if (s1.territoryArea<s2.territoryArea) return -1;
    if(s1.territoryArea==s2.territoryArea) return 0;
    return 1;
}

int State::compareMonetaryUnit(const State& s1, const State& s2)
{
    return strcmp(s1.monetaryUnit.c_str(), s2.monetaryUnit.c_str());
}

int State::comparePoliticalSystem(const State& s1, const State& s2)
{
   return strcmp(s1.politicalSystem.c_str(), s2.politicalSystem.c_str());
}


void State::writeToFile (std::ofstream &ofs, List<State> &list)
{
    for (unsigned int i=0;i<list.Len();i++)
       ofs<<"Capital: "<<list[i].capitalName<<"\nCountry: " <<list[i].countryName<<"\nLanguage: " <<list[i].language<<
                   "\nMonetary unit: "<<list[i].monetaryUnit<<"\nPolitical system: " <<list[i].politicalSystem<<
                   "\nPopulation: "<<list[i].population<<"\nArea: "<<list[i].territoryArea<<"\n\n\n";
}


void State::readFromFile (std::ifstream &fs, List<State>& list)
{
    std::string s;
    int i=0, currListIndex=list.Len()-1;
    while (!fs.eof())
    {
       std::getline(fs,s);
       if (s=="") continue;
       switch(i)
       {
           case 0:
           {
                   State state;
                   list.add(state);
                   currListIndex++;

                   int index = s.find(':')+2;
                   list[currListIndex].capitalName=s.substr(index, s.length()-index);
                   i++;
                   break;
           }
           case 1:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].countryName=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 2:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].language=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 3:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].monetaryUnit=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 4:
           {
                  int index = s.find(':')+2;
                  list[currListIndex].politicalSystem=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 5:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  list[currListIndex].population=atoi(curr.c_str());
                  i++;
                  break;
           }
           case 6:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  list[currListIndex].territoryArea=std::atof(curr.c_str());
                  i=0;
                  break;
           }
       }
   }
}


void State::readFromKeyboard(List<State>&list)
{
     std::string s=" ";
     std::cout <<"Input capital name, country name, language, monetary unit, political system, population and area."
                 "Each field must delim by tabulation. Input empty string to finish.\n";

    //clear console istream to read correctly
     std::cin.clear();

     while (true)
    {
        std::getline(std::cin,s);
        if (s=="") break;
        List <std::string> parsed;
        std::string curr;
        std::stringstream stream(s);

        while (std::getline(stream, curr, '\t'))
            parsed.add(curr);

          State state;

        int len=parsed.Len();
        if (len>0) state.capitalName=parsed[0];
        if (len>1)state.countryName=parsed[1];
        if (len>2)state.language=parsed[2];
        if (len>3)state.monetaryUnit=parsed[3];
        if (len>4)state.politicalSystem =parsed[4];
        if (len>5)
        {
            std::stringstream intStream(parsed[5]);
            intStream>> state.population;
        }

        if (len>6)
        {
            std::stringstream floatStream(parsed[6]);
            floatStream>> state.territoryArea;
        }

        list.add(state);
   }

}
