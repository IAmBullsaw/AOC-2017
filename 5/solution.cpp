#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  long number{0};
  vector<long> instructions;

  copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(instructions));

  int i{0};
  int steps{0};
  while (i++; steps++) {
    try {
      i += instructions.at(i)++ - 1;
    } catch (...) {
      cout << "We crasched in " << steps << endl;
    }
    cout << i << endl;
  }
  return 0;
}
