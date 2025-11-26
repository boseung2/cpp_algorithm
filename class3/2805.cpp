#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> trees;

int main(void) {
  int n, m;
  cin >> n >> m;
  trees.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> trees[i];
  }

  long long low = 0;
  long long high = *max_element(trees.begin(), trees.end());
  long long answer = 0;

  while (low <= high) {
    long long mid = (low + high) / 2;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      if (trees[i] > mid) {
        sum += trees[i] - mid;
      }
    }

    if (sum >= m) {
      answer = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << answer << "\n";
}