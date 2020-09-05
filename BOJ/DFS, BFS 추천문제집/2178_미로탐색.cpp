#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;
#define endl "\n"

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int N, int M, vector<vector<int>>& board) {

  vector<vector<int>> cost(N, vector<int>(M, N*M));
  cost[0][0] = 1;
  queue<pair<int,int>> que;

  int y = 0;
  int x = 0;
  int ny = 0;
  int nx = 0;

  que.push({y, x});

  while(!que.empty()) {
    pair<int, int> curr = que.front();
    que.pop();

    y = curr.first;
    x = curr.second;

    for(int dir=0;dir<4;dir++) {
      ny = y + dy[dir];
      nx = x + dx[dir];

      if(ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] == 0) continue;

      if(cost[ny][nx] > cost[y][x] + 1) {
        cost[ny][nx] = cost[y][x] + 1; 
        que.push({ny, nx}); 
      }
    }
  }

  return cost[N-1][M-1];
}

int main()
{
  freopen("2178_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> board(N, vector<int>(M, 0));

  for(int i=0;i<N;i++) {
    string line;
    cin >> line;

    for(int j=0;j<M;j++) {
      board[i][j] = line[j] - '0';
    }
  }

  int answer = bfs(N, M, board);

  cout<<answer;

  return 0;
}