#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
#define endl "\n"

int n;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> dp;


class Point {
public:
  int value;
  int y;
  int x;
  Point(int v, int y2, int x2) {
    value = v;
    y = y2;
    x = x2;
  }
};

struct cmp {
  bool operator()(Point& a, Point& b) {
    return a.value > b.value;
  }
};

int getMaxCnt(vector<vector<int>> &board, priority_queue<Point, vector<Point>, cmp>& pq)
{
  int max_cnt = 0;

  while(!pq.empty()) {
    Point curr = pq.top();
    pq.pop();

    for(int dir=0;dir<4;dir++) {
      int ny = curr.y + dy[dir];
      int nx = curr.x + dx[dir];

      if(ny >= 0 && ny < n && nx >= 0 && nx < n && board[ny][nx] > curr.value) {
        if(dp[ny][nx] < dp[curr.y][curr.x] + 1) dp[ny][nx] = dp[curr.y][curr.x] + 1;
      }
    }

    if(dp[curr.y][curr.x] > max_cnt) max_cnt = dp[curr.y][curr.x];

  }

  return max_cnt;
}

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  priority_queue<Point, vector<Point>, cmp> pq;
  vector<vector<int>> board(n, vector<int>(n, 0));

  for(int y=0;y<n;y++) {
    for(int x=0;x<n;x++) {
      cin >> board[y][x];
      pq.push(Point(board[y][x], y, x));
    }
  }

  dp.assign(n, vector<int>(n, 1));

  cout << getMaxCnt(board, pq)<<endl;

  return 0;
}