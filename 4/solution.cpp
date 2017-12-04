#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int main() {
  string line{""};
  int result{0};
  while(getline(cin,line)) {
    istringstream iss{line};
    vector<string> tokens{istream_iterator<string>{iss},
                                                    istream_iterator<string>{}};
    bool approved{true};
    set<string> set;
    for (string token: tokens){
      auto p = set.insert(token);
      approved = p.second;
      if (!approved) {
        break;
      }
    }
    if (approved) {
      ++result;
    }
  }

  cout << "Result is: " << result << endl;
  return 0;
}
