#include<iostream>
#include<cctype>
#include<string>

using namespace std;

bool isDigit(string s) {
  if(s.empty()) return false;
  for(char c : s) {
   if(!isdigit(c)) {
    return false;
   } 
  }
  return true;
}

int main(void) {
  string x[3];
  cin >> x[0] >> x[1] >> x[2];
  int value = 0;
  for(int i=0; i<3; i++) {
    if(isDigit(x[i])) {
      value = stoi(x[i]) + (3-i);
      break;
    }
  }
  bool d3 = value % 3 == 0;
  bool d5 = value % 5 == 0;
  if(d3 && d5) {
    cout << "FizzBuzz";
  }else if(d3) {
    cout << "Fizz";
  }else if(d5) {
    cout << "Buzz";
  }else {
    cout << value;
  }
}