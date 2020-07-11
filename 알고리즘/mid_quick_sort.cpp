#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void QuickSort(vector<int>& data, int start, int end)
{
  if(start >= end)
  {
    return;
  }

  int mid = (start + end)/2;
  int pivot = data[mid];
  swap(data[start], data[mid]);

  int i = start + 1, j = end;
  int temp;

  while(i <= j)
  {
    while(i <= end && data[i] >= pivot)
    {
      ++i;
    }
    while(j > start && data[j] <= pivot)
    {
      --j;
    }

    if(i > j)
    {
      swap(data[start], data[j]);
    }
    else
    {
      swap(data[i], data[j]);
    }
  }
  
  QuickSort(data, start, j-1);
  QuickSort(data, j+1, end);
}


int main()
{
  vector<int> array = {1, 3, 6, 5, 4, 7, 8, 9, 2, 10};

  for(auto i : array)
    cout<<i<<" ";
  cout<<endl;

  QuickSort(array, 0, array.size()-1);

  for(auto i : array)
    cout<<i<<" ";
  cout<<endl;
}