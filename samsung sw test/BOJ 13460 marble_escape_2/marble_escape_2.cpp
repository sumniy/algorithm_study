#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> answer_candidate;

int dir_array[4][2] = {-1, 0,
                       0, 1,
                       +1, 0,
                       0, -1};

// dir[] 만들어서 어떤 dir이 와도 하나의 코드로 대응 가능하도록 만들기
void move(vector<string> &board, pair<int, int> target, int N, int M, int dir)
{
  int r, c;
  int r2, c2;
  for (int i = 1; i < 10; i++)
  {
    r = dir_array[dir][0] * i;
    c = dir_array[dir][1] * i;
    r2 = dir_array[dir][0] * (i - 1);
    c2 = dir_array[dir][1] * (i - 1);

    if (board[target.first + r][target.second + c] == 'O')
    {
      board[target.first][target.second] = '.';
      return;
    }
    else if (board[target.first + r][target.second + c] != '.')
    {
      char temp = board[target.first][target.second];
      board[target.first][target.second] = '.';
      board[target.first + r2][target.second + c2] = temp;
      return;
    }
  }
}

pair<int, int> FindMarble(vector<string> &board, char c, int N, int M)
{
  pair<int, int> point;
  point.first = 0;
  point.second = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      if (board[i][j] == c)
      {
        point.first = i;
        point.second = j;
      }
    }
  return point;
}

void DFS(vector<string> &board, pair<int, int> R, pair<int, int> B, int N, int M, int dir, int time)
{
  if (time > 10)
    return;

  if (R.first == 0 && R.second == 0)
  {
    if (B.first == 0 && B.second == 0)
    {
      return;
    }
    else
    {
      answer_candidate.push_back(time);
      return;
    }
  }
  else
  {
    if (B.first == 0 && B.second == 0)
    {
      return;
    }
  }

  int recent_dir = 0;
  if (dir == -1) recent_dir = -1;
  else if (dir == 0)
    recent_dir = 2;
  else if (dir == 1)
    recent_dir = 3;
  else if (dir == 2)
    recent_dir = 0;
  else if (dir == 3)
    recent_dir = 1;

  // board, R, B 처럼 다음 방향에도 똑같이 유지되는 것을 바뀌지 않도록 확실하게 확인해야하는데
  // R과 B 좌표가 계속 바뀌도록 코딩하여, 계속 틀린 결과를 나오게 함
  for (int i = 0; i < 4; i++)
  {
    if ((i != recent_dir && i != dir) && 
    (board[R.first + dir_array[i][0]][R.second + dir_array[i][1]] == '.' || board[R.first + dir_array[i][0]][R.second + dir_array[i][1]] == 'O'))
    {
      vector<string> temp(board);
      move(temp, R, N, M, i);
      move(temp, B, N, M, i);
      DFS(temp, FindMarble(temp, 'R', N, M), FindMarble(temp, 'B', N, M), N, M, i, time + 1);
    }
  }

  return;
}

int main()
{
  ifstream input("input.txt");

  int N, M;

  input >> N >> M;

  vector<string> board;
  string input_string;

  for (int i = 0; i < N; i++)
  {
    input >> input_string;
    board.push_back(input_string);
  }

  pair<int, int> R;
  pair<int, int> B;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      if (board[i][j] == 'R')
      {
        R.first = i;
        R.second = j;
      }
      else if (board[i][j] == 'B')
      {
        B.first = i;
        B.second = j;
      }
    }

  DFS(board, R, B, N, M, -1, 0);

  if (answer_candidate.size() == 0)
    cout << "-1" << endl;
  else
  {
    sort(answer_candidate.begin(), answer_candidate.end());
    if (answer_candidate[0] > 10)
      cout << "-1" << endl;
    else
      cout << answer_candidate[0];
  }

  return 0;
}