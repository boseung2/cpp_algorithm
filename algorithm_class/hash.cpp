#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int findPrime(int n) {
  int m = 2 * n;
  while (!isPrime(m)) m++;
  return m;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int m = findPrime(n);
  vector<int> hashTable(m, -1);

  int cnt = 0;
  for (int x : nums) {
    int i = 0;
    while (true) {
      int h = (x + i) % m;
      if (hashTable[h] == -1) {
        hashTable[h] = x;
        break;
      } else {
        cnt++;
        i++;
      }
    }
  }

  cout << cnt << "\n";

  return 0;
}