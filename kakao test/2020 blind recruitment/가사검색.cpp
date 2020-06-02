#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 트라이 자료구조에 words를 입력
// 쿼리 마다 find 함수를 통해 몇 개의 단어가 해당되는지 구함
// find 함수에서 쿼리를 통해 트라이를 따라갈 때
// 쿼리의 문자가  '?'라면 모든 존재하는 포인터를 따라 함수를 또 실행
// 그러기 위해서는 입력값에 각 문자와 그 부분에 해당하는 트라이를 가르키는 포인터를 같이 입력해주어야함

#define TRIESIZE 26

class Trie
{
public:
    Trie *nextnode[TRIESIZE];
    bool finish;
    bool next;

    Trie()
    {
        for (int i = 0; i < TRIESIZE; i++)
        {
            nextnode[i] = nullptr;
        }
        finish = false;
        next = false;
    }

    ~Trie()
    {
        for (int i = 0; i < TRIESIZE; i++)
        {
            delete (nextnode[i]);
        }
    }

    void insert(const char *c)
    {
        if (*c == '\0')
        {
            finish = true;
            return;
        }

        int index = *c - 'a';
        if (nextnode[index] == nullptr)
        {
            nextnode[index] = new Trie;
        }
        next = true;

        nextnode[index]->insert(c + 1);
    }

    int find(const char *c)
    {
        int ret = 0;

        if (next == false)
            return 0;

        if (*c == '\0')
        {
            if (finish == true)
                return 1;
            else
                return 0;
        }

        if (*c == '?')
        {
            for (int i = 0; i < TRIESIZE; i++)
            {
                if (nextnode[i] != nullptr)
                {
                    ret += nextnode[i]->find(c + 1);
                }
            }
            return ret;
        }
        else
        {
            int index = *c - 'a';
            if (nextnode[index] == nullptr)
            {
                return 0;
            }
            return ret + nextnode[index]->find(c + 1);
        }
    }
};

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    Trie trie;
    for (int i = 0; i < words.size(); i++)
    {
        const char ptr = words[i].c_str();
        trie.insert(ptr);
    }

    const char *p = words[0][0];
    while (*p != '\0')
    {
        cout << p;
        p++;
    }
    cout << endl;

    int cnt;
    for (int i = 0; i < queries.size(); i++)
    {
        const char *ptr = queries[i].c_str();
        cnt = trie.find(ptr);
        answer.push_back(cnt);
    }

    return answer;
}