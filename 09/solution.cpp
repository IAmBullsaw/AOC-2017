#include <iostream>
#include <regex>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

void clean(string & data) {
  regex negations("(!.)");
  regex garbage("(<.*?>)");
  string res{""};
  regex_replace(back_inserter(res),data.begin(), data.end(), negations, "");
  data.clear();
  regex_replace(back_inserter(data), res.begin(), res.end(), garbage, "");
}

pair<string::iterator, int> get_points(string::iterator it, string & data, int depth) {
  int res{0};
  while(it != data.end()) {
    char c{*it};
    advance(it,1);
    if ( c == '{') {
      auto [first, second] = get_points(it, data, depth + 1);
      it = first;
      res += second;
    } else if ( c == '}') {
      res += depth;
      break;
    }
  }
  return make_pair(it,res);
}

int main() {
  string data;
  while (getline(cin,data)) {
    clean(data);
    auto [it, result] = get_points(data.begin(), data,0);
    cout << "result: " << result << endl;
  }
}
