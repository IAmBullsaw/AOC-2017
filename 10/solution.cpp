#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Circle {
public:
  Circle(int list_size)
    :list(list_size), skip_size{0}, current_position{0}
  {
    for (int i{0}; i < list_size; i++) list.at(i) = i;
  }

  void tie(int const& length) {
    cout << "Tieing " << length << " ..." << endl;
    reverse(list.begin(), list.begin() + length);
    int skip = (length + skip_size) % list.size();
    rotate(list.begin(), list.begin() + skip, list.end());
    current_position = (current_position + length) % (list.size() - 1);
    ++skip_size;
  }

  void print() {
    cout << "Circle: ";
    for (int i{0}; i < list.size(); ++i) {
      if ( i == current_position)
        cout <<"[" << list.at(i) << "] ";
      else
        cout << list.at(i) << " ";
    }
    cout << endl;
    cout << "Current position: "<< current_position << endl;
    cout << "Result: " << list.at(current_position)* list.at((current_position+1)%list.size())<< endl;
  }

private:
  vector<int> list;
  int skip_size;
  int current_position;
};


void test() {
  Circle circle{5};
  circle.print();
  circle.tie(3);
  circle.print();
  circle.tie(4);
  circle.print();
  circle.tie(1);
  circle.print();
  circle.tie(5);
  circle.print();
}

int main() {

  Circle circle{256};
  vector<int> input({183,0,31,146,254,240,223,150,2,206,161,1,255,232,199,88});
  for (int const& i: input) {
    circle.tie(i);
  }
  circle.print();

  return 0;
}
