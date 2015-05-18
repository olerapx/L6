#include "uiprovider.h"


 UserAction UIProvider::getAction(char s)
 {
    if (Commands.find(s)!= Commands.end()) return Commands[s];

     return ACTION_UNKNOWN;
 }

void UIProvider::clearStream()
 {
     std::cin.clear();
     while (std::cin.get() != '\n');
 }


void UIProvider::handleUserInput(Queue<State>&queue)
{
    char s='\0';
    handleHelp();
    do{
        s=std::cin.get();
        clearStream();
        switch(getAction(s))
        {
           case ACTION_HELP:
             handleHelp();
             break;

           case ACTION_QSTORE:
             handleStoreAction(queue);
             break;

           case ACTION_QRETRIEVE:
            handleRetrieveAction(queue);
            break;

           case ACTION_GET:
            handleGetAction(queue);
            break;

           case ACTION_PRINT:
            handlePrintAction(queue);
            break;

            case ACTION_QUIT:
            return;

           default:
            std::cout<< "Wrong command. To get the command list, input h\n";
            break;
        }
    }
    while (true);
}


void UIProvider::handleStoreAction(Queue<State> &queue)
{
    readFromKeyboard(queue);
    std::cout << "inputting finished\n";
}

void UIProvider::handleRetrieveAction(Queue<State> &queue)
{
  State state=queue.qretrieve();


     std::cout<<state.capitalName<<"\n" <<state.countryName<<"\nLanguage: " <<state.language<<
                 "\nMonetary unit: "<<state.monetaryUnit<<"\nPolitical system: " <<state.politicalSystem<<
                 "\nPopulation: "<<state.population<<"\nArea: "<<state.territoryArea<<"\n\n\n";
}

void UIProvider::handleGetAction(Queue<State>&queue)
{
    State state;
    std::cout <<"Input index:\n";
    int index;
    std::cin>>index;

    try
    {
           state=queue.getElement(index);
    }
    catch(std::out_of_range){}
    printState(std::cout, state);

 char e='y';


 while (e=='y')
 {
    std::cout<<"Do you want to edit? y/n \n";

    std::cin>>e;
    clearStream();

    if (e!='y') return;

    std::cout <<"Input:\n"
                  "1 to edit name\n"
                  "2 to edit capital name\n"
                  "3 to edit language\n"
                  "4 to edit population\n"
                  "5 to edit area\n"
                  "6 to edit monetary unit\n"
                  "7 to edit system\n";

     char s=std::cin.get();
     clearStream();

     std::cout <<"Input new field value\n";
     std::string str=" ";
     std::cin>>str;
     clearStream();

     if (str=="")
     {
         std::cout <<"No value was inputted. Abort\n";
         continue;
     }
     switch(s-'0')
     {
            case FIELD_COUNTRY_NAME:
                state.countryName=str;
                break;

           case FIELD_CAPITAL_NAME:
               state.capitalName=str;
                break;

           case FIELD_LANGUAGE:
                state.language=str;
                break;

           case FIELD_POPULATION:
           {
                std::stringstream intStream(str);
                intStream>> state.population;
                break;
           }
           case FIELD_AREA:
           {
                std::stringstream floatStream(str);
                floatStream>> state.territoryArea;
                break;
           }
           case FIELD_UNIT:
                state.monetaryUnit=str;
                break;

           case FIELD_SYSTEM:
                state.politicalSystem=str;
                break;

           default:
                std::cout <<"Wrong field\n";
                return;
        }
     std::cout <<"Successfully changed\n";
    }
}

void UIProvider::handlePrintAction(Queue<State>&queue)
{
  queue.printQueue(std::cout, printState);
}


void UIProvider::handleHelp()
{
    std::cout <<"input:\n"
                "h to get the command list\n"
                "s to store States into queue\n"
                "p to retrieve State\n"
                "g to get element\n"
                "p to print queue\n"
                "q to quit\n";
}


void UIProvider::printState (std::ostream& os,const State & state)
{
    os<<"Capital name: "<<state.capitalName<<"\nCountry name: " <<state.countryName<<"\nLanguage: " <<state.language<<
                "\nMonetary unit: "<<state.monetaryUnit<<"\nPolitical system: " <<state.politicalSystem<<
                "\nPopulation: "<<state.population<<"\nArea: "<<state.territoryArea<<"\n\n\n";
}


void UIProvider::readFromFile (std::ifstream &fs, Queue<State>& queue)
{
    std::string s;
    int i=0, currQueueIndex=queue.len()-1;
    while (!fs.eof())
    {
       std::getline(fs,s);
       if (s=="") continue;
       switch(i)
       {
           case 0:
           {
                   State state;
                   queue.qstore(state);
                   currQueueIndex++;

                   int index = s.find(':')+2;
                   queue[currQueueIndex].capitalName=s.substr(index, s.length()-index);
                   i++;
                   break;
           }
           case 1:
           {
                  int index = s.find(':')+2;
                  queue[currQueueIndex].countryName=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 2:
           {
                  int index = s.find(':')+2;
                  queue[currQueueIndex].language=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 3:
           {
                  int index = s.find(':')+2;
                  queue[currQueueIndex].monetaryUnit=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 4:
           {
                  int index = s.find(':')+2;
                  queue[currQueueIndex].politicalSystem=s.substr(index, s.length()-index);
                  i++;
                  break;
           }
           case 5:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  queue[currQueueIndex].population=atoi(curr.c_str());
                  i++;
                  break;
           }
           case 6:
           {
                  std::string curr;
                  int index = s.find(':')+2;
                  curr=s.substr(index, s.length()-index);
                  queue[currQueueIndex].territoryArea=std::atof(curr.c_str());
                  i=0;
                  break;
           }
       }
   }
}

void UIProvider::readFromKeyboard(Queue<State>&queue)
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

        queue.qstore(state);
   }

}
