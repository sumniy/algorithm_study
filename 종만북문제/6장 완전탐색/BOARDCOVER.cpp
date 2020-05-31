#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

// 테스트 케이스 C
// 각 테스트 케이스에 높이(행) H, 너비(열) W가 주어진다. (1<=H,W<=20)
// H 줄에 W 글자로 게임판의 모양이 주어진다. "#" 은 검은 칸, "." 는 흰 칸을 나타냄

// 0,0 칸 부터 시작하여 흰 칸이 나타나면, 그 칸을 덮을 수 있는 모든 방법을 찾고
// 각 방법을 선택한 후 다음 단계로 넘어간다.

// ㄴ 블럭은 4가지 모양으로 회전이 가능함.
// ㄴ 을 0으로 부터 시작해서 90도 회전하면서 3 까지 정한다.

// 0,0 부터 오른쪽으로 한 칸씩 이동하면서 블록을 놓을 수 있는 지 검사하도록 순서를 강제하는데,
// x == W 가 될 때 다음 행으로 이동하게 만들어 주었다.

// 실수한 점 : 이렇게 순서를 강제했으니, 해당 순서 이전 칸은 모두 채워져 있다고 가정을 하고 진행해야 하는데
// 블록의 패턴 중 3번 째 모양을, 해당 순서 이전 칸을 침범하는 모양으로 잡아서 제대로 블록을 놓지 못하게 되어
// 답을 구하지 못했다. 블록의 패턴만 변경하니 답이 구해짐.

typedef pair<int,int> pii;

pii block_shape[4][3] = {
  {{0,0}, {1,0}, {1,1}},
  {{0,0}, {0,1}, {1,0}},
  {{0,0}, {0,1}, {1,1}},
  {{0,0}, {1,0}, {1,-1}}
};

bool CanCover(vector<vector<char>>& board, int H, int W, int y, int x)
{
  if(y < 0 || y >= H || x < 0 || x>= W) return false;
  if(board[y][x] == '#') return false;
  return true;
}

int CoverBoard(vector<vector<char>>& board,int H, int W, int y, int x,int remain_white)
{
  if(x == W)
  {
    y++; x=0;
    if(y==H) return 0;
  }
  if(remain_white == 0)
  {
    return 1;
  }

  int ret = 0;

  if(board[y][x] == '#')
  {
    ret += CoverBoard(board, H, W, y, x+1, remain_white);
    return ret;
  }

  for(int shape = 0;shape<4;++shape)
  {
    pii nyx1 = block_shape[shape][1];
    pii nyx2 = block_shape[shape][2];

    int ny1 = y + nyx1.first;
    int nx1 = x + nyx1.second;
    int ny2 = y + nyx2.first;
    int nx2 = x + nyx2.second;

    if(CanCover(board, H, W, ny1, nx1) && CanCover(board, H, W, ny2, nx2))
    {
      board[y][x] = '#';
      board[ny1][nx1] = '#';
      board[ny2][nx2] = '#';
      ret += CoverBoard(board, H, W, y, x + 1, remain_white - 3);
      board[y][x] = '.';
      board[ny1][nx1] = '.';
      board[ny2][nx2] = '.';
    }

  }
  return ret;
}


int main() 
{
  ifstream input("BOARDCOVER_input.txt");
  int C;
  input>>C;
  for(int tc = 0;tc<C;++tc)
  {
    int H, W;
    input>>H>>W;

    vector<vector<char>> board(H, vector<char>(W));

    int remain_white = 0;
    for(int i=0;i<H;++i)
      for(int j=0;j<W;j++)
      {
        input>>board[i][j];
        if(board[i][j] == '.') remain_white++;
      }
      
    int answer = CoverBoard(board, H, W, 0, 0, remain_white);
    cout<<answer<<endl;
  }
  return 0;
}