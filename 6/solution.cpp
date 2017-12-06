#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

void print(vector<int>* banks) {
  auto w = to_string(*max_element(banks->begin(), banks->end())).length();
  for (auto n:*banks) {
    cout << setw(w) << n << " ";
  }
  cout << endl;
}

void distribute(vector<int>* banks) {
  auto d = distance(banks->begin(), max_element(banks->begin(), banks->end()));
  auto it = banks->begin() + d;
  int memory{*it};
  *it = 0;
  while (memory--) {
    advance(it,1);
    if (it == banks->end()) {
      it = banks->begin();
    }
    *it += 1;
  }
  // print(banks);
}

void solution1() {
  int steps{0};
  vector<int> banks{};
  set<vector<int>> memory{};
  copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(banks));
  while (++steps) {
    pair<set<vector<int>>::iterator,bool> ret;
    ret = memory.insert(banks);
    if (! ret.second) {
     break;
    }
    distribute(&banks);
    // cout << setw(6) << steps << " | ";
    // print(&banks);
    // if (steps == 1000) {break;}
  }
  cout << "Found duplicate in " << steps-1 << " steps." << endl;
}

int main() {
  solution1();
  return 0;
}
