#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // 모든 8x8을 잘라서 확인
  // w시작 경우, b시작 경우 구분
  // 각 경우 칠하는 경우 구하고 최소값 출력
  int count = 0;
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= j - 8; j++) {
    }
  }
}