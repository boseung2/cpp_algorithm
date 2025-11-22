#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> arr;

void recursion(int x, int y, int size) {
  if (size == 1) {
    arr[x][y] = '*';
    return;
  }
  int sub = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // (1, 1) 위치는 공백
      if (i == 1 && j == 1) {
        continue;
      }
      recursion(x + i * sub, y + j * sub, sub);
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  arr.assign(n, vector<char>(n, ' '));
  recursion(0, 0, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j];
    }
    cout << '\n';
  }

  return 0;
}

/*
void fill3(int x, int y) {
  // 3x3 패턴을 직접 그림
  arr[x][y] = '*';
  arr[x][y+1] = '*';
  arr[x][y+2] = '*';
  arr[x+1][y] = '*';
  arr[x+1][y+1] = ' ';
  arr[x+1][y+2] = '*';
  arr[x+2][y] = '*';
  arr[x+2][y+1] = '*';
  arr[x+2][y+2] = '*';
}

void recursion(int x, int y, int size) {
  if (size == 3) {
    fill3(x, y);
    return;
  }
  int sub = size / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      recursion(x + i*sub, y + j*sub, sub);
    }
  }
}
*/