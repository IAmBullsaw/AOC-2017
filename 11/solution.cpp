#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Coordinate {
  Coordinate(int x,int y, int z)
    :x{x},y{y},z{z}
  {}
  int x;
  int y;
  int z;

  int distance() const {
    return max(abs(x), max(abs(y),abs(z)));
  }
};

int main() {
  string dir;
  Coordinate pos{0,0,0};
  int maxdist{0};
  while (getline(cin,dir,',')) {
    cout << "Line: " << dir << endl;
    if (dir == "n") { ++pos.x; --pos.z; }
    else if (dir == "s") { --pos.x; ++pos.z; }
    else if (dir == "nw") { ++pos.y; --pos.z; }
    else if (dir == "ne") { ++pos.x; --pos.y; }
    else if (dir == "sw") { --pos.x; ++pos.y; }
    else if (dir == "se") { --pos.y; ++pos.z; }
    else { cout << "Missed something: " << dir << endl;}

    if (pos.distance() > maxdist) maxdist = pos.distance();

  }
  cout << "Pos: " << pos.x << " " << pos.y << " " << pos.z << endl;
  cout << "Distance: " << pos.distance() << endl;
  cout << "Has anyone really been far even as decided to use even go want to do look more like: " << maxdist << endl;
  return 0;
}
