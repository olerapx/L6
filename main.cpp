#include <iostream>
#include "uiprovider.h"
#include "fstream"


int main(int argc, char *argv[])
{
    Queue<State>queue;
    UIProvider::handleUserInput(queue);

    return 0;
}
