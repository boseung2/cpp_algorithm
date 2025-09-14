#include<stack>
#include<string>
#include<iostream>

using namespace std;

int solution(string s) {
  stack<char> stk;

  for(int i=0; i<s.length(); i++) {
    if(stk.empty() || stk.top() != s[i]) {
      stk.push(s[i]);
    } else {
      stk.pop();
    }
  }

  return stk.empty();
}

int main(void) {
  cout << solution("baabaa") << endl;
}