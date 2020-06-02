#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define endl "\n"

int answer;
vector<int> dices;

// key : 칸, value : 다음 이동할 칸의 key
int map[40];
// 각 칸의 값을 저장
int score[40];
// 말이 있는지 없는 지 확인
bool check[40];
// 각 말의 위치를 저장
int horse[4];
// 회전하는 칸에서 출발할 시 방향을 정해주는 배열
int turn[40];

void dfs(int index, int total)
{
    if (index >= 10)
    {
        if (answer < total)
        {
            answer = total;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dice = dices[index];
        int prev = horse[i];
        int next = prev;

        if (turn[next] > 0)
        {
            next = turn[next];
            dice-=1;
        }

        while (dice--)
        {
            next = map[next];
        }

        if (next != 21 && check[next] == true)
            continue;

        
        check[prev] = false;
        check[next] = true;
        horse[i] = next;
        
        dfs(index + 1, total + score[next]);

        horse[i] = prev;
        check[next] = false;
        check[prev] = true;
        
        
    }
}

void Init()
{
    answer = 0;

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 10; i++)
    {
        int temp;
        cin >> temp;
        dices.push_back(temp);
    }

    for (int i = 0; i < 30; i++)
        map[i] = i + 1;
    map[21] = 21;
    map[30] = 25;
    map[31] = 32;
    map[32] = 25;
    map[27] = 20;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;
    turn[25] = 26;

    for (int i = 0; i < 21; i++)
    {
        score[i] = i * 2;
    }
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;
}

int main()
{
    Init();
    dfs(0, 0);
    cout << answer << endl;
    return 0;
}