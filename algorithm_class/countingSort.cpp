#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<int>& a) {
  // a에서 max, min 값 찾기
  int n = a.size();
  if (n == 0) return;
  int max = a[0];
  int min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
  }
  // k = max - min + 1
  int k = max - min + 1;
  // c배열 생성
  vector<int> c(k);
  // 각 원소 카운팅
  for (int i = 0; i < n; i++) {
    c[a[i] - min]++;
  }
  // c배열 누적합
  for (int i = 1; i < k; i++) {
    c[i] += c[i - 1];
  }
  // C배열 출력
  for (int i = 0; i < n; i++) {
    if (c[i] != 0) {
      cout << c[i] << (i == n - 1 ? "\n" : " ");
    }
  }
  // B배열에 정렬된 결과 저장
  vector<int> b(n);
  for (int i = n - 1; i >= 0; i--) {
    b[c[a[i] - min] - 1] = a[i];
    c[a[i] - min]--;
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  counting_sort(a);
}