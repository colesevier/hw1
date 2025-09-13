#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("because");
  dat.push_front("I'm");
  dat.push_back("Coding");
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  size_t index = 13;
  //dat.getValAtLoc(index);
  // prints: 8 7 9
  dat.pop_back();
  cout << dat.get(0) << " " << dat.get(1) << endl;
  dat.pop_front();
  cout << " " << dat.get(1) << endl;
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
