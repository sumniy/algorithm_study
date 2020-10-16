#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int n;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> dp;

int dfs(vector<vector<int>> &board, int y, int x)
{
  if (dp[y][x] == -1)
  {
    dp[y][x] = 1;
    int max_cnt = 0;

    for (int dir = 0; dir < 4; dir++)
    {
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] <= board[y][x])
        continue;

      max_cnt = max(max_cnt, dfs(board, ny, nx));
    }
    dp[y][x] += max_cnt;
  }
  return dp[y][x];
}

int getMaxCnt(vector<vector<int>> &board)
{
  int max_cnt = 0;

  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < n; x++)
    {
      max_cnt = max(max_cnt, dfs(board, y, x));
    }
  }

  return max_cnt;
}

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  vector<vector<int>> board(n, vector<int>(n, 0));
  for (auto &row : board)
  {
    for (auto &col : row)
    {
      cin >> col;
    }
  }

  dp.assign(n, vector<int>(n, -1));

  cout << getMaxCnt(board);

  return 0;
}