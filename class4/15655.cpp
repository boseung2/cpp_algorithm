#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int pick[9];
bool used[10000];

void dfs(int depth, int start) {
  if (depth == m) {
    for (int i = 0; i < m; i++) {
      cout << pick[i] << (i + 1 == m ? '\n' : ' ');
    }
    return;
  }

  for (int i = start; i <= n; i++) {
    if (!used[arr[i]]) {
      used[arr[i]] = true;
      pick[depth] = arr[i];
      dfs(depth + 1, i);
      used[arr[i]] = false;
    }
  }
}

int main(void) {
  cin >> n >> m;
  arr.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  dfs(0, 1);
}