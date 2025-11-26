#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> tmp;

int main(void) {
  int n;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  tmp = arr;
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

  for (int i = 0; i < n; i++) {
    int index = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    cout << index << " ";
  }
}