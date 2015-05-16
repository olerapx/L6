#include <iostream>
#include "uiprovider.h"
#include "fstream"

void printInt (std::ostream& os,const int& i)
{
    os<<i<<"\n";
}

int main(int argc, char *argv[])
{

    Queue<State>queue;
    UIProvider::handleUserInput(queue);

    return 0;
}
