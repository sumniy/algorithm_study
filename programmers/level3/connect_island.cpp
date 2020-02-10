#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int parent[101];

int GetParent(int parent[], int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    return parent[a] = GetParent(parent, parent[a]);
}

void UnionParent(int parent[], int a, int b)
{
    int aParent = GetParent(parent, a);
    int bParent = GetParent(parent, b);
    
    if(aParent < bParent) parent[bParent] = aParent;
    else parent[aParent] = bParent;
}

int FindParent(int parent[], int a, int b)
{
    int aParent = GetParent(parent, a);
    int bParent = GetParent(parent, b);
    
    if(aParent == bParent)
        return 1;
    else return 0;
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0;i<n;i++)
        parent[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);
    
    int size = costs.size();
    int linked_edges = 0;
    
    
    for(int i=0;i<size;i++)
    {
        // 사이클을 생성하지 않는다면 
        if(!FindParent(parent, costs[i][0], costs[i][1]))
        {
            answer += costs[i][2];
            UnionParent(parent, costs[i][0], costs[i][1]);
            linked_edges += 1;
            if(linked_edges == n-1) return answer;
        }
    }
    
    return answer;
}