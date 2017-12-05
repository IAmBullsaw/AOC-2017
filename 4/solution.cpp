#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;


int puzzle1() {
  string line{""};
  int result{0};
  while(getline(cin,line)) {
    istringstream iss{line};
    vector<string> tokens{istream_iterator<string>{iss},
        istream_iterator<string>{}};
    bool approved{true};
    set<string> set;
    for (string token: tokens){
      if(auto [it, approved] = set.insert(token); !approved)
        break;
    }
    if (approved) {
      ++result;
    }
  }
  return result;
}

int main() {
  cout << "Result is: " << puzzle1() << endl;
  return 0;
}
