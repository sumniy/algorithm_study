#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int cnt;
    Node* next[26];
    Node()
    {
        cnt = 0;
        for(int i=0;i<26;i++)
        {
            next[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* alpabet[26];
    
    Trie()
    {
        for(int i=0;i<26;i++)
            alpabet[i] = nullptr;
    }

    void insert(string word)
    {
      auto it = word.begin();
      int index = *it - 97;

      if(alpabet[index] == nullptr)
      {
        alpabet[index] = new Node();
      }

      Node* curr = alpabet[index];
      curr->cnt += 1;
      ++it;

      while(it != word.end())
      {
        index = *it - 97;
        if(curr->next[index] == nullptr)
        {
          curr->next[index] = new Node();
        }
        curr = curr->next[index];
        curr->cnt += 1;
        ++it;
      }
    }

    int find(string word)
    {
      int ret = 0;
      auto it = word.begin();
      int index = *it - 97;
      Node* curr = alpabet[index];
      ++ret;
      ++it;

      while(it != word.end() && curr->cnt != 1)
      {
        index = *it - 97;
        ++ret;
        curr = curr->next[index];
        ++it;
      }
      return ret;
    }
    
};

int solution(vector<string> words) {
    int answer = 0;
    
    Trie words_trie;
    
    for(auto word : words)
    {
        words_trie.insert(word);
    }
    
    for(auto word : words)
    {
        answer += words_trie.find(word);
    }
    
    return answer;
}