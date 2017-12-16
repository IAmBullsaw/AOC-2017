#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

class Circle {
public:
  Circle(int list_size, string hash)
    :list(list_size), skip_size{0}, current_position{0}
  {
    for (int i{0}; i < list_size; i++) list.at(i) = i;

    for (char const& c: hash)
      input.push_back(c);
    // append_salt
    vector<int> salt({17, 31, 73, 47, 23});
    for (auto i: salt)
      input.push_back( i );
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

  void print_list() {
    cout << "input: ";
    for (auto v: input) {
      cout << v << " ";
    }
    cout << endl;
  }

  void sparse_tie() {
    int i{64};
    while (i--) {
      for (int const& length: input) {
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
    }
  }

  void hashify() {
    sparse_tie();
    for (int i{0}; i < 256; i+=16) {
      int res =
        list.at(i) ^ list.at(i+1) ^ list.at(i+2) ^ list.at(i+3) ^
        list.at(i+4) ^ list.at(i+5) ^ list.at(i+6) ^ list.at(i+7) ^
        list.at(i+8) ^ list.at(i+9) ^ list.at(i+10) ^ list.at(i+11) ^
        list.at(i+12) ^ list.at(i+13) ^ list.at(i+14) ^ list.at(i+15);
      if (res < 16) {
        cout << 0 << hex << res << dec;
      } else
        cout << hex << res << dec;
    }
    cout << endl;
  }

private:
  vector<int> list;
  int skip_size;
  int current_position;
  vector<int> input;
};

void test() {
  Circle circle{256,""};
  circle.hashify();
  Circle circl{256,"AoC 2017"};
  circl.hashify();
  Circle circ{256,"1,2,3"};
  circ.hashify();
  Circle cir{256,"1,2,4"};
  cir.hashify();
}

void solution2() {
  string input;
  cin >> input;
  Circle circle{256,"183,0,31,146,254,240,223,150,2,206,161,1,255,232,199,88"};
  circle.hashify();
}

int main() {
  test();
  solution2();
  return 0;
}
