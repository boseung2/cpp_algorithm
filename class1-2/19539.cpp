#include<iostream>

using namespace std;

int main(void) {
  int n;
  int h[100001];

  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> h[i];
  }

  int sum = 0;
  int countTwo = 0;
  for(int i=0; i<n; i++) {
    sum += h[i];
    countTwo += (h[i] / 2);
  }
  int countThree = sum / 3;

  if(sum % 3 == 0) {
    if(countTwo >= countThree) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }

}