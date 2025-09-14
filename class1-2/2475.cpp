#include<iostream>

using namespace std;

int main(void) {
  int a[5];
  int length = sizeof(a) / sizeof(a[0]);
  for(int i=0; i<length; i++) {
    cin >> a[i];
  }

  int sum = 0;
  for(int i=0; i<length; i++) {
    sum += a[i] * a[i];
  }
  cout << sum % 10;
}