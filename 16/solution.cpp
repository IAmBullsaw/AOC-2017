#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

class Dancers {
public:
  Dancers(vector<char> j)
    :programs{j}
  {}

  void spin(int const& n) {
    // auto front = programs.begin();
    // auto back = programs.end() - n;
    // iter_swap(front,back);
    rotate(programs.begin(), programs.end()-n, programs.end());
  }

  void exchange(string const& cmd) {
    auto [a,b] = split(cmd,"/");
    swap(programs[stoi(a)],programs[stoi(b)]);
  }

  void partner(string const& cmd) {
    auto [a,b] = split(cmd,"/");
    auto found_a = find(programs.begin(), programs.end(), a.front());
    auto found_b = find(programs.begin(), programs.end(), b.front());
    iter_swap(found_a,found_b);
  }

  void print() {
    for (char const& c: programs) {
      cout << c;
    }
    cout << endl;
  }

private:
  vector<char> programs;

  pair<string,string> split(string const& source, string const& delimiter) {
    regex reg{"(.+)" + delimiter + "(.+)"};
    smatch match;
    regex_match(source, match, reg);
    return make_pair(match[1],match[2]);
  }
};

void test() {
  string cmd;
  Dancers dancers{{'a','b','c','d','e'}};
  while (getline(cin, cmd, ',')) {
    if (cmd.front() == 's') dancers.spin(stoi(cmd.substr(1,cmd.size())));
    else if (cmd.front() == 'x') dancers.exchange(cmd.substr(1,cmd.size()));
    else if (cmd.front() == 'p') dancers.partner(cmd.substr(1,cmd.size()));
    dancers.print();
  }
}

void solution() {
  string cmd;
  Dancers dancers{{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'}};
  while (getline(cin, cmd, ',')) {
    if (cmd.front() == 's') dancers.spin(stoi(cmd.substr(1,cmd.size())));
    else if (cmd.front() == 'x') dancers.exchange(cmd.substr(1,cmd.size()));
    else if (cmd.front() == 'p') dancers.partner(cmd.substr(1,cmd.size()));
  }
  dancers.print();
}

int main() {
  solution();
  return 0;
}
