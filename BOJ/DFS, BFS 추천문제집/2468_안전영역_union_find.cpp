#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define endl "\n"

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int board[101][101];
vector<int> parent(101*101+101, -1);

int cnt = 0;

int Find(int x) {
  if(parent[x] == x) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);

  if(a != b) {
    parent[b] = a;
    cnt--;
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

  int max_height = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> board[i][j];
      max_height = max(max_height, board[i][j]);
    }
  }

  int max_area_num = 1;

  for(int limit=max_height;limit>0;limit--) {
    for(int y=0;y<N;y++) {
      for(int x=0;x<N;x++) {
        if(board[y][x] > limit) {
          int pos = y * N + x;
          if(parent[pos] == -1) {
            parent[pos] = pos;
            cnt++;
          }
          for(int dir=0;dir<4;dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= N || parent[ny*N + nx] == -1) continue;
            
            Union(pos, ny*N + nx);
          }
        }
      }
    }
    max_area_num = max(max_area_num, cnt);
  }

  cout<<max_area_num<<endl;

  return 0;
}