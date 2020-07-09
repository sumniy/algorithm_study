#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE_OF_INPUT = 7; // + MIN_SIZE
const int MIN_SIZE = 4;
const int MAX_ELEMENT = 10;

vector<int> MakeSet(vector<int> array)
{
  vector<int> set;
  if (array.empty())
    return set;

  sort(array.begin(), array.end());

  set.push_back(array[0]);
  int set_index = 0;

  for (int i = 1; i < array.size(); ++i)
  {
    if (set[set_index] != array[i])
    {
      set.push_back(array[i]);
      ++set_index;
    }
    else
    {
      continue;
    }
  }
  return set;
}

vector<int> Union(vector<int> setA, vector<int> setB)
{
  vector<int> union_set;
  int indexA = 0, indexB = 0;
  int A, B;
  int sizeA = setA.size(), sizeB = setB.size();
  while (indexA < sizeA && indexB < sizeB)
  {
    A = setA[indexA];
    B = setB[indexB];

    if (A == B)
    {
      union_set.push_back(A);
      indexA++;
      indexB++;
      continue;
    }
    else if (A > B)
    {
      union_set.push_back(B);
      indexB++;
      continue;
    }
    else if (A < B)
    {
      union_set.push_back(A);
      indexA++;
      continue;
    }
  }

  if (indexA == sizeA)
  {
    while (indexB < sizeB)
    {
      union_set.push_back(setB[indexB++]);
    }
  }
  else if (indexB == sizeB)
  {
    while (indexA < sizeA)
    {
      union_set.push_back(setA[indexA++]);
    }
  }
  return union_set;
}

vector<int> Difference(vector<int> base, vector<int> set)
{
  int set_index = 0;
  for (auto base_it = base.begin(); base_it != base.end(); ++base_it)
  {
    while (*base_it > set[set_index])
    {
      ++set_index;
    }

    if (*base_it == set[set_index])
    {
      base.erase(base_it--);
      ++set_index;
    }
    else if (*base_it < set[set_index])
    {
      continue;
    }
  }
  return base;
}

vector<int> Intersect(vector<int> setA, vector<int> setB)
{
  vector<int> intersect;
  int indexA = 0, indexB = 0;
  int A, B;
  int sizeA = setA.size(), sizeB = setB.size();
  while (indexA < sizeA && indexB < sizeB)
  {
    A = setA[indexA];
    B = setB[indexB];

    if (A == B)
    {
      intersect.push_back(A);
      indexA++;
      indexB++;
      continue;
    }
    else if (A > B)
    {
      indexB++;
      continue;
    }
    else if (A < B)
    {
      indexA++;
      continue;
    }
  }
  return intersect;
}

void print(vector<int> array, string name)
{
  int size = array.size();
  cout << name<<" : ";
  if(array.empty())
  {
    cout<<"empty"<<endl;
    return;
  }
  cout<<"{";
  for (int i = 0; i < size - 1; ++i)
    cout << array[i] << ", ";
  cout << array[size - 1] << "}" << endl;
}

int main()
{
  srand(time(NULL));

  vector<int> arrayA;
  vector<int> arrayB;
  int sizeA = rand() % MAX_SIZE_OF_INPUT + MIN_SIZE;
  int sizeB = rand() % MAX_SIZE_OF_INPUT + MIN_SIZE;

  for (int i = 0; i < sizeA; i++)
  {
    arrayA.push_back(rand() % MAX_ELEMENT);
  }

    for (int i = 0; i < sizeB; i++)
  {
    arrayB.push_back(rand() % MAX_ELEMENT);
  }

  vector<int> setA = MakeSet(arrayA);
  vector<int> setB = MakeSet(arrayB);

  vector<int> union_set = Union(setA, setB);
  vector<int> difference = Difference(setA, setB);
  vector<int> intersect = Intersect(setA, setB);

  print(arrayA, "arrayA");
  print(arrayB, "arrayB");
  print(setA, "setA");
  print(setB, "setB");
  print(union_set, "union_set");
  print(difference, "difference");
  print(intersect, "intersect");

  return 0;
}