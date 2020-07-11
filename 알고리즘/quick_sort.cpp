#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& data, int start, int end)
{
  if( start >= end )
  {
    return;
  }

  // int pivot = data[(start+end)/2];
  // swap(data[start], data[(start+end)/2]);

  int pivot = data[start];
  int i = start + 1;
  int j = end;
  int temp;
  
  while(i <= j)
  {
    while(i <= end && data[i] <= pivot)
    {
      ++i;
    }
    while(j > start && data[j] >= pivot)
    {
      --j;
    }

    if( i > j)
    {
      temp = data[j];
      data[j] = pivot;
      data[start] = temp;
    }
    else if(i<=j)
    {
      temp = data[j];
      data[j] = data[i];
      data[i] = temp;
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