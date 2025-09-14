#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> input(n);
  stack<int> stack;
  vector<char> result;

  for(int i=0; i<n; i++) {
    cin >> input[i];
  }

  // 1~n array 만든다.
  // stack 
  int j=0;
  for(int i=1; i<=n; i++) {
    stack.push(i);
    result.push_back('+');

    // top 값이 target값과 같으면 pop한다.
    while(!stack.empty() && stack.top() == input[j]) {
      stack.pop();
      result.push_back('-');
      j++;
    }
  }

  if(!stack.empty()) {
    cout << "NO" << "\n";
  } else {
    for(int i=0; i<result.size(); i++) {
     cout << result[i] << "\n";
    }
  }

  
}