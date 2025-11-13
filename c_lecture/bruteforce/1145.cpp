#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  vector<int> arr(5);
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  // 가장 작은 수부터 시작
  // 쭉 올라가면서 arr[0] ~ arr[4]을 나누었을때 나누어 떨어지는지 확인
  // 나누어 떨어지는 수가 3개 이상이 되면 그 수를 출력하고 종료
  sort(arr.begin(), arr.end());

  for (int i = arr[0];; i++) {
    int count = 0;
    // a[0] ~ a[4]까지 확인하면서 나누어 떨어지면 count++
    for (int j = 0; j < 5; j++) {
      if (arr[j] % i == 0) {
        count++;
      }
    }
    if (count >= 3) {
      cout << i << "\n";
      break;
    }
  }

  return 0;
}