#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
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

int puzzle2() {
  string line{""};
  int result{0};
  while(getline(cin,line)) {
    istringstream iss{line};
    vector<string> tokens{istream_iterator<string>{iss},
        istream_iterator<string>{}};
    bool approved{true};
    set<string> set;
    cout << endl;
    for (string token: tokens){
      sort(token.begin(),token.end());
      cout << token << endl;
      if(auto [it, inserted] = set.insert(token); !inserted) {
        approved = false;
        break;
      }
    }
    if (approved) {
      cout << approved << endl;
      ++result;
    }
  }
  return result;
}

int main() {
  cout << "Result is: " << puzzle2() << endl;
  return 0;
}
