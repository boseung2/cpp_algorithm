#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  int l;
  string s;
  cin >> l >> s;
  long long sum = 0;
  long long m = 1234567891;
  long long r = 1;

  for(int i=0; i<s.length(); i++) {
    int num = s[i] - 'a' + 1;    
    sum = (sum + num * r) % m;
    r = (r * 31) % m;
  }
  cout << sum;
}