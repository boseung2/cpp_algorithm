#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

int main(void) {
  int n;
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  int prefix = 0;
  int answer = 0;
  for (int i = 0; i < p.size(); i++) {
    prefix += p[i];
    answer += prefix;
  }

  cout << answer << "\n";
}