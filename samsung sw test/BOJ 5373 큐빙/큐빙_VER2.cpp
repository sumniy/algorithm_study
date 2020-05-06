#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// w, y, r, o, g, b  색상
// U, D, F, B, L, R  방향

enum SURFACE
{
  UP,
  FRONT,
  LEFT,
  RIGHT,
  BACK,
  DOWN
};

vector<vector<char>> qube;

vector<char> surface(char color)
{
  vector<char> ret;
  for (int i = 0; i < 9; i++)
  {
    ret.push_back(color);
  }
  return ret;
}

void TurnTargetSurface(int sur_no, char dir)
{
  vector<char> temp = qube[sur_no];

  if (dir == '+')
  {
    temp[0] = qube[sur_no][6];
    temp[1] = qube[sur_no][3];
    temp[2] = qube[sur_no][0];
    temp[3] = qube[sur_no][7];
    temp[4] = qube[sur_no][4];
    temp[5] = qube[sur_no][1];
    temp[6] = qube[sur_no][8];
    temp[7] = qube[sur_no][5];
    temp[8] = qube[sur_no][2];
  }
  else if (dir == '-')
  {
    temp[0] = qube[sur_no][2];
    temp[1] = qube[sur_no][5];
    temp[2] = qube[sur_no][8];
    temp[3] = qube[sur_no][1];
    temp[4] = qube[sur_no][4];
    temp[5] = qube[sur_no][7];
    temp[6] = qube[sur_no][0];
    temp[7] = qube[sur_no][3];
    temp[8] = qube[sur_no][6];
  }

  qube[sur_no] = temp;
}

void TurnU()
{
  vector<vector<char>> temp_qube = qube;
  // B->R
  temp_qube[RIGHT][0] = qube[BACK][6];
  temp_qube[RIGHT][3] = qube[BACK][7];
  temp_qube[RIGHT][6] = qube[BACK][8];
  // R->F
  temp_qube[FRONT][0] = qube[RIGHT][6];
  temp_qube[FRONT][1] = qube[RIGHT][3];
  temp_qube[FRONT][2] = qube[RIGHT][0];
  // F->L
  temp_qube[LEFT][2] = qube[FRONT][0];
  temp_qube[LEFT][5] = qube[FRONT][1];
  temp_qube[LEFT][8] = qube[FRONT][2];
  // L->B
  temp_qube[BACK][8] = qube[LEFT][2];
  temp_qube[BACK][7] = qube[LEFT][5];
  temp_qube[BACK][6] = qube[LEFT][8];
  qube = temp_qube;
}

