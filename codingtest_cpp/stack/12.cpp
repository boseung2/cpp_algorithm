#include<stack>
#include<string>
#include<vector>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size());
  stack<int> s;

  int priceNum = prices.size();
  
  // prices 배열 돌기
  for(int i=0; i<priceNum; i++) {
    // 스택에 값 있고, 이전 값이 현재 값 보다 클 때 -> 계속 돌면서
    // 답 : 현재 인덱스 - 스택 위 인덱스
    // 답을 구했다면 stack은 pop한다.
    while(!s.empty() && prices[s.top()] > prices[i]) {
      answer[s.top()] = i - s.top();
      s.pop();
    }
    // 스택에 비었다면 비교할게 없으므로 그냥 푸쉬
    s.push(i);
  }

  // 스택 남은거 돌면서
  // 마지막 까지 살아있는 애들 정답 : 전체 일수 - 인덱스 - 1
  // 답을 구했다면 pop한다.
  while(!s.empty()) {
    answer[s.top()] = priceNum - s.top() - 1;
    s.pop();
  }

  return answer;
}

int main(void) {

}
