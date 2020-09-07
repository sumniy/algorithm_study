#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define endl "\n"

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int y, int x, int N, vector<string> &board, vector<vector<bool>> &visit)
{
  visit[y][x] = true;
  int ret = 1;

  for (int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == '0' ||visit[ny][nx])
      continue;

    ret += dfs(ny, nx, N, board, visit);
  }

  return ret;
}

int main()
{
  freopen("2667_input.txt", "r", stdin);
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<string> board;
  vector<vector<bool>> visit(N, vector<bool>(N, false));

  for (int i = 0; i < N; i++)
  {
    string input;
    cin >> input;
    board.push_back(input);
  }

  vector<int> answer;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == '1' && visit[i][j] == false)
      {
        int temp = dfs(i, j, N, board, visit);
        answer.push_back(temp);
      }
    }
  }

  sort(answer.begin(), answer.end());

  cout<<answer.size()<<endl;

  for (auto a : answer)
  {
    cout << a << endl;
  }

  return 0;
}