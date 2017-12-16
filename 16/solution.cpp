#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

class Dancers {
public:
  Dancers(string j)
    :programs{j}
  {}

  void spin( int const& n) {
    auto front = programs.begin();
    auto back = programs.end() - n;
    iter_swap(front,back);
  }

  void print() {
    for (char const& c: programs) {
      cout << c << " ";
    }
    cout << endl;
  }

  void exchange( string const& cmd) {

  }
  void partner( string const& cmd) {

  }

private:
  array<char,16> programs;
};


int main() {
  string cmd;
  Dancers dancers{{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'}};
  while (getline(cin, cmd, ',')) {
    if (cmd.front() == 's') dancers.spin(stoi(cmd.substr(1,cmd.size())));
    else if (cmd.front() == 'x') dancers.exchange(cmd.substr(1,cmd.size()));
    else if (cmd.front() == 'p') dancers.partner(cmd.substr(1,cmd.size()));
    dancers.print();
  }

}
