#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;

  int s = 0;

  for (int i = 0; i < m; i++) {
    string cmd;
    int value;
    cin >> cmd;

    if (cmd == "add") {
      cin >> value;
      s |= (1 << value);
    } else if (cmd == "remove") {
      cin >> value;
      s &= ~(1 << value);
    } else if (cmd == "check") {
      cin >> value;
      if (s & (1 << value))
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
    } else if (cmd == "toggle") {
      cin >> value;
      s ^= (1 << value);
    } else if (cmd == "all") {
      s = (1 << 21) - 1;
    } else if (cmd == "empty") {
      s = 0;
    }
  }
  return 0;
}