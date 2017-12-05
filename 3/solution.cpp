#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>
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
ostream& operator<<(ostream & os, Direction & dir) {
  if (dir == R) os << "R";
  else if (dir == U) os << "U";
  else if (dir == L) os << "L";
  else os << "D"; // (dir == D)
  return  os;
}

/*

  First box:

  4 3  (0:1)(1:1)
  1 2  (0:0)(1:0)

  Second box:
  5 4 3   (-1:1)(0:1)(1:1)
  6 1 2   (-1:0)(0:0)(1:0)

  Third box:
  5 4 3  (-1: 1)(0: 1)(1: 1)
  6 1 2  (-1: 0)(0: 0)(1: 0)
  7 8 9  (-1:-1)(0:-1)(1:-1)

  Fourth box:
  5 4 3 12 (-1: 1)(0: 1)(1: 1)(2: 1)
  6 1 2 11 (-1: 0)(0: 0)(1: 0)(2: 0)
  7 8 9 10 (-1:-1)(0:-1)(1:-1)(2:-1)

  and so forth
 */


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

  bool widen(pair<int,int> const& point, Direction const& d) {
    bool widens{false};
    if (point == top_left && d == L ) {
      --top_left.first;
      --bottom_left.first;
      widens = true;
    } else if (point == bottom_left && d == D ) {
      --bottom_left.second;
      --bottom_right.second;
      widens = true;
    } else if (point == bottom_right && d == R ) {
      ++bottom_right.first;
      ++top_right.first;
      widens = true;
    } else if (point == top_right && d == U ){
      ++top_right.second;
      ++top_left.second;
      widens = true;
    }
    return widens;
  }

private:
  pair<int,int> top_left;
  pair<int,int> bottom_left;
  pair<int,int> bottom_right;
  pair<int,int> top_right;
};

void print(pair<int,int> const& point, Direction & d) {
  cout << "(" << point.first << ":" << point.second << ")" << " " << d << endl;
}

void solution1(unsigned const& goal) {
  Grid grid;
  pair<int,int> pos{0,1};
  unsigned current{4};

  // The first cases!
  if (goal == 1) {
    cout << "Result is " << 0 << endl;
    return;
  } else if (goal == 2 || goal == 4) {
    cout << "Result is " << 1 << endl;
    return;
  } else if (goal == 3) {
    cout << "Result is " << 2 << endl;
    return;
  }

  Direction d{L};
  while (current != goal && ++current) {
    bool turn{false};
    if (grid.at_corner(pos)) {
      turn = grid.widen(pos,d);
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
    if (turn) d++;
  }
  cout << "Final position" << endl;
  print(pos,d);
  cout << "Result is " << abs(pos.first) + abs(pos.second) << endl;
}

class Score_grid {
public:
  Score_grid(unsigned long x,unsigned long y):grid{x,vector<int>(y)},translatorx{x/2},translatory{y/2} {}

  int tranx(int const& x) const {
    return translatorx + x;
  }

  int trany(int const& y) const {
    return translatory + y;
  }

  void set(int const& x, int const& y, unsigned const& score) {
    grid.at(tranx(x)).at(trany(y)) = score;
  }

  unsigned get() {
    unsigned sum{};

    /*
      (-1, 1)(0, 1)(1, 1)
      (-1, 0)      (1, 0)
      (-1,-1)(0,-1)(1,-1)
     */

    sum += get(-1,1);
    sum += get(0,1);
    sum += get(1,1);

    sum += get(-1,0);
    sum += get(1,0);

    sum += get(-1,-1);
    sum += get(0,-1);
    sum += get(1,-1);

    return sum;
  }

  unsigned get(int const& x, int const& y) const {
    return grid.at(tranx(x)).at(trany(y));
  }

  void move(Direction const& d) {
    if (d == Direction::R) {
      for (vector<int> & v: grid) {
        rotate(v.begin(), v.begin()+1,v.end());
        v.back() = 0;
      }
    } else if (d == Direction::L) {
      for (vector<int> & v: grid) {
        rotate(v.begin(), v.end()-1,v.end());
        v.front() = 0;
      }
    } else if (d == Direction::D) {
      rotate(grid.begin(), grid.begin()+1, grid.end());
      for_each(grid.back().begin(), grid.back().end(), [](int & n){ n = 0;});
    } else if (d == Direction::U) {
      rotate(grid.begin(), grid.end()-1, grid.end());
      for_each(grid.front().begin(), grid.front().end(), [](int & n){ n = 0;});
    }
  }

  void print() {
    unsigned w = to_string(get()).length();
    for (auto v: grid) {
      for (auto n: v) {
        cout << setw(w) << n << " ";
      }
      cout << endl;
    }
  }

private:
  vector<vector<int>> grid;
  long unsigned translatorx;
  long unsigned translatory;
};

void solution2(unsigned const& goal) {
  Grid grid;
  pair<int,int> pos{0,1}; // start at 4
  Score_grid scores{100,100};

  scores.set(0,0,4);
  scores.set(1,0,1);
  scores.set(1,1,1);
  scores.set(0,1,2);

  // The first cases!
  if (goal == 1) {
    cout << "Result is " << 1 << endl;
    return;
  } else if (goal == 2 ) {
    cout << "Result is " << 1 << endl;
    return;
  } else if (goal == 3) {
    cout << "Result is " << 2 << endl;
    return;
  } else if (goal == 4) {
    cout << "Result is " << goal << endl;
    return;
  }

  Direction d{L};
  while (goal > scores.get()-1) {
    bool turn{false};
    if (grid.at_corner(pos)) {
      turn = grid.widen(pos,d);
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

    scores.move(d);
    scores.set(0,0,scores.get());
    if (turn) d++;
  }
  // scores.print();
  cout << "Result is " << scores.get() << endl;
}

int main(int argc,char *argv[]) {
  unsigned goal{0};
  if (argc == 2) {
    goal = stoi(argv[1]);
  } else {
    cout << "Please enter the goal: ";
    cin >> goal;
  }
  solution2(goal);
  return 0;
}
