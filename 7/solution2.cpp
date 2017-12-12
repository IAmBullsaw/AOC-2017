#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Connection {
  Connection(){ };
  string name;
  int weight;
  int disk_weight;
  bool balanced;
  vector<string> children_names;
};

int calc_weight(Connection parent, map<string,Connection> const& nodes) {
  int current_weight{parent.weight};
  for (string child: parent.children_names) {
    current_weight += calc_weight(nodes.at(child), nodes);
  }
  cout << "Returning weight: " << current_weight << " " << parent.name << endl;
  return current_weight;
}

void solution() {
  vector<Connection> parents;
  map<string,Connection> nodes;

  string line;
  while (getline(cin,line)) {
    istringstream iss{line};
    string name;
    string weight_s;
    string arrow;
    iss >> name >> weight_s >> arrow;

    Connection current;
    current.name = name;
    current.weight = stoi( weight_s.substr(1,weight_s.size()-2) );

    nodes.emplace(name,current);

    if (!arrow.empty()) {
      string child;
      while (iss >> child) {
        if (child.back() == ',') { child = child.substr(0, child.size() - 1);}
        current.children_names.push_back(child);
      }
      parents.push_back(current);
    }
  }

  for (Connection p: parents) {
    vector<pair<int,string>> weights;
    for (string name: p.children_names) {
      int weight = calc_weight(nodes.at(name), nodes);
      weights.push_back(make_pair(weight,name));
    }

    int disk_w{0};
    for (auto pair: weights) {
      disk_w += pair.first;
    }
    p.balanced = adjacent_find( weights.begin(), weights.end(), [](auto & a, auto & b){
        return a.first != b.first;
      }) == weights.end();
    p.disk_weight = disk_w;
    if (!p.balanced) {
      cout << "Parent " + p.name + ": " << p.disk_weight << " imbalanced!" << endl;

      for (auto w: weights) {
        // FUNKA DÅ FÖR FAN JAG PALLAR INTE
        cout << disk_w + p.weight << " "<< w.first << " " << w.second << endl;
      }

    }
  }


}

int main() {
  solution();
  return 0;
}
