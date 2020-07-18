#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void QuickSort(vector<int> &data, int start, int end)
{
  if (start >= end)
  {
    return;
  }

  int mid = (start + end) / 2;
  int pivot = data[mid];
  swap(data[start], data[mid]);

  int i = start + 1, j = end;
  int temp;

  while (i <= j)
  {
    while (i <= end && data[i] <= pivot)
    {
      ++i;
    }
    while (j > start && data[j] >= pivot)
    {
      --j;
    }

    if (i > j)
    {
      swap(data[start], data[j]);
    }
    else
    {
      swap(data[i], data[j]);
    }
  }

  QuickSort(data, start, j - 1);
  QuickSort(data, j + 1, end);
}

const int INPUT_SIZE = 10000;
const int MAX_ELEM = 999999;
#define endl "\n"

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> array;

  srand(11);

  for (int i = 0; i < INPUT_SIZE; i++)
  {
    array.push_back(rand() % MAX_ELEM);
  }

  for (auto i : array)
    cout << i << " ";
  cout << endl;

  QuickSort(array, 0, array.size() - 1);

  for (auto i : array)
    cout << i << " ";
  cout << endl;
}