#include <iostream>
#include <string>
using namespace std;

int main() {
  string cmd;
  char first;
  int second;
  while (cin >> cmd >> first >> second) {
    if (cmd == "set") {}
    else if (cmd == "add") {}
    else if (cmd == "mul") {}
    else if (cmd == "mod") {}
    else if (cmd == "snd") {}
    else if (cmd == "rcv") {}
    else if (cmd == "jgz") {}
    else { cout << "Missed something: " << cmd << endl; }
  }

  return 0;
}
