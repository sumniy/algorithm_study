#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

#define endl "\n"

const int SIZE_OF_TABLE = 10;
const int HASH_VALUE = 401;
const int MAX_KEY_LENGTH = 16;
const int SIZE_OF_INPUT = 20;
const int MAX_VALUE_SIZE = 21700;
const int SIZE_OF_DELETE = 20;

class Bucket {
public:
  string key;
  int value;
  Bucket *next;
  Bucket()
  {
    next = nullptr;
  }
  Bucket(string k, int v)
  {
    key = k;
    value = v;
    next = nullptr;
  }
  ~Bucket()
  {
  }
};

class ChainingHashTable {
private:
  int num_of_elems;
  vector<Bucket*> hash_table;
public:
  ChainingHashTable()
  {
    num_of_elems = 0;
    for(int i=0;i<SIZE_OF_TABLE;i++)
    {
      hash_table.push_back(nullptr);
    }
    cout<<"SIZE_OF_TABLE is "<<hash_table.size()<<endl;
  }

  int hash(string key)
  {
    int hash = HASH_VALUE;
    auto key_it = key.begin();

    while(key_it != key.end())
    {
      hash = ((hash << 5) + (int)(*key_it)) % SIZE_OF_TABLE;
      ++key_it;
    }
    return hash;
  }

  void insert(string key, int value)
  {
    int key_index = hash(key);

    // Bucket *new_bucket = (Bucket *)malloc(sizeof(Bucket));
    // new Bucket 가 아닌 malloc으로 메모리를 할당했을 때 프로그램이 중간에 터지는 문제가 발생했다.
    // 아마도 Bucket의 변수 중 string이 포함되어 있어서 string의 길이에 따른 저장 용량의 차이 때문에 발생하는 것 같다. 나중에 자세히 알아보자
    Bucket *new_bucket = new Bucket(key, value);

    if(hash_table[key_index] == nullptr)
    {
      hash_table[key_index] = new_bucket;
    }
    else 
    {
      Bucket *curr = hash_table[key_index];

      while(curr->next != nullptr && curr->key != key)
      {
        curr = curr->next;
      }

      if(curr->key == key) 
      {
        curr->value = value;
        return;
      }
      else if(curr->next == nullptr)
      {
        curr->next = new_bucket;
      }
    }
    ++num_of_elems;
  }


// erase 호출 시 삭제가 정상적으로 이루어지지 않는다.
// insert 시 노드에 key와 value가 제대로 할당되지 않아서 터지는 문제 발생.
// Bucket 생성자에서 입력 매개변수와 멤버변수의 이름이 같아서 발생, 매개변수 이름 변경 -> 해결
// 다시 문제 발생, 지웠던 KEY를 다시 지울 때 프로그램 종료됨.
// 밑에 else 문에서 while(curr != nullptr && curr->key != key) 여기서 원래는
// while(curr->key != key && curr != nullptr) 이 순서로 했었는데 이거 때문에 문제가 발생했음
// curr가 nullptr일 때도 key에 접근해버리니까 이럴 때 터져버림,
// 조건문은 항상 문장의 순서를 신경쓰자
  bool erase(string key)
  {
    int key_index = hash(key);
    if(hash_table[key_index] == nullptr)
    {
      return false; 
    }
    else 
    {
      if(hash_table[key_index]->key == key)
      {
        Bucket *temp = hash_table[key_index];
        hash_table[key_index] = hash_table[key_index]->next;
        delete temp;
      }
      else
      {
        Bucket *curr = hash_table[key_index]->next;
        Bucket *pre = hash_table[key_index];
        while(curr != nullptr && curr->key != key)
        {
          pre = curr;
          curr = curr->next;
        }

        if(curr == nullptr)
        {
          return false;
        }
        else
        {
          pre->next = curr->next;
          delete curr;
        }
      }
    }
    --num_of_elems;
    return true;
  }


  bool find(string key)
  {
    int key_index = hash(key);

    Bucket *curr = hash_table[key_index];

    while(curr != nullptr)
    {
      if(curr->key == key) return true;
    }
  
    return false;
  }

  int size()
  {
    return num_of_elems;
  }

  bool empty()
  {
    if(num_of_elems == 0) return true;
    else return false;
  }
};

ChainingHashTable hash_table;

int main()
{
  vector<string> keys;
  vector<int> values;

  srand(time(nullptr));

  for(int i=0;i<SIZE_OF_INPUT;++i)
  {
    string key = "";
    int value = rand()%MAX_VALUE_SIZE;
    int key_length = rand() % MAX_KEY_LENGTH;

    if(key_length == 0) ++key_length;

    for(int key_index = 0;key_index<key_length;++key_index)
    {
      key += rand() % 26 + 97;
    }
    keys.push_back(key);
    values.push_back(value);

    cout<<"Generated KEY: "<<key<<", VALUE: "<<value<<endl;
  }

  cout<<endl;

  for(int i=0;i<SIZE_OF_INPUT;++i)
  {
    hash_table.insert(keys[i], values[i]);
    cout<<"Insert KEY : "<<keys[i]<<", VALUE : "<<values[i]<<endl;
  }

  cout<<endl<<"hash_table's size is "<<hash_table.size()<<endl<<endl;

  for(int i=0;i<SIZE_OF_DELETE;++i)
  {
    int random_index = rand() % SIZE_OF_INPUT;
    string delete_key = keys[random_index];

    if(hash_table.erase(delete_key))
      cout<<"Delete KEY: "<<delete_key<<endl;
    else 
      cout<<"cat't find KEY: "<<delete_key<<endl;
  }
  
  cout<<endl<<"hash_table's size is "<<hash_table.size()<<endl;


  return 0;
}