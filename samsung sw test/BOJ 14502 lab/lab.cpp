#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int ClcSafeArea(vector<vector<int>> &map, int N, int M)
{
  int safe_area=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
      if(map[i][j] == 0) safe_area++;
    }
  return safe_area;
}

void FillVirus(vector<vector<int>> &map, vector<vector<bool>> &visited, int N, int M, int i, int j)
{
  if(map[i][j] == 1) return;

  visited[i][j] = true;
  map[i][j] = 2;

  // 위쪽
  if(i > 0 && !visited[i-1][j])
    FillVirus(map, visited,N,M, i-1, j);

  // 오른쪽
  if(j<M-1 && !visited[i][j+1])
    FillVirus(map,visited,N,M,i,j+1);

  // 아래쪽
  if(i < N-1 && !visited[i+1][j])
    FillVirus(map,visited,N,M,i+1,j);
  
  // 왼쪽
  if(j > 0 && !visited[i][j-1])
    FillVirus(map,visited,N,M,i,j-1);
}

void VirusSpread(vector<vector<int>> &map, int N, int M)
{
  vector<vector<bool>> visited(N, vector<bool>(M,false));
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
      if(map[i][j] == 2 && !visited[i][j])
        FillVirus(map, visited, N, M, i, j);
    }
}

int FindSafeArea(vector<vector<int>> map, int N, int M, int a, int b, int c)
{
  int row, col;

  #define ROW(n) n/M
  #define COL(n) n%M

  if(map[ROW(a)][COL(a)] == 0)
    map[ROW(a)][COL(a)] = 1;
  else return 0;

  if(map[ROW(b)][COL(b)] == 0)
    map[ROW(b)][COL(b)] = 1;
  else return 0;

  if(map[ROW(c)][COL(c)] == 0)
    map[ROW(c)][COL(c)] = 1;
  else return 0;

  VirusSpread(map, N, M);
  return ClcSafeArea(map, N, M); 
}

int FindMaxSafeArea(vector<vector<int>> map, int N, int M)
{
  int size = N * M;
  vector<int> max;
  for (int i = 0; i < size - 2; i++)
    for (int j = i + 1; j < size - 1; j++)
      for (int k = j + 1; k < size; k++)
      {
        max.push_back(FindSafeArea(map, N, M, i, j, k));
      }
  sort(max.begin(), max.end());
  return max[max.size()-1];
}

int main()
{
  ifstream inStream("input.txt");

  int answer = 0;
  // 지도의 세로 크기 N, 가로 크기 M
  int N, M;

  inStream >> N >> M;
  vector<vector<int>> map(N, vector<int>(M, 0));
  int input;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      inStream >> input;
      map[i][j] = input;
    }
  answer = FindMaxSafeArea(map, N, M);
  cout<<answer<<"\n";
  return 0;
}