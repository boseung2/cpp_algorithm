#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> arr;

int main(void) {
  int n;
  cin >> n;
  arr.assign(n, vector<char>(n, ' '));
}