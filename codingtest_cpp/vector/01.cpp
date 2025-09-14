#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
  sort(arr.begin(), arr.end());
  return arr;
}

void print(vector<int> vec) {
  for(int x : vec) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  print(solution({1, -5, 2, 4, 3}));
}