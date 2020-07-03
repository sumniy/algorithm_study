#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 직선이동일 때는 100원
// 코너일 때는 600원의 비용이 든다.

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int costs[25][25];

void BFS(vector<vector<int>>& board, int y, int x, int dir, int cost)
{
    int size = board.size();
    if(y < 0 || y >= size || x < 0 || x >= size || board[y][x] == 1)
    {
        return;
    }
    if(costs[y][x] >= cost)
    {
        costs[y][x] = cost;
    }
    else return;
    if(y == size-1 && x == size -1)
    {
        return;
    }
    
    for(int d=0;d<4;d++)
    {
        int next_y = y + dy[d];
        int next_x = x + dx[d];
        
        if(abs(dir - d) % 2 == 0)
        {
            BFS(board, next_y, next_x, d, cost + 100);
        }
        else
        {
            BFS(board, next_y, next_x, d, cost + 600);
        }
    }
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            costs[i][j] = 100000000;
        }
    }
    
    BFS(board, 0, 0, 1, 0);
    BFS(board, 0, 0, 2, 0);
    
    answer = costs[size-1][size-1];
    return answer;
}