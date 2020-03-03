#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

int N;
int board[20][20];
int max = -1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

#define CHECK i + dy[d] >= 0 && i + dy[d] < N &&j + dx[d] >= 0 && j + dx[d] < N
#define CHECK n_dy >= 0 && n_dy < N &&n_dx >= 0 && n_dx < N

int move(int d)
{
  int i, j;
  int n_dy, n_dx;
  // 방향별로 따로 계산
  if (d == 0)
  {
    // 먼저 합치는 과정
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
        if (board[i][j] == 0)
          continue;

        n_dy = i + dy[d];
        n_dx = j + dx[d];
        // 한번 싹 다 합치고나서 이동해줘야 제대로 작동함
        while (CHECK)
        {
          if (board[n_dy][n_dx] == 0)
          {
            n_dy = i + dy[d];
            n_dx = j + dx[d];
            continue;
          }
          else
          {
            if (board[n_dy][n_dx] != board[i][j])
              break;
            else if (board[n_dy][n_dx] == board[i][j])
            {
              board[n_dy][n_dx] *= 2;
              board[i][j] = 0;
              break;
            }
          }
        }

        if (CHECK)
        {

          if (board[n_dy][n_dx] == board[i][j])
          {
            board[n_dy][n_dx] *= 2;
            board[i][j] = 0;
          }
        }
      }
    }
  }
}

void dfs(int time, int cur_max)
{
  if (time == 5)
  {
    if (cur_max > max)
      max = cur_max;
    return;
  }

  int temp[20][20];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      temp[i][j] = board[i][j];

  for (int dir = 0; dir < 4; dir++)
  {
    cur_max = move(dir);
    dfs(time + 1, cur_max);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        board[i][j] = temp[i][j];
  }
}

int main()
{
  ifstream input("input.txt");
  input >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      input >> board[i][j];
}