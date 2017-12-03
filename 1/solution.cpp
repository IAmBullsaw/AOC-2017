#include <iostream>
#include <string>
using namespace std;

int solveCaptcha(string & captcha) {
  captcha.push_back(captcha.front());
  string::const_iterator it{captcha.begin()};
  int sum{0};
  while() {

  }

  return sum;
}


int main() {
  string captcha{"1122"};
  int sum{solveCaptcha(captcha)};
  cout << "Sum of 1122 is: " << sum << endl;
  captcha = "1111";
  sum = solveCaptcha(captcha);
  cout << "Sum of 1111 is: " << sum << endl;
  captcha = "1234";
  sum = solveCaptcha(captcha);
  cout << "Sum of 1234 is: " << sum << endl;
  captcha = "91212129";
  sum = solveCaptcha(captcha);
  cout << "Sum of 91212129 is: " << sum << endl;
  return 0;
}
