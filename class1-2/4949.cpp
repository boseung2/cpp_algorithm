#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
  string line;
  while (true) {
    if (!getline(cin, line)) break;  // EOF
    if (line == ".") break;          // 종료 조건

    stack<char> s;
    bool ok = true;

    for (char c : line) {
      if (c == '(' || c == '[') {
        s.push(c);
      } else if (c == ')') {
        if (s.empty() || s.top() != '(') {
          ok = false;
          break;
        }
        s.pop();
      } else if (c == ']') {
        if (s.empty() || s.top() != '[') {
          ok = false;
          break;
        }
        s.pop();
      }
      // 그 외 문자는 무시
    }

    if (ok && s.empty())
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}