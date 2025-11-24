#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void average(const vector<int>& arr) {
  long long sum = 0;
  for (int num : arr) {
    sum += num;
  }
  int result = (int)round((double)sum / arr.size());
  cout << result << "\n";
}

void median(vector<int> arr) {
  sort(arr.begin(), arr.end());
  int result = arr[arr.size() / 2];
  cout << result << "\n";
}

void mode(const vector<int>& arr) {
  // -4000 ~ 4000 까지 가능하므로 8001 크기의 count 배열 생성
  vector<int> count(8001, 0);
  for (int num : arr) {
    count[num + 4000]++;
  }
  // count 전체 돌면서 최빈값 찾기
  int maxValue = 0;
  for (int c : count) {
    if (c > maxValue) maxValue = c;
  }

  int modeValue = 0;
  bool first = true;
  for (int i = 0; i < 8001; i++) {
    if (count[i] == maxValue) {
      modeValue = i - 4000;  // 다시 실제 값으로
      if (first) {
        first = false;  // 첫 번째 최빈값
      } else {
        break;  // 두 번째 최빈값에서 멈춤
      }
    }
  }
  cout << modeValue << "\n";
}

void range(const vector<int>& arr) {
  int minValue = *min_element(arr.begin(), arr.end());
  int maxValue = *max_element(arr.begin(), arr.end());
  int result = maxValue - minValue;
  cout << result << "\n";
}

int main(void) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  average(arr);
  median(arr);
  mode(arr);
  range(arr);

  return 0;
}
