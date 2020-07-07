#include <iostream>
#include <vector>

using namespace std;

const int SHARK = -1;

class Shark
{
public:
  Shark(int dir)
  {
    dir = dir;
    y = 0;
    x = 0;
  }
  int dir;
  int y;
  int x;
}

class Fish
{
public:
  Fish(int y, int x, int num, int dir)
  {
    is_alive = true;
    y = y;
    x = x;
    num = num;
    dir = dir;
  };
  void BeEaten()
  {
    is_alive = false;
    y = -1;
    x = -1;
    dir = -1;
  }

  bool is_alive;
  int y;
  int x;
  int num;
  int dir;
};

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int board[4][4];
Fish fishes[16];

void MoveFishes()
{
  Fish fish;
  for(int i=0;i<16;i++)
  {
    MoveFish(i);
  }
}

void MoveFish(int num)
{
  Fish *fish = &fishes[num];
  if(fish->is_alive == false) return;

  for(int i=0;i<8;i++)
  {
    int dir = fish->dir - i;
    if(dir < 0) dir += 8;

    int next_y = fish->y + dy[dir];
    int next_x = fish->x + dx[dir];

    int *next = &board[next_y][next_x];

    if(next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4 || next == SHARK)
      continue;

    int curr_y = fish->y;
    int curr_x = fish->x;

    if(next == 0)
    {
      board[curr_y][curr_x] = 0;
    }
    else
    {
      Fish *next_fish = &fishes[next];
      next_fish->y = curr_y;
      next_fish->x = curr_x;
      board[curr_y][curr_x] = next;
    }
    board[next_y][next_x] = num;
    fish->y = next_y;
    fish->x = next_x;
    fish->dir = dir;
  }
}

int DFS(Shark& shark, int sum)
{

}

int main()
{
  freopen("input.txt", "r", stdin);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      int num, dir;
      cin >> num >> dir;
      board[i][j] = num;
      fishes[num] = new Fish(i, j, num, dir);
    }
  }
  int first_fish = board[0][0];
  int sum = fishes[first_fish].num;
  Shark shark = new Shark(fishes[first_fish].dir);
  fishes[first_fish].BeEaten();



}