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

  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  cout << dat.size() << endl;

  dat.clear();

  for (int i = 0; i < 20; ++i) {
    dat.push_back(std::to_string(i%10));
  }
  dat.pop_front();
  dat.pop_front();
  dat.pop_back();

  cout << dat.front() << " " << dat.get(14) << " " << dat.back() << endl; 

}
