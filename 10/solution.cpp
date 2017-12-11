#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string line;
  pair<int,int> pos{0,0};
  while (getline(cin,line,',')) {
    cout << "Line: " << line << endl;
    for (char & c: line) {
      if (c =='n') pos.second += 1;
      else if (c =='s') pos.second -= 1;
      else if (c =='e') pos.first += 1;
      else if (c =='w') pos.first -= 1;
    }
  }
  cout << "Pos: " << pos.first << " " << pos.second << endl;
  cout << "Diagonal: " << sqrt(pos.first^2 + pos.second^2) << endl;
  return 0;
}
