#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void solution1() {
  vector<long> instructions;
  copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(instructions));

  int i{0};
  int jumps{0};
  bool done{false};
  while (!done) {
    try {
      i += instructions.at(i)++;
    } catch (...) {
      cout << "We crasched in " << jumps << " jumps ... Great code!" << endl;
      done=true;
    }
    ++jumps;
  }
}

void solution2() {
  vector<long> instructions;
  copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(instructions));

  int i{0};
  int jumps{0};
  bool done{false};
  while (!done) {
    try {
      i += instructions.at(i) > 2 ? instructions.at(i)-- : instructions.at(i)++;
    } catch (...) {
      cout << "We crasched in " << jumps << " jumps ... Great code!" << endl;
      done=true;
    }
    ++jumps;
  }
}

int main() {
  solution2();
  return 0;
}
