#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> MakeSet(vector<int> array)
{
  vector<int> set;
  for(int i=0;i<array.size();i++)
  {
    int j;
    for(j=0;j<set.size();j++)
    {
      if(set[j] == array[i]) 
      {
        break;
      }
    }
    if(j==set.size()) set.push_back(array[i]);
  } 
  sort(set.begin(), set.end());
  return set;
}

vector<int> Sum(vector<int> setA, vector<int> setB)
{
  vector<int> sum;
  int indexA = 0, indexB = 0;
  int A, B;
  int sizeA = setA.size(), sizeB = setB.size();
  while(indexA < sizeA && indexB < sizeB)
  {
    A = setA[indexA];
    B = setB[indexB];

    if(A == B)
    {
      sum.push_back(A);
      indexA++; 
      indexB++;
      continue;
    }
    else if(A > B)
    {
      indexB++;
      continue;
    }
    else if(A < B)
    {
      indexA++;
      continue;
    }
  }
}