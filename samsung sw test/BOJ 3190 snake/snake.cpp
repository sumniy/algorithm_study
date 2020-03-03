#include <cstdlib>
#include <queue>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int N, K, L, time = 0, dir = 1;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int board[105][105];
int y, x, tail_y, tail_x;
bool isFinish = false;
queue<pair<int, char>> TurnInfo;
queue<int> tail_dir;

void init()
{
  y = 1;
  x = 1;
  tail_y = 1;
  tail_x = 1;
  time = 0;
  dir = 1;
  ifstream input("input.txt");
  input >> N >> K;
  for (int i = 0; i < N + 2; i++)
  {
    for (int j = 0; j < N + 2; j++)
    {
      board[0][j] = -2;
      board[N + 1][j] = -2;
      board[i][0] = -2;
      board[i][N + 1] = -2;
    }
  }

  int row, col;
  for (int i = 0; i < K; i++)
  {
    input >> row >> col;
    board[row][col] = 1;
  }

  board[1][1] = -1;

  input >> L;
  int t;
  char t_dir;
  for (int i = 0; i < L; i++)
  {
    input >> t >> t_dir;
    TurnInfo.push(make_pair(t, t_dir));
  }
}

void Turn(char LD)
{
  if (LD == 'L')
  {
    dir -= 1;
    if (dir < 0)
      dir += 4;
  }
  else if (LD == 'D')
  {
    dir += 1;
    if (dir > 3)
      dir -= 4;
  }
  else
  {
    printf("Turn error : unexpected Turn command inputed");
  }
}

void Move()
{
  tail_dir.push(dir);
  int ny = y + dy[dir];
  int nx = x + dx[dir];

  if (board[ny][nx] < 0)
  {
    isFinish = true;
    return;
  }
  else if (board[ny][nx] == 1) // 사과 존재
  {
    board[ny][nx] = -1;
    y = ny;
    x = nx;
  }
  else if (board[ny][nx] == 0)
  {
    board[ny][nx] = -1;
    y = ny;
    x = nx;

    board[tail_y][tail_x] = 0;

    tail_y += dy[tail_dir.front()];
    tail_x += dx[tail_dir.front()];
    tail_dir.pop();
  }
}

int main()
{
  init();

  while (!isFinish)
  {
    if (time == TurnInfo.front().first)
    {
      Turn(TurnInfo.front().second);
      TurnInfo.pop();
      Move();
    }
    else
    {
      Move();
    }

    time++;
  }

  printf("%d", time);
}