#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAX 2147000000
#define endl "\n"

int Init(vector<int>& tree, vector<int>& array, int node, int start, int end)
{
  if(start == end) return tree[node] = array[start];
  return tree[node] = min(Init(tree, array, node*2, start, (start+end)/2), 
  Init(tree, array, node*2+1, (start+end)/2+1, end));
}

int FindMinValue(vector<int>& tree, int node, int start, int end, int left, int right)
{
  if(left > end || right < start) return MAX;
  if(left <= start && right >= end) return tree[node];
  return min(FindMinValue(tree, node*2, start, (start+end)/2, left, right),
  FindMinValue(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  int tree_size = (int) ceil(log2(N));
  tree_size = ( 1 << (tree_size+1));
  vector<int> array(N);
  vector<int> segment_tree(tree_size);

  for(int i=0;i<N;i++)
    cin>>array[i];

  Init(segment_tree, array, 1, 0, N-1);
  
  for(int i=0;i<M;i++)
  {
    int left, right;
    cin >> left >> right;
    cout<<FindMinValue(segment_tree, 1, 0, N-1, --left, --right)<<endl;
  }

  return 0;
}