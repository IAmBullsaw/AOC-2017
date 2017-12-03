#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int get_difference(string const& row) {
  stringstream iss{row};
  vector<string> tokens{istream_iterator<string>{iss},
      istream_iterator<string>{}};
  auto result = minmax_element(tokens.begin(),tokens.end(), [](string const& a, string const& b){
      return stoi(a) < stoi(b);
    });
  return abs(stoi(*result.first) - stoi(*result.second) );
}

int get_even_division(string const& row) {
  stringstream iss{row};
  vector<string> tokens{istream_iterator<string>{iss},
      istream_iterator<string>{}};

  for (unsigned i{0};i < tokens.size(); ++i) {
    int a{stoi(tokens.at(i))};
    for (unsigned j{i+1}; j < tokens.size(); ++j) {
      int b{stoi(tokens.at(j))};
      auto result = div(a,b);
      if (result.rem == 0) {
        return result.quot;
      }
      result = div(b,a);
      if (result.rem == 0) {
        return result.quot;
      }
    }
  }

  return 0;
}

int main() {
  string row{""};
  unsigned sum{0};
  while(getline(cin,row)) {
    sum += get_even_division(row);
  }
  cout << "Checksum is " << sum << endl;
  return 0;
}
