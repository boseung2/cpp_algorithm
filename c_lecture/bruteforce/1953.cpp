#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  // arr 배열에서 순서대로 a, b, c, d, e, f에 넣는다.
  int a, b, c, d, e, f = 0;
  int x, y;
  cin >> a >> b >> c >> d >> e >> f;
  // x : -999 ~ 999
  // y : -999 ~ 999
  for (x = -999; x <= 999; x++) {
    for (y = -999; y <= 999; y++) {
      if (a * x + b * y == c && d * x + e * y == f) {
        cout << x << " " << y << "\n";
        return 0;
      }
    }
  }
}