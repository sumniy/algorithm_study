#include <vector>
#include <iostream>

using namespace std;

#define SIZE 10

vector<int> segment_tree(SIZE + 1, 0);
vector<int> target_array(SIZE, 0);

int init(vector<int> &tree, vector<int> &array, int node, int start, int end)
{
  if (start == end)
    return tree[node] = array[start];
  else
  {
    return tree[node] = init(tree, array, node * 2, start, (start + end) / 2) +
                        init(tree, array, node * 2 + 1, (start + end) / 2 + 1, end);
  }
}

int sum(vector<int> &tree, int node, int start, int end, int left, int right)
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

void update(vector<int>& tree, int node, int start, int end, int index, int diff)
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
  for (int i = 0; i < SIZE; i++)
  {
    target_array[i] = i;
  }

  init(segment_tree, target_array, 1, 0, SIZE-1);
  cout<<sum(segment_tree, 1, 0, SIZE-1, 0, 9)<<endl;

  update(segment_tree, 1, 0, SIZE-1, 3, 7);
  cout<<sum(segment_tree, 1, 0, SIZE-1, 0, 9)<<endl;

  return 0;
}