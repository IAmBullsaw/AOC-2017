#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Connection {
  string name;
  int weight;
  Connection* parent;
};


void solution1() {
  vector<string> parents{};
  vector<string> children{};
  string line;
  while (getline(cin,line)) {
    istringstream iss{line};
    string name;
    string weight_s;
    string arrow;
    iss >> name >> weight_s >> arrow;
    if (!arrow.empty()) {
      string child;
      parents.push_back(name);
      while (iss >> child) {
        if (child.back() == ',') { child = child.substr(0, child.size() - 1);}
        children.push_back(child);
      }
    }
  }
  cout << "Parents: " ;
  for (string p: parents) cout << p << " ";
  cout << endl;
  cout << "Children: " ;
  for (string c: children) cout << c << " ";
  cout << endl;
  vector<string> difference{parents.size()+children.size()};
  sort(parents.begin(), parents.end());
  sort(children.begin(), children.end());
  auto it = set_difference(parents.begin(),parents.end(),children.begin(),children.end(),difference.begin());
  difference.resize(it-difference.begin());

  cout << "Difference: ";
  for (string d: difference) cout << d << " ";
  cout << endl;

}

int main() {
  solution1();
  return 0;
}
