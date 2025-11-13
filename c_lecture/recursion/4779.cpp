#include <iostream>

using namespace std;

void recursion(string& s, int start, int end) {
  // 3등분 해서 가운데 부분을 공백으로 바꿈
  int len = end - start;
  // 길이가 3 미만이면 재귀 종료
  if (len < 3) {
    return;
  }
  // 길이가 3 이상이면 재귀 호출
  int part = len / 3;
  for (int i = start + part; i < start + 2 * part; i++) {
    s[i] = ' ';
  }
  recursion(s, start, start + part);
  recursion(s, start + 2 * part, end);
}

int main(void) {
  // 계속 숫자를 입력받음
  int n;
  while (cin >> n) {
    int len = 1;
    for (int i = 0; i < n; i++) {
      len *= 3;
    }
    string s(len, '-');
    recursion(s, 0, len);
    cout << s << "\n";
  }
}