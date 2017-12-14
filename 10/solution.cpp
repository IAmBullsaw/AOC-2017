#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class Circle {
public:
  Circle(int list_size)
    :list(list_size), skip_size{0}, current_position{0}
  {
    for (int i{0}; i < list_size; i++) list.at(i) = i;
  }

  void old_tie(int const& length) {
    cout << "Tieing " << length << " ..." << endl;
    reverse(list.begin(), list.begin() + length);

    rotate(list.begin(), list.begin() + current_position, list.end());

    current_position = (length + skip_size) % list.size();
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
    cout << "Result: " << list.at(0)*list.at(1) << endl;
  }

  void tie(int const& length) {
    if ( (current_position + length) < list.size()) { // don't go too far, it's only the first date
      reverse(list.begin() + current_position, list.begin() + current_position + length);
      current_position = (current_position + length + skip_size) % list.size(); // update ze position
    }
    else {
      vector<int> hej;
      int new_length = (current_position + length) % list.size(); // Get overflow
      copy(list.begin() + current_position, list.end(), back_inserter(hej)); // copy from current to end
      copy(list.begin(), list.begin() + new_length, back_inserter(hej)); // copy from beginning to length

      reverse(hej.begin(),hej.end());
      swap_ranges(list.begin() + current_position, list.end(), hej.begin()); // swap from beginning of hej
      swap_ranges(list.begin(), list.begin() + new_length, hej.begin() + ( length - new_length ) ); // swap from beginning of hej+previous amount

      current_position = (current_position + length + skip_size) % list.size(); // update ze position
    }
    ++skip_size;
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

void solution1() {
  Circle circle{256};
  vector<int> input({183,0,31,146,254,240,223,150,2,206,161,1,255,232,199,88});
  for (int const& i: input) {
    circle.tie(i);
  }
  circle.print();
}

int main() {
  solution1();
  return 0;
}
