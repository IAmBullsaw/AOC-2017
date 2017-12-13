#include <iostream>
#include <string>
using namespace std;

int solveCaptcha(string & captcha) {
  captcha.push_back(captcha.front());
  string::const_iterator it{captcha.begin()};
  int sum{0};
  while(it != captcha.end()) {
    char letter{*it};
    unsigned n{0};
    do {
      if (letter == *(it+1+n)) {
        ++n;
      } else break;
    } while(n < captcha.size());
    sum += static_cast<int>(letter - '0')*n;
    advance(it,1+n);
  }

  return sum;
}

int solveCaptcha2(string const& captcha) {
  const long unsigned half{captcha.size()/2};
  int opposite{0};
  char other{};
  int sum{0};
  long unsigned i{0};
  for (char letter : captcha) {
    if (i < half) {
      opposite = half + i;
    } else { opposite = i - half; }
    other = captcha.at(opposite);
    if (letter == other) {
      sum += static_cast<int>(letter - '0');
    }
    ++i;
  }
  return sum;
}

void test() {
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
}

void test2() {
  string captcha{"1212"};
  int sum{solveCaptcha2(captcha)};
  cout << "Sum of " << captcha << " is: " << sum << endl;
  captcha = "1221";
  sum = solveCaptcha2(captcha);
  cout << "Sum of " << captcha << " is: " << sum << endl;
  captcha = "123425";
  sum = solveCaptcha2(captcha);
  cout << "Sum of " << captcha << " is: " << sum << endl;
  captcha = "123123";
  sum = solveCaptcha2(captcha);
  cout << "Sum of " << captcha << " is: " << sum << endl;
  captcha = "12131415";
  sum = solveCaptcha2(captcha);
  cout << "Sum of " << captcha << " is: " << sum << endl;
}

int main() {
  string captcha{""};
  cin >> captcha;
  int sum{solveCaptcha2(captcha)};
  cout << "Sum of " << captcha << " is: " << sum << endl;
  return 0;
}
