#include <queue>
#include <iostream>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1005][1005];
bool vis[1005][1005];

int main(void) {
  int n, m;
    cin >> n >> m;

    int min = INT_MAX;
    pair<int, int> minpair = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int pos;
            cin >> pos;
            board[i][j] = pos;
            if (min >= pos)
            {
                min = pos;
                minpair = { i,j };
            }
        }
    }
    queue <pair<int, int>> q;
    q.push(minpair);
    int count = 0;

    //cout << minpair.first << " " << minpair.second << endl;


    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] == true)
                continue;


            // 현재 == 0, 주위 == 0 -> push 후 넘어감
            if (board[cur.first][cur.second] == 0 && board[nx][ny] == 0)
            {
                cout << "1" << endl;
                vis[cur.first][cur.second] = true;
                q.push({ nx,ny });
                continue;
            }
            // 현재 == 0, 주위 != 0 -> 주위만 -1씩 하면서 count++
            else if (board[cur.first][cur.second] == 0 && board[nx][ny] != 0)
            {
                while (board[nx][ny] != 0)
                {
                    board[nx][ny] -= 1;
                    count++;
                    q.push({ nx,ny });
                    cout << "2" << endl;
                }
            }
            // 현재 != 0, 주위 !=0 -> 둘 중 하나 0될 때 까지 -1씩 하면서 count++
            else if (board[cur.first][cur.second] != 0 && board[nx][ny] != 0)
            {
                while (board[cur.first][cur.second] == 0 || board[nx][ny] == 0)
                {
                    if (board[cur.first][cur.second] != 0)
                        board[cur.first][cur.second] -= 1;
                    if (board[nx][ny] != 0)
                        board[nx][ny] -= 1;
                    count++;
                    q.push({ nx,ny });
                    cout << "3" << endl;
                }
            }
            // 현재 != 0, 주위 ==0 -> 현재가 0될 때 까지 -1, count++
            else if (board[cur.first][cur.second] != 0 && board[nx][ny] == 0)
            {
                while (board[cur.first][cur.second] != 0)
                {
                    board[cur.first][cur.second] -= 1;
                    count++;
                    q.push({ nx,ny });
                    cout << "4" << endl;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}