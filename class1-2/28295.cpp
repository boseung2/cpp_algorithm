#include<iostream>

using namespace std;

int main(void) {
  int input[10];
  for(int i=0; i<10; i++) {
    cin >> input[i];
  }

  int sum = 0;
  for(int i=0; i<10; i++) {
    if(input[i] == 1) {
      sum += 1;
    } else if(input[i] == 2) {
      sum += 2;
    } else if(input[i] == 3) {
      sum -= 1;
    }
  }

  if(sum >= 0) {
    int result = sum % 4;
    if(result == 0) {
      cout << "N";
    } else if(result == 1) {
      cout << "E";
    } else if(result == 2) {
      cout << "S";
    } else if(result == 3) {
      cout << "W";
    }
  } else {
    int result = sum % 4;
    if(result == 0) {
      cout << "N";
    } else if(result == -1) {
      cout << "W";
    } else if(result == -2) {
      cout << "S";
    } else if(result == -3) {
      cout << "E";
    }
  }
}