#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct Connection {
  string name;
  int weight;
  Connection* parent;
};


void solution1() {
  map<string,pair<int,string>> program{};
  string line;
  while (getline(cin,line)) {
    istringstream iss{line};
    string name;
    string weight_s;
    iss >> name >> weight_s;
    int weight = stoi(weight_s.substr(1, weight_s.size() - 2 ));
    pair<int,string> p = make_pair(weight, "");
    pair<string,pair<int,string>> e = make_pair(name,p);
    auto ret = program.insert(e);
    if (!ret.second) {
      cout << "Already existed" << endl;
    }
    string arrow;
    iss >> arrow;
    if (!arrow.empty()) {
      string child;
      while (iss >> child) {
        program.at(child).second = name;
      }
    }
    cout << name << weight << arrow << endl;
  }
}

int main() {
  solution1();
  return 0;
}
