#include <iostream>
#include "queue.h"
#include "fstream"

void printInt (std::ostream& os,const int& i)
{
    os<<i<<"\n";
}

int main(int argc, char *argv[])
{
  Queue<int> queue(3);
  queue.qstore(10);
  queue.qstore(20);
  queue.qstore(30);
  queue.qstore(40);
  queue.qstore(50);

  std::ofstream ofs;
  ofs.open("1");

  queue.printQueue(std::cout, printInt);
  ofs.close();

    return 0;
}
