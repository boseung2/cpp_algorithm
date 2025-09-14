#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, float>& a, pair<int, float>& b) {
  // 실패율 같으면 stage수 적은 수 먼저 정렬
  if(a.second == b.second) {
    return a.first < b.first;
  }
  // 실패율 다르면 실패율 높은 순서로 정렬
  return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  vector<float> challenger(N+1, 0.0);
  vector<float> fail(N+2, 0.0);

  // stage마다 도전자수, 실패자수 입력
  for(int i=0; i<stages.size(); i++) {
    for(int j=0; j<=stages[i]; j++) {
      challenger[j]++;
    }
    fail[stages[i]]++;
  }

  // 실패율 계산 <stage, 실패율>
  vector<pair<int, float>> failRatio(N);
  for(int i=0; i<N; i++) {
    failRatio[i].first = i + 1;

    if(challenger[i+1] == 0) {
      failRatio[i].second = 0;
    } else {
      failRatio[i].second = fail[i+1] / challenger[i+1];
    }
  }

  // failRatio 정렬
  sort(failRatio.begin(), failRatio.end(), compare);

  // 정렬된 순서대로 answer에 저장
  for(int i=0; i<N; i++) {
    answer.push_back(failRatio[i].first);
  }

  return answer;
}

void print(vector<int> arr) {
  for(int x : arr) {
    cout << x << ", ";
  }
}

int main(void) {
  print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3}));
}