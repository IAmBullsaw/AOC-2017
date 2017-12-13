#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

string replace(string const& source, string const& pattern, string const& replace) {
  regex reg{pattern};
  return regex_replace(source, reg, replace);
}

struct Scanner {
  Scanner()
    :pos{0},range{0},down{true}
  {}
  Scanner(int pos, int range)
    :pos{pos},range{range},down{true}
  {}

  int pos;
  int range;
  bool down;
};


void scanners_move(vector<Scanner> & firewall) {
  for (auto & p: firewall) {
    if (p.range != 0) {
      p.down ? ++p.pos : --p.pos;
      if (p.pos == 0 || p.pos == p.range-1) p.down = ! p.down;
    }
  }
}

bool we_move(vector<Scanner> const& firewall, int const& pos) {
  return firewall.at(pos).pos == 0; // we walked right into a scanner :(
}

void print_wall(vector<Scanner> firewall) {
  for (auto p: firewall)
    cout << p.pos << " " << p.range << endl;
  cout << endl;
}

int main() {
  vector<Scanner> firewall{100};

  // Read the puzzle
  string line;
  while (getline(cin,line)) {
    line = replace(line,":","");
    istringstream iss{line};
    int d;
    int r;
    iss >> d >> r;
    firewall.at(d).pos = 0; // scanner position
    firewall.at(d).range = r; // range
  }

  int sum{0};
  for (int i{0}; i < firewall.size(); ++i) {
    cout << "Pos: " << i << endl;
    print_wall(firewall);
    if (bool detected = we_move(firewall, i); detected) {
      sum += i * firewall.at(i).range;
      cout << "detected at " << i << " for "<<i * firewall.at(i).range << endl;
    }
    scanners_move(firewall);
    string trash;
    cin >> trash;
  }
  cout << "Sum: " << sum << endl;
}
