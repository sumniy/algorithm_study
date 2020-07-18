#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 99999;

vector<int> dist_from_zero;
vector<bool> visited;

void BFS(vector<vector<int>>& graph, int start)
{
  queue<int> que;
  que.push(start);
  dist_from_zero[start] = 0;
  visited[start] = true;
  while(!que.empty())
  {
    start = que.front();
    que.pop();
    for(auto& node : graph[start])
    {
      if(visited[node] == false)
      {
        que.push(node);
        visited[node] = true;
        if(dist_from_zero[node] > dist_from_zero[start] + 1)
          dist_from_zero[node] = dist_from_zero[start] + 1;
      }
    }
  }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n);
    
    for(auto e : edge)
    {
        graph[e[0]-1].push_back(e[1]-1);
        graph[e[1]-1].push_back(e[0]-1);
    }
    
    dist_from_zero.assign(n, INF);
    visited.assign(n, false);
    
    BFS(graph, 0);
    
    int max_distance = *max_element(dist_from_zero.begin(), dist_from_zero.end());
    answer = count(dist_from_zero.begin(), dist_from_zero.end(), max_distance);
    
    return answer;
}