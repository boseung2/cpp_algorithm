#include<iostream>
#include<string>

using namespace std;

int main(void) {
  string s1;
  cin >> s1;
  int len =  s1.length();

  for(int i=1; i<=999; i++) {
    string s2 = "";

    // j는 i부터 s1의 len만큼 돌아야함
    int j = i;
    int a = i;
    int b = i;
    while(s2.length() < len) {
      s2 += to_string(j);
      b = j;
      j++;
    }
    if(s1 == s2) {
      cout << a << " " << b;
      break;
    }
  }
}