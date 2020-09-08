#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl "\n"

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool visit[101][101];
int board[101][101];

void init() {
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++) {
      visit[i][j] = false;
    }
  }
}

void dfs(int y, int x, int limit, int N) {
  visit[y][x] = true;
  for(int dir=0;dir<4;dir++) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(ny >= 0 && ny < N && nx >= 0 && nx < N && board[ny][nx] > limit && visit[ny][nx] == false) {
      dfs(ny, nx, limit, N);
    }
  }
}

int main()
{
  freopen("2468_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> board[i][j];
    }
  }

  init();
  int max_area_num = 1;

  for(int limit=1;limit<100;limit++) {
    int area_num = 0;
    // init();
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        if(visit[i][j] == false && board[i][j] > limit) {
          area_num++;
          dfs(i, j, limit, N);
        }
      }
    }
    if(area_num > max_area_num) max_area_num = area_num;
  }

  cout<<max_area_num<<endl;

  return 0;
}