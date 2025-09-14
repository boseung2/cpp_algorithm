#include<iostream>

using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;

  // n! / k!(n-k)!
  // n(n-1)...(n-k+1) / k!
  int result = 1;
  for (int i = 1; i <= k; ++i) {
      result = result * (n - i + 1) / i;
  }

  cout << result;

}