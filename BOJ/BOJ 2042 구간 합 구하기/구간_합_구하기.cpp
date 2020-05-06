#include <vector>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

long long init(vector<long long> &tree, vector<long long> &array, int node, int start, int end)
{
  if (start == end)
    return tree[node] = array[start];
  else
  {
    return tree[node] = init(tree, array, node * 2, start, (start + end) / 2) +
                        init(tree, array, node * 2 + 1, (start + end) / 2 + 1, end);
  }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return 0;
  else if (left <= start && right >= end)
  {
    return tree[node];
  }
  return sum(tree, node * 2, start, (start + end) / 2, left, right) +
         sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
  if(index < start || index > end) return;
  tree[node] += diff;
  if(start != end) 
  {
    update(tree, node*2, start, (start+end)/2, index, diff);
    update(tree, node*2+1, (start+end)/2+1, end, index, diff);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  int N,M,K;
  cin >> N >> M >> K;

  int size = (int)ceil(log2(N));
  size = pow(2, size+1); 

  vector<long long> segment_tree(size);
  vector<long long> array(N);

  for(int i=0;i<N;i++)
  {
    cin>>array[i];
  }

  init(segment_tree, array, 1, 0, N-1);

  for(int i=0;i<M+K;i++)
  {
    int cmd;
    cin>>cmd;
    // update
    if(cmd==1)
    {
      int index;
      long long diff;
      cin>>index>>diff;
      diff = diff - array[--index];
      array[index] += diff;
      update(segment_tree, 1, 0, N-1, index, diff);
    }
    // sum
    else if(cmd == 2)
    {
      int left, right;
      cin>>left>>right;
      cout<<sum(segment_tree, 1, 0, N-1, --left, --right)<<endl;
    }
  }

  return 0;
}