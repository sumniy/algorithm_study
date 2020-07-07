#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE_OF_TABLE = 10;

class Node {
  string key;
  int value;
  Node *next;
};

class Map {
private:
  vector<*Node> hash_table;
public:
  void insert(string key, int value)
  {

  }
  void erase();
  void find();
  void size();
  void empty();
};

