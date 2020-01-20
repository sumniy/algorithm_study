#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> answer_candidate;


// dir[] 만들어서 어떤 dir이 와도 하나의 코드로 대응 가능하도록 만들기
void move(vector<string> &board, pair<int, int> target, int N, int M, int dir)
{
  for(int i=1;i<N;i++)
  {
    if(board[target.first-i][target.second] != '.')
    {
      board[target.first-i][target.second] = board[target.first][target.second];
      board[target.first][target.second] = '.';
    }
  }
}

    void DFS(vector<string> &board, pair<int, int> R, pair<int, int> B, int N, int M, int dir, int time)
{
  if (board[R.first][R.second] == 'O')
  {
    if (board[B.first][B.second] != 'O')
      answer_candidate.push_back(time);
    return;
  }

  if (board[R.first - 1][R.second] == '.')
  {
    move R
        move B
            DFS
  }
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
}