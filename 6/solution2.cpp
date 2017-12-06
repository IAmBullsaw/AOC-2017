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

class Ordered_set {
public:
  Ordered_set() {}
  
  pair<set<vector<int>>::iterator,bool> insert(vector<int> v) {
      auto res = unique.insert(v);
      
      if (res.second) {
        order.push_back(v);  
      }
      return res;
  }
  
  int previous_match_index(vector<int> v) {
      auto pos = distance(order.begin(), find(order.begin(), order.end(), v));
      //for (auto vv:order)
        //print(&vv);
      //cout << "pos: " << pos << endl;
      return pos;
  }
  
private:
    vector<vector<int>> order;
    set<vector<int>> unique;
};



int distribute(vector<int>* banks) {
  // print(banks);
  auto d = distance(banks->begin(), max_element(banks->begin(), banks->end()));
  auto it = banks->begin() + d;
  int memory{*it};
  int culprit{memory};
  *it = 0;
  while (memory--) {
    advance(it,1);
    if (it == banks->end()) {
      it = banks->begin();
    }
    *it += 1;
  }
  // print(banks);
  
  return culprit;
}

void solution2() {
  int steps{0};
  vector<int> banks{};
  //set<vector<int>> memory{};
  Ordered_set memory{};
  copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(banks));
  int culprit{0};
  int distance{0};
  while (++steps) {
    pair<set<vector<int>>::iterator,bool> ret;
    ret = memory.insert(banks);
    // Debugging
    // cout << setw(6) << steps-1 << " | ";
    // print(&banks);
    // if (steps == 1000) {break;}
    
    if (! ret.second) {
        distance = steps - 1 - memory.previous_match_index(banks);
     break;
    }
    culprit = distribute(&banks);
  }
  cout << "Found duplicate in " << steps-1 << " steps." << endl;
  cout << "The culprit is: " << culprit << endl;
  cout << "Distance is : " << distance << endl;
}

int main() {
  solution2();
  return 0;
}
