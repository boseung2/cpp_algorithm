#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

int recursion(const string& s, int l, int r) {
  cnt++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string& s) { return recursion(s, 0, s.length() - 1); }

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int result = isPalindrome(s);
    cout << result << " " << cnt << "\n";
    cnt = 0;
  }
  return 0;
}