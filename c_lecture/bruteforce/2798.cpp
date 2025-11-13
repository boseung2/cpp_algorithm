#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // arr을 돌면서 3개를 고르는 모든 경우의 수를 확인한다.
  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = arr[i] + arr[j] + arr[k];
        if (sum <= m && sum > answer) {
          answer = sum;
        }
      }
    }
  }
  cout << answer << "\n";
}