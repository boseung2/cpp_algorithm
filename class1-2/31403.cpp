#include<iostream>
#include<string>

using namespace std;

int main(void) {
  int a=0, b=0, c=0;
  cin >> a >> b >> c;

  cout << a + b - c << endl;

  string s = "";
  s = s + to_string(a) + to_string(b);
  cout << stoi(s) - c;
}