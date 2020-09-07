#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
#define endl "\n"

vector<int> answer;

int selectMinVertex(vector<int>& v, vector<bool>& visit) {
  int min = 1001;
  for(auto next : v) {
    if(next < min && visit[next] == false) {
      min = next;
    }
  }
  return min;
}

void bfs(int start, vector<vector<int>>& adj ,vector<bool>& visit) {
  queue<vector<int>> que;
  queue<int> number_que;

  que.push(adj[start]);
  number_que.push(start);

  while(!que.empty()) {
    vector<int> curr = que.front();
    int curr_vertex = number_que.front();

    visit[curr_vertex] = true;
    answer.push_back(curr_vertex);

    que.pop();
    number_que.pop();

    sort(curr.begin(), curr.end());

    for(auto vertex : curr) {
      if(visit[vertex] == false) {
        que.push(adj[vertex]);
        number_que.push(vertex);
        visit[vertex] = true;
      }
    }
  }
}

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visit) {
  


  visit[start] = true;
  answer.push_back(start);

  vector<int> curr = adj[start];
  sort(curr.begin(), curr.end());

  for(auto next : curr) {
    if(visit[next] == false) {
      dfs(next, adj, visit);
    }
  }
}


int main()
{
  freopen("1260_input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, V;
  cin >> N >> M >> V;

  vector<vector<int>> adj(1001);
  vector<bool> visit(1001, false);

  for(int i=0;i<M;i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  answer.clear();
  dfs(V, adj, visit);
  for(auto v : answer) {
    cout<< v <<" ";
  }
  cout<<endl;

  for(int i=0;i<1001;i++) {
    visit[i] = false;
  }

  answer.clear();
  bfs(V, adj, visit);
  for(auto v : answer) {
    cout<< v <<" ";
  }
  cout<<endl;


  return 0;
}