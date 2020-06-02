#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 2147483647
#define MIN -2147483648
#define endl "\n"

int InitMinTree(vector<int> &tree, vector<int> &array, int node, int start, int end)
{
    if (start == end) return tree[node] = array[start];
    return tree[node] = min(InitMinTree(tree, array, node*2, start, (start+end)/2), 
                            InitMinTree(tree, array, node*2+1, (start+end)/2 +1, end));
}

int InitMaxTree(vector<int> &tree, vector<int> &array, int node, int start, int end)
{
    if (start == end) return tree[node] = array[start];
    return tree[node] = max(InitMaxTree(tree, array, node*2, start, (start+end)/2), 
                            InitMaxTree(tree, array, node*2+1, (start+end)/2 +1, end));
}

int FindMin(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return MAX;
    if (left <= start && right >= end)
        return tree[node];
    
    return min(FindMin(tree, node*2, start, (start+end)/2, left, right),
              FindMin(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int FindMax(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return MIN;
    if (left <= start && right >= end)
        return tree[node];
    
    return max(FindMax(tree, node*2, start, (start+end)/2, left, right),
              FindMax(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int main()
{
    freopen("input.txt", "r" , stdin);
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int tree_size = ceil(log2(N));
    tree_size = (1 << (tree_size + 1));

    vector<int> array(N);
    vector<int> min_segment_tree(tree_size);
    vector<int> max_segment_tree(tree_size);

    for(int i=0;i<N;i++)
        cin>>array[i];

    InitMinTree(min_segment_tree, array, 1, 0, N-1);
    InitMaxTree(max_segment_tree, array, 1, 0, N-1);
    
    int left, right;
    for(int i=0;i<M;i++)
    {
        cin>>left>>right;
        left--; right--;
        cout<<FindMin(min_segment_tree, 1, 0, N-1, left, right)<<" "<<FindMax(max_segment_tree, 1, 0, N-1, left, right)<<endl;
    }

    return 0;
}