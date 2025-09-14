#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[11][11][4];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int todir(char dir) {
  if(dir == 'U') return 0;
  if(dir == 'R') return 1;
  if(dir == 'D') return 2;
  if(dir == 'L') return 3;
}

bool isNotValid(int x, int y) {
  return x<0 || y<0 || x>10 || y>10;
}

int opposite_direction(int dir) {
  return (dir +2) % 4;
}

int solution(string dirs) {
  int answer = 0;
  int x = 5, y = 5;
  for(char c : dirs) {
    int dir = todir(c);
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(isNotValid(nx, ny)) {
      continue;
    }

    if(visited[y][x][dir] == false) {
      
      visited[y][x][dir] = true;
      visited[ny][nx][opposite_direction(dir)] = true;
      answer++;
    }

    x = nx;
    y = ny;
  }

  return answer;
}

int main(void) {
  // 호우..
}