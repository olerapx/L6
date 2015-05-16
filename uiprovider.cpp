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
    State::readFromKeyboard(queue);
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
  std::cout <<"Input index\n";
   char s=std::cin.get();
   clearStream();

   std::cout <<"Input index:\n";
   int index;
   std::cin>>index;

   State state=queue.getElement(index);


    std::cout<<state.capitalName<<"\n" <<state.countryName<<"\nLanguage: " <<state.language<<
                "\nMonetary unit: "<<state.monetaryUnit<<"\nPolitical system: " <<state.politicalSystem<<
                "\nPopulation: "<<state.population<<"\nArea: "<<state.territoryArea<<"\n\n\n";
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


