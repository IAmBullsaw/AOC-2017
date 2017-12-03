#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

enum Direction{R,U,L,D};
Direction& operator++(Direction& dir) {
  if (dir == R) dir = U;
  else if (dir == U) dir = L;
  else if (dir == L) dir = D;
  else dir = R; // (dir == D)
  return dir;
}

Direction operator++(Direction& dir,int) {
  Direction temp{dir};
  ++dir;
  return temp;
}

class Grid {
public:
  Grid():top_left{0,1},bottom_left{0,0},bottom_right{1,0},top_right{1,1} {}

  bool at_edge(pair<int,int> const& point) const {
    return (top_left.first == point.first || bottom_left.first == point.first || bottom_right.first == point.first || top_right.first == point.first) ||
      (top_left.second == point.second || bottom_left.second == point.second || bottom_right.second == point.second || top_right.second == point.second);
  }

  bool at_corner(pair<int,int> const& point) {
    return top_left == point ||
      bottom_left == point ||
      bottom_right == point ||
      top_right == point;
  }

  void print() const {
    cout << "Grid:\n"
         << "(" << top_left.first << ":" << top_left.second << ")" << " " << "(" << top_right.first << ":" << top_right.second << ")\n"
         << "(" << bottom_left.first << ":" << bottom_left.second << ")" << " " << "(" << bottom_right.first << ":" << bottom_right.second << ")"
         << endl;
  }

  void widen(pair<int,int> const& point, Direction const& d) {
    if (point == top_left && d == L ) {
      --top_left.first;
      --bottom_left.first;
      cout << "widens!" << endl;
    } else if (point == bottom_left && d == D ) {
      --bottom_left.second;
      --bottom_right.second;
      cout << "widens!" << endl;
    } else if (point == bottom_right && d == R ) {
      ++bottom_right.first;
      ++top_right.first;
      cout << "widens!" << endl;
    } else if (point == top_right && d == U ){
      ++top_right.second;
      ++top_left.second;
      cout << "widens!" << endl;
    }
    print();
  }

private:
  pair<int,int> top_left;
  pair<int,int> bottom_left;
  pair<int,int> bottom_right;
  pair<int,int> top_right;
};

void print(pair<int,int> const& point, Direction const& d) {
  cout << "(" << point.first << ":" << point.second << ")" << " " << d << endl;
}

int main() {
  Grid grid;
  pair<int,int> pos{0,1};
  unsigned current{4};
  unsigned goal{0};
  cin >> goal;

  // The first cases!
  if (goal == 1) {
    cout << "Result is " << 0 << endl;
    return 0;
  } else if (goal == 2 || goal == 4) {
    cout << "Result is " << 1 << endl;
    return 0;
  } else if (goal == 3) {
    cout << "Result is " << 2 << endl;
    return 0;
  }

  Direction d{L};
  while (current != goal && ++current) {
    print(pos,d);
    if (grid.at_corner(pos)) {
      grid.widen(pos,d);
      if (d == R) {
        ++pos.first;
      } else if (d == U) {
        ++pos.second;
      } else if (d == L) {
        --pos.first;
      } else { // (d == D)
        --pos.second;
      }
      d++;
    }
    if (d == R) {
      ++pos.first;
    } else if (d == U) {
      ++pos.second;
    } else if (d == L) {
      --pos.first;
    } else { // (d == D)
      --pos.second;
    }
  }
  cout << "Final position" << endl;
  print(pos,d);
  cout << "Result is " << abs(pos.first) + abs(pos.second) << endl;
  return 0;
}
