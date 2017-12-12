#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

string replace(string const& source, string const& pattern, string const& replace) {
  regex reg{pattern};
  return regex_replace(source, reg, replace);
}

int main() {
  string line;
  vector<vector<int>> queue;
  while (getline(cin,line)) {
    line = replace(line," <-> "," ");
    line = replace(line,",","");
    istringstream iss{line};
    int id;
    vector<int> group;
    set<int> s;
    while (iss >> id) {
      s.insert(id);
    }
    copy(s.begin(),s.end(),back_inserter(group));
    queue.push_back(group);
  }

  vector<vector<int>> groups;
  groups.push_back(queue.back());
  queue.pop_back();

  unsigned since_last_merge{0};
  while (!queue.empty()) {
    auto queue_size = queue.size();
    vector<int> v1 = queue.back();
    queue.pop_back();

    bool did_merge{false};
    for (unsigned long i{0}; i < groups.size();i++) {
      vector<int> intersection;
      vector<int> v2 = groups.at(i);
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end());

      set_intersection(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),
                       back_inserter(intersection));

      if (!intersection.empty()) {
        vector<int> merged;
        set_union(v1.begin(), v1.end(),
                  v2.begin(), v2.end(),
                  back_inserter(merged));

        groups.erase(groups.begin()+i);

        queue.push_back(merged);
        did_merge = true;
        break;
      }
    }
    if (!did_merge) {
      groups.push_back(v1);
    }

    if (since_last_merge == queue_size) {break;}

  }
  vector<int> zero_group{};
  for (auto v: groups) {
    for (auto n: v) {
      if ( n == 0) {
        zero_group = v;
      }
    }
  }
  cout << "Size: " << zero_group.size() << endl;
  cout << "Groups: " << groups.size() << endl;
  return 0;
}
