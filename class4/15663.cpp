#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int pick[9];
bool used[9];

void dfs(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; i++) {
      cout << pick[i] << (i + 1 == m ? '\n' : ' ');
    }
    return;
  }

  int last = 10001;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    if (arr[i] == last) continue;

    used[i] = true;
    pick[depth] = arr[i];
    last = arr[i];

    dfs(depth + 1);

    used[i] = false;
  }
}

int main(void) {
  cin >> n >> m;
  arr.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  dfs(0);
}