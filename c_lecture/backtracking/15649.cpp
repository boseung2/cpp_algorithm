#include <iostream>

using namespace std;

int N, M;      // 입력값: 1~N 중에서 M개 고르기
int pick[9];   // 현재 고른 숫자들을 저장 (M ≤ 8이므로 9로 충분)
bool used[9];  // 숫자 사용 여부 표시

// 깊이 우선 탐색 (DFS)
void dfs(int depth) {
  // 종료 조건: M개 다 골랐으면 출력
  if (depth == M) {
    for (int i = 0; i < M; ++i) {
      cout << pick[i] << (i + 1 == M ? '\n' : ' ');
    }
    return;
  }

  // 1부터 N까지 모든 숫자 시도
  for (int i = 1; i <= N; ++i) {
    // 아직 사용하지 않은 숫자만 선택
    if (!used[i]) {
      used[i] = true;   // i를 사용했다고 표시
      pick[depth] = i;  // 현재 depth 자리에 i 저장
      dfs(depth + 1);   // 다음 자리(depth+1)로 재귀 호출
      used[i] = false;  // 돌아오면 사용 표시 해제 (백트래킹)
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;  // 입력 받기
  dfs(0);         // depth=0부터 시작
  return 0;
}