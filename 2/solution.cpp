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
int main() {
  string row{""};
  unsigned sum{0};
  while(getline(cin,row)) {
    sum += get_difference(row);
  }
  cout << "Checksum is " << sum << endl;
  return 0;
}
