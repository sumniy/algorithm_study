#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> priority;
vector<int> search_after;
vector<bool> visited;

void DFS(int room)
{
    if(visited[room] == true)
    {
        return;
    }
    
    // 현재 room의 우선순위 room이 방문하지 않은 상태라면 우선순위 room 다음에 실행되도록 해준다.
    if(visited[priority[room]] == false)
    {
        search_after[priority[room]] = room;
        return;
    }
    
    visited[room] = true;
    DFS(search_after[room]);
    for(auto& next_room : graph[room])
    {
        DFS(next_room);
    }
}

void init(int n)
{
    priority.assign(n, 0);
    search_after.assign(n, 0);
    visited.assign(n, false);
    visited[0] = true;
    graph.assign(n, vector<int>());
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    init(n);
    
    // 그래프 연결
    for(auto& edge : path)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    // 우선순위 할당
    for(auto p : order)
    {
        priority[p[1]] = p[0];
    }
    if(priority[0] > 0) return false;
    
    // 0을 기점으로 탐색 시작
    for(auto& next_room : graph[0])
    {
        DFS(next_room);
    }
    
    // 최소 한번 씩 방문하지 못 했으면 false
    for(int i=0;i<visited.size();i++)
    {
        if(visited[i] == false) return false;
    }
    
    return answer;
}