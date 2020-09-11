#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 트라이 자료구조에 words를 입력
// 쿼리 마다 find 함수를 통해 몇 개의 단어가 해당되는지 구함
// find 함수에서 쿼리를 통해 트라이를 따라갈 때
// 쿼리의 문자가  '?'라면 모든 존재하는 포인터를 따라 함수를 또 실행
// 그러기 위해서는 입력값에 각 문자와 그 부분에 해당하는 트라이를 가르키는 포인터를 같이 입력해주어야함

#define TRIESIZE 26

class Node
{
public:
    Node *next[TRIESIZE];
    int cnt;
    Node()
    {
        cnt = 0;
        for (int i = 0; i < TRIESIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

class Trie
{
public:
    Node *head;
    int word_cnt;

    void insert(string word)
    {
        word_cnt++;
        Node *curr = head;

        for (char c : word)
        {
            c = c - 'a';
            if (curr->next[c] == NULL)
            {
                Node *temp = new Node();
                curr->next[c] = temp;
            }
            curr = curr->next[c];
            curr->cnt++;
        }
    }

    int find(string query)
    {
        if(query[0] == '?') return word_cnt;
        Node *curr = head;

        int cnt = 0;
        for (char c : query)
        {
            if (c == '?')
                return cnt;
            c = c - 'a';
            if (curr->next[c] == NULL)
            {
                return 0;
            }
            curr = curr->next[c];
            cnt = curr->cnt;
        }
        return 0;
    }

    Trie()
    {
        Node *temp = new Node();
        head = temp;
        word_cnt = 0;
    }
};

Trie tries[10001];
Trie triesR[10001];

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    for (auto word : words)
    {
        int size = word.size();

        tries[size].insert(word);

        reverse(word.begin(), word.end());

        triesR[size].insert(word);
    }

    for (auto query : queries)
    {
        int size = query.size();
        if (query[0] == '?')
        {
            reverse(query.begin(), query.end());
            answer.push_back(triesR[size].find(query));
        }
        else
        {
            answer.push_back(tries[size].find(query));
        }
    }

    return answer;
}