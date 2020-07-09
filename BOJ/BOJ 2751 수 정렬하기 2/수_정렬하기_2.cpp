#include<iostream>
#include<vector>

using namespace std;

#define endl "\n"

vector<int> MergeSort(vector<int> array, int begin, int end)
{
  if(array.size() <= 1)
  {
    return array;
  }
  vector<int> left(array.begin()+begin, array.begin()+(begin+end)/2+1);
  vector<int> right(array.begin()+(begin+end)/2 + 1, array.end());

  left = MergeSort(left, 0, left.size()-1);
  right = MergeSort(right, 0, right.size()-1);

  vector<int> ret;

  int left_size = left.size();
  int right_size = right.size();
  int left_index = 0, right_index = 0;

  while(left_index < left_size && right_index < right_size)
  {
    int left_elem = left[left_index];
    int right_elem = right[right_index];

    if(left_elem == right_elem)
    {
      ret.push_back(right_elem);
      ++right_index;
    }
    else if(left_elem > right_elem)
    {
      ret.push_back(right_elem);
      ++right_index;
    }
    else if(left_elem < right_elem)
    {
      ret.push_back(left_elem);
      ++left_index;
    }
  }

  if(left_index == left_size)
  {
    while(right_index < right_size)
    {
      ret.push_back(right[right_index++]);
    }
  }
  else if(right_index == right_size)
  {
    while(left_index < left_size)
    {
      ret.push_back(left[left_index++]);
    }
  }

  return ret;
}

vector<int> array;

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  for(int i=0;i<N;i++)
  {
    int temp;
    cin >> temp;
    array.push_back(temp);
  }

  vector<int> sorted_array = MergeSort(array, 0, array.size()-1);

  for(auto num : sorted_array)
  {
    cout<<num<<" ";
  }
  cout<<endl;

  return 0;
}