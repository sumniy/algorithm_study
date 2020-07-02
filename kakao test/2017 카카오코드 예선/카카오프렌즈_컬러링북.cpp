#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// BFS of DFS

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int M,N;

int DFS(vector<vector<int>>& picture, vector<vector<bool>>& is_visited, int y, int x)
{
  int ret = 0;
  if(is_visited[y][x])
  {
    return 0;
  }
  else
  {
    is_visited[y][x] = true;
    ret = 1;
  }
  
  for(int dir=0;dir<4;dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(ny < 0 || ny >= M || nx <0 || nx >= N)
      continue;

    if(picture[ny][nx] == picture[y][x])
      ret += DFS(picture, is_visited, ny, nx);
  }

  return ret;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;

    vector<vector<bool>> is_visited(m, vector<bool>(n, false));
    


    for(int y=0;y<m;y++)
    {
      for(int x=0;x<n;x++)
      {
        int size_of_area = 0;
        if(picture[y][x] != 0)
          size_of_area = DFS(picture, is_visited, y, x);
        if(size_of_area == 0) continue;
        else
        {
          number_of_area++;
          if(size_of_area > max_size_of_one_area) max_size_of_one_area = size_of_area;
        }
        
      }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}