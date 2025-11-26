#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> lines;

int main(void) {
  int k, n;
  cin >> k >> n;

  lines.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> lines[i];
  }

  long long min = 1;
  long long max = *max_element(lines.begin(), lines.end());
  long long answer = 0;

  while (min <= max) {
    long long mid = (min + max) / 2;
    long long cnt = 0;

    for (int i = 0; i < k; i++) {
      if (lines[i] >= mid) {
        cnt += lines[i] / mid;
      }
    }

    if (cnt >= n) {
      answer = mid;
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }

  cout << answer << "\n";
}