void TurnD()
{
  vector<vector<char>> temp_qube = qube;
  // B->L
  temp_qube[LEFT][6] = qube[BACK][0];
  temp_qube[LEFT][3] = qube[BACK][1];
  temp_qube[LEFT][0] = qube[BACK][2];

  // L->F
  temp_qube[FRONT][8] = qube[LEFT][6];
  temp_qube[FRONT][7] = qube[LEFT][3];
  temp_qube[FRONT][6] = qube[LEFT][0];

  // F->R
  temp_qube[RIGHT][2] = qube[FRONT][8];
  temp_qube[RIGHT][5] = qube[FRONT][7];
  temp_qube[RIGHT][8] = qube[FRONT][6];

  // R->B
  temp_qube[BACK][0] = qube[RIGHT][2];
  temp_qube[BACK][1] = qube[RIGHT][5];
  temp_qube[BACK][2] = qube[RIGHT][8];

  qube = temp_qube;
}
void TurnR()
{
  vector<vector<char>> temp_qube = qube;
  // U-> B
  temp_qube[BACK][2] = qube[UP][2];
  temp_qube[BACK][5] = qube[UP][5];
  temp_qube[BACK][8] = qube[UP][8];

  // B->D
  temp_qube[DOWN][8] = qube[BACK][2];
  temp_qube[DOWN][5] = qube[BACK][5];
  temp_qube[DOWN][2] = qube[BACK][8];
  // D->F
  temp_qube[FRONT][2] = qube[DOWN][8];
  temp_qube[FRONT][5] = qube[DOWN][5];
  temp_qube[FRONT][8] = qube[DOWN][2];
  // F->U
  temp_qube[UP][2] = qube[FRONT][2];
  temp_qube[UP][5] = qube[FRONT][5];
  temp_qube[UP][8] = qube[FRONT][8];
  qube = temp_qube;
}
void TurnL()
{
  vector<vector<char>> temp_qube = qube;

  // U->F
  temp_qube[FRONT][6] = qube[UP][6];
  temp_qube[FRONT][3] = qube[UP][3];
  temp_qube[FRONT][0] = qube[UP][0];
  // F->D
  temp_qube[DOWN][0] = qube[FRONT][6];
  temp_qube[DOWN][3] = qube[FRONT][3];
  temp_qube[DOWN][6] = qube[FRONT][0];
  // D->B
  temp_qube[BACK][6] = qube[DOWN][0];
  temp_qube[BACK][3] = qube[DOWN][3];
  temp_qube[BACK][0] = qube[DOWN][6];
  // B->U
  temp_qube[UP][6] = qube[BACK][6];
  temp_qube[UP][3] = qube[BACK][3];
  temp_qube[UP][0] = qube[BACK][0];

  qube = temp_qube;
}
void TurnF()
{
  vector<vector<char>> temp_qube = qube;

  // U->R
  temp_qube[RIGHT][8] = qube[UP][8];
  temp_qube[RIGHT][7] = qube[UP][7];
  temp_qube[RIGHT][6] = qube[UP][6];
  // R->D
  temp_qube[DOWN][6] = qube[RIGHT][8];
  temp_qube[DOWN][7] = qube[RIGHT][7];
  temp_qube[DOWN][8] = qube[RIGHT][6];
  // D->L
  temp_qube[LEFT][8] = qube[DOWN][6];
  temp_qube[LEFT][7] = qube[DOWN][7];
  temp_qube[LEFT][6] = qube[DOWN][8];
  // L->U
  temp_qube[UP][8] = qube[LEFT][8];
  temp_qube[UP][7] = qube[LEFT][7];
  temp_qube[UP][6] = qube[LEFT][6];

  qube = temp_qube;
}
void TurnB()
{
  vector<vector<char>> temp_qube = qube;
  // U->L
  temp_qube[LEFT][0] = qube[UP][0];
  temp_qube[LEFT][1] = qube[UP][1];
  temp_qube[LEFT][2] = qube[UP][2];
  // L->D
  temp_qube[DOWN][2] = qube[LEFT][0];
  temp_qube[DOWN][1] = qube[LEFT][1];
  temp_qube[DOWN][0] = qube[LEFT][2];
  // D->R
  temp_qube[RIGHT][0] = qube[DOWN][2];
  temp_qube[RIGHT][1] = qube[DOWN][1];
  temp_qube[RIGHT][2] = qube[DOWN][0];
  // R->U
  temp_qube[UP][0] = qube[RIGHT][0];
  temp_qube[UP][1] = qube[RIGHT][1];
  temp_qube[UP][2] = qube[RIGHT][2];

  qube = temp_qube;
}

// 0 : U, 1 : F, 2 : L, 3 : R, 4 : B, 5 : D
int SurfaceToInt(char s)
{
  if (s == 'U')
    return UP;
  if (s == 'F')
    return FRONT;
  if (s == 'L')
    return LEFT;
  if (s == 'R')
    return RIGHT;
  if (s == 'B')
    return BACK;
  if (s == 'D')
    return DOWN;
}

void Turn(string cmd)
{
  char sur = cmd[0];
  char dir = cmd[1];

  int sur_ = SurfaceToInt(sur);

  TurnTargetSurface(sur_, dir);

  switch (sur_)
  {
  case UP:
    TurnU();
    if (dir == '-')
    {
      TurnU();
      TurnU();
    }
    break;
  case DOWN:
    TurnD();
    if (dir == '-')
    {
      TurnD();
      TurnD();
    }
    break;
  case FRONT:
    TurnF();
    if (dir == '-')
    {
      TurnF();
      TurnF();
    }
    break;
  case BACK:
    TurnB();
    if (dir == '-')
    {
      TurnB();
      TurnB();
    }
    break;
  case LEFT:
    TurnL();
    if (dir == '-')
    {
      TurnL();
      TurnL();
    }
    break;
  case RIGHT:
    TurnR();
    if (dir == '-')
    {
      TurnR();
      TurnR();
    }
    break;
  default:
    break;
  }
}

int tc;
int n;
vector<string> cmds;

// 0 : U, 1 : F, 2 : L, 3 : R, 4 : B, 5 : D
void init()
{
  qube.clear();
  qube.push_back(surface('w'));
  qube.push_back(surface('r'));
  qube.push_back(surface('g'));
  qube.push_back(surface('b'));
  qube.push_back(surface('o'));
  qube.push_back(surface('y'));

  cin >> n;
  cmds.clear();
  for (int i = 0; i < n; i++)
  {
    string cmd;
    cin >> cmd;
    cmds.push_back(cmd);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> tc;

  for (int i = 0; i < tc; i++)
  {
    init();

    for (int j = 0; j < n; j++)
    {
      Turn(cmds[j]);
    }

    cout << qube[UP][0] << qube[UP][1] << qube[UP][2] << endl;
    cout << qube[UP][3] << qube[UP][4] << qube[UP][5] << endl;
    cout << qube[UP][6] << qube[UP][7] << qube[UP][8] << endl;
  }
  return 0;
}