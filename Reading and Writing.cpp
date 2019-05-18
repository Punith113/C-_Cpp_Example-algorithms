#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  ifstream inFile;
  inFile.open("numbers.txt");

  //check for error
  if (inFile.fail()){
      cerr << "Error opening File" << endl;
      exit(1);
  }

  int x, y;

  infile >> x >> y;

  cout << "Num 1: " << x << endl;
  cout << "Num 2:" << y << endl;

  return 0;
}
