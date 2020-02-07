#include <cstdio>
#include <string.h>
// #include <fstream>

using namespace std;

int N, M, x, y, K;
int map[20][20];
int move[1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

class Dice
{
public:
    int state[7];
    int floor;
    int surface;

    Dice()
    {
        memset(state, 0, sizeof(state));
        floor = 6;
        surface = 1;
    }

    void ChangeDice(int dir)
    {
        int temp[7];
        for(int i=0;i<7;i++)
            temp[i] = state[i];
        
        if(dir == 1)
        {
            state[1] = temp[4]; state[3] = temp[1];
            state[4] = temp[6]; state[6] = temp[3];
        }
        else if(dir ==2)
        {
            state[1] = temp[3]; state[3] = temp[6];
            state[4] = temp[1]; state[6] = temp[4];
        }
        else if(dir ==3)
        {
            state[1] = temp[5]; state[2] = temp[1];
            state[5] = temp[6]; state[6] = temp[2];
        }
        else if(dir==4)
        {
            state[1] = temp[2]; state[2] = temp[6];
            state[5] = temp[1]; state[6] = temp[5];
        }

    }

    void roll(int dir)
    {
        dir-=1;
        // map 바깥으로 나가는 명령 if로 확인
        x += dx[dir];
        y += dy[dir];

        if(x < 0 || x >= N || y < 0 || y >= M)
        {
            x -= dx[dir];
            y -= dy[dir];
            return;
        } 
        dir+=1;

        ChangeDice(dir);

        if (map[x][y] == 0)
            map[x][y] = state[6];
        else
        {
            state[6] = map[x][y];
            map[x][y] = 0;
        }

        print();
    }

    void print()
    {
        printf("%d\n", state[1]);
    }
};

int main() {
    Dice dice;

    // ifstream input("input.txt");

    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    // input>>N>>M>>x>>y>>K;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d", &map[i][j]);
            // input>>map[i][j];
    
    int dir;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &dir);
        // input>>dir;
        dice.roll(dir);
    }
    return 0;
}