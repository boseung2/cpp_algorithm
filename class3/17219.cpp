#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> map;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string site, pwd;
    cin >> site >> pwd;
    map[site] = pwd;
  }

  for (int i = 0; i < m; i++) {
    string site;
    cin >> site;
    cout << map[site] << "\n";
  }
}