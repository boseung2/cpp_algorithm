#include<iostream>

using namespace std;

int apply_weight(int digit, int index) {
  return (index % 2 == 0) ? digit : digit * 3;
}

int main(void) {
  string s;
  cin >> s;
  
  int sum = 0;
  int star_index = 0;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == '*') {
      star_index = i;
      continue;
    }
    int digit = s[i] - '0';
    sum += apply_weight(digit, i);
  }

  for(int i=0; i<10; i++) {
    int total = sum + apply_weight(i, star_index);
    if(total % 10 == 0) {
      cout << i;
    }
  }

}