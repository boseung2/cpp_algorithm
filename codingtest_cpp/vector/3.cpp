#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> solution(vector<int> numbers) {
  set<int> sum;

  // numbers 돌면서 앞의 수와 뒤에 수 각각 더함
  for(int i=0; i<numbers.size() - 1; i++) {
    for(int j=i+1; j<numbers.size(); j++) {
      sum.insert(numbers[i] + numbers[j]);
    }
  }

  vector<int> answer(sum.begin(), sum.end());
  return answer;
}

void print(vector<int> list) {
  cout << "[";
  for(int x : list) {
    cout << x << ", ";
  }
  cout << "]" << endl;
}

int main(void){
  print(solution({5, 0, 2, 7}));
}