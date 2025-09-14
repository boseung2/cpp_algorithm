#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
void print(vector<int> list) {
  cout << "[";
  for(int x : list) {
    cout << x << ", ";
  }
  cout << "]" << endl;
}

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  vector<int> matchCnt(3);
  vector<int> firstPattern = {1, 2, 3, 4, 5};
  vector<int> secondPattern = {2, 1, 2, 3, 2, 4, 2, 5};
  vector<int> thirdPattern = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

  for(int i=0; i<answers.size(); i++) {
    if(answers[i] == firstPattern[i % firstPattern.size()]) {
      matchCnt[0]++;
    }
    if(answers[i] == secondPattern[i % secondPattern.size()]) {
      matchCnt[1]++;
    }
    if(answers[i] == thirdPattern[i % thirdPattern.size()]) {
      matchCnt[2]++;
    } 
  }

  int maxScore = *max_element(matchCnt.begin(), matchCnt.end());

  for(int i=0; i<3; i++) {
    if(matchCnt[i] == maxScore) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}

int main(void) {
  print(solution({1, 2, 3, 4, 5}));
  print(solution({1, 3, 2, 4, 2}));
}