#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

char board[5][5];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool answer;

bool HasWord(int y, int x, string word)
{
  if (word[0] != board[y][x])
  {
    return false;
  }
  if (word.size() == 1)
  {
    answer = true;
    return true;
  }

  for (int i = 0; i < 8; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
      continue;

    if(HasWord(ny, nx, word.substr(1)))
      return true;
  }
}

int main()
{
  ifstream input("input.txt");

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> board[i][j];

  int y, x;
  cin >> y >> x;
  string word;
  cin >> word;

  HasWord(y, x, word);

  if(answer)
    cout<<"Target word is exist in board\n";
  else 
    cout<<"Target word is not exist in board\n";
}