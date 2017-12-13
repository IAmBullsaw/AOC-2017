
#include <iostream>
#include <regex>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

int get_garbage(string & data) {
  regex negations("(!.)");
  regex garbage("<(.*?)>");
  string res{""};
  regex_replace(back_inserter(res),data.begin(), data.end(), negations, "");

  regex_iterator<string::iterator> rit(res.begin(),res.end(),garbage);
  regex_iterator<string::iterator> rend;
  data.clear();

  while (rit != rend) {
    data += rit->str().substr(1,rit->str().size() - 2);
    ++rit;
  }

  return data.size();
}

int main() {
  string data;
  while (getline(cin,data)) {
    cout << "It's garbage day: " << get_garbage(data) << endl;
  }
}
