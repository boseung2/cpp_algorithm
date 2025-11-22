#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;
long long result = 1;

int main(void) {
  int c, n;
  cin >> c;

  for (int i = 0; i < c; i++) {
    cin >> n;
    map.clear();
    for (int j = 0; j < n; j++) {
      string a, b;
      cin >> a >> b;
      map[b]++;
    }

    result = 1;
    for (auto& p : map) {
      result *= (p.second + 1);
    }

    result -= 1;
    cout << result << "\n";
  }

  return 0;
}