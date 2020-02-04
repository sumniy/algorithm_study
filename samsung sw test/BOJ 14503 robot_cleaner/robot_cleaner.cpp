#include <iostream>
#include <fstream>

using namespace std;

int dir, y, x, N, M; // y = r , x = c
int dir_chk;
int answer;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int map[50][50];
bool chk[50][50];

void clean()
{
  int ny, nx;
  while (1)
  {
    if (chk[y][x] == 0)
    {
      chk[y][x] = 1;
      answer++;
    }

    dir_chk = 0;
    while (dir_chk < 4)
    {
      dir -= 1;
      if (dir == -1)
        dir = 3;
      dir_chk++;

      ny = y + dy[dir];
      nx = x + dx[dir];

      if (chk[ny][nx] == 0 && map[ny][nx] == 0)
      {
        y = y + dy[dir];
        x = x + dx[dir];
        dir_chk=0;
        break;
      }
    }
    if (dir_chk == 4)
    {
      ny = y - dy[dir];
      nx = x - dx[dir];
      if (map[ny][nx] == 0)
      {
        y = ny;
        x = nx;
      }
      else
        return;
    }
  }
}

int main()
{
  ifstream input("input.txt");

  input >> N >> M >> y >> x >> dir;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      input >> map[i][j];

  answer = 0;
  clean();
  cout << answer << endl;
}