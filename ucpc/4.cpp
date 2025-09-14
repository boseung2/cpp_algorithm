#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1005][1005];
bool vis[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
    int count = 0;
    queue <pair<int, int>> q;
    q.push(minpair);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (vis[nx][ny] == true || nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

              // 현재 == 0, 주위 == 0 -> push 후 넘어감
            if (board[cur.first][cur.second] == 0 && board[nx][ny] == 0)
            {
                vis[cur.first][cur.second] = true;
                q.push({ nx,ny });
                continue;
            }
            // 현재 == 0, 주위 != 0 -> 주위만 -1씩 하면서 count++
            else if (board[cur.first][cur.second] == 0 && board[nx][ny] != 0)
            {
                count += board[nx][ny];
                board[nx][ny] = 0;
                q.push({ nx,ny });
                vis[cur.first][cur.second] = true;
            }
            // 현재 != 0, 주위 !=0 -> 둘 중 하나 0될 때 까지 -1씩 하면서 count++
            else if (board[cur.first][cur.second] != 0 && board[nx][ny] != 0)
            {
                if (board[cur.first][cur.second] <= board[nx][ny])
                    count += board[nx][ny];
                else
                    count += board[cur.first][cur.second];
                board[cur.first][cur.second] = 0;
                board[nx][ny] = 0;
                q.push({ nx,ny });
                vis[cur.first][cur.second] = true;
            }

            //else if (board[cur.first][cur.second] != 0 && board[nx][ny] == 0)
            //{
            //    count += board[cur.first][cur.second];
            //    board[cur.first][cur.second];
            //    q.push({ nx,ny });
            //    vis[cur.first][cur.second] = true;
            //}
        }
    }


    cout << count << "\n";

    return 0;
}