#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool check(int const& a, string const& comp, int const& b) {
  bool res{false};
  if ( comp == "<" ) {
    res = a < b;
  } else if ( comp == ">" ) {
    res = a > b;
  } else if ( comp == "==" ) {
    res = a == b;
  } else if ( comp == "!=" ) {
    res = a != b;
  } else if ( comp == "<=" ) {
    res = a <= b;
  } else if ( comp == ">=" ) {
    res = a >= b;
  } else { cout << "Forgot something... " << endl;}
  return res;
}

struct Instruction {
  string name;
  string action;
  int amount;
  string other;
  string comp;
  int val;
};

int main() {
  map<string,int> registers{};
  vector<Instruction> instructions{};
  string line;
  while(getline(cin,line)) {
    istringstream iss{line};
    string who, action, other, comp, tmp;
    int amount,val;
    iss >> who >> action >> amount >> tmp >> other >> comp >> val;

    registers.emplace(who,0);

    Instruction i;
    i.name = who;
    i.action = action;
    i.amount = amount;
    i.other = other;
    i.comp = comp;
    i.val = val;

    instructions.push_back(i);
  }

  int largest{0}; // for sol2
  for (Instruction & i: instructions) {
    if (check(registers.at(i.other),i.comp,i.val)) {
      if (i.action == "inc") {
        registers.at(i.name) += i.amount;
      } else  {
        registers.at(i.name) -= i.amount;
      }
      if (largest < registers.at(i.name)) largest = registers.at(i.name);
    }
  }

  cout << "Largest value: " <<
    max_element(registers.begin(),registers.end(), [](auto const& a, auto const& b){
      return a.second < b.second;
    })->second
       << endl;

  cout << "Largest ever:" << largest << endl;

  return 0;
}
