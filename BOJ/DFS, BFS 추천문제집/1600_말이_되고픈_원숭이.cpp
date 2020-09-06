#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
#define endl "\n"

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int min_cost = 40000;

bool is_visited[200][200][31];
vector<vector<int>> costs(200, vector<int>(200, 40000));


// void dfs(int y, int x, int dest_y, int dest_x, vector<vector<int>>& board, int k, int cost) {
//   if(y == dest_y && x == dest_x) {
//     if(min_cost > cost) min_cost = cost;
//     return;
//   }

//   is_visited[y][x] = true;
//   costs[y][x] = cost;

//   if(k > 0) {
//     for(int dir = 0; dir<8; ++dir) {
//       int next_y = y + hy[dir];
//       int next_x = x + hx[dir];

//       if(next_y < 0 || next_y > dest_y || next_x < 0 || next_x > dest_x 
//       || is_visited[next_y][next_x] 
//       || board[next_y][next_x] == 1
//       || costs[next_y][next_x] < cost + 1 ) continue;

//       dfs(next_y, next_x, dest_y, dest_x, board, k - 1, cost + 1);
//     }
//   }

//   for(int dir = 0; dir<4; ++dir) {
//       int next_y = y + dy[dir];
//       int next_x = x + dx[dir];

//       if(next_y < 0 || next_y > dest_y || next_x < 0 || next_x > dest_x 
//       || is_visited[next_y][next_x] 
//       || board[next_y][next_x] == 1
//       || costs[next_y][next_x] < cost + 1 ) continue;

//       dfs(next_y, next_x, dest_y, dest_x, board, k, cost + 1);
//   }

//   is_visited[y][x] = false;
// }

queue<pair<int, int>> que; 
queue<int> cost_que;
queue<int> k_que;

void bfs(int dest_y, int dest_x, vector<vector<int>>& board, int k) {


  int y = 0;
  int x = 0;
  int cost = 0;
  int k_ = k;

  que.push({y, x});
  cost_que.push(0);
  k_que.push(k_);

  is_visited[0][0][0] = true;

  while(!que.empty()) {
    pair<int, int> curr = que.front();
    y = curr.first;
    x = curr.second;
    que.pop();

    cost = cost_que.front();
    cost_que.pop(); 

    k_ = k_que.front();
    k_que.pop();

    if(y == dest_y && x == dest_x) {
      if(min_cost > cost) min_cost = cost;
      continue;
    }

    // is_visited[y][x] = true;
    // costs[y][x] = cost;

    if(k_ > 0) {
      for(int dir = 0; dir<8; ++dir) {
      int next_y = y + hy[dir];
      int next_x = x + hx[dir];

      if(next_y < 0 || next_y > dest_y || next_x < 0 || next_x > dest_x 
      || is_visited[next_y][next_x][k_-1]
      || board[next_y][next_x] == 1) continue;

      is_visited[next_y][next_x][k_-1] = true;
      que.push({next_y, next_x});
      cost_que.push(cost+1);
      k_que.push(k_-1);
      }
    }

    for(int dir = 0; dir<4; ++dir) {
      int next_y = y + dy[dir];
      int next_x = x + dx[dir];

      if(next_y < 0 || next_y > dest_y || next_x < 0 || next_x > dest_x 
      || is_visited[next_y][next_x][k_]
      || board[next_y][next_x] == 1) continue;

      is_visited[next_y][next_x][k_] = true;
      que.push({next_y, next_x});
      cost_que.push(cost+1);
      k_que.push(k_);
    }
  }
}

int main()
{
  freopen("1600_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int K;
  cin >> K;

  int W, H;
  cin >> W >> H;

  vector<vector<int>> board(H, vector<int>(W, 0));

  for(int i=0;i<H;i++) {
    for(int j=0;j<W;j++) {
      cin >> board[i][j];
    }
  }

  // dfs(0, 0, H-1, W-1, board, K, 0);
  bfs(H-1, W-1, board, K);
  
  if(min_cost == 40000) cout<<-1<<endl;
  else cout<<min_cost<<endl;

  return 0;
}