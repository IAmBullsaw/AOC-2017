#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string line;
  while (getline(cin,line)) {
    istringstream iss{line};
    int parent;
    string trash;
    iss >> parent >> trash;
    string child_s;
    int child;
    while (iss >> child_s) {
      if (child_s.back() == ',') child_s = child_s.substr(0, child_s.size()-2); // Remove trailing ,
      child = stoi(child_s);
      cout << child << endl;
    }
  }
  return 0;
}
