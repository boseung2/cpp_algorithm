#include<iostream>

using namespace std;

bool isPrime(int n) {
  // 0,1은 소수 아님
  if(n<2) return false;
  // 제곱근까지 나누어 떨어지면 소수 아님
  for(int i=2; i*i<=n; i++) {
    if(n%i == 0) return false;
  }
  return true;
}

int main(void) {
  int n;
  int a[1000];
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  int count = 0;
  for(int i=0; i<n; i++) {
    if(isPrime(a[i])) count++;
  }
  cout << count;

}