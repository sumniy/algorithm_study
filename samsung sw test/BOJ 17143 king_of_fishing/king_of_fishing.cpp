#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Shark
{
public:
    int row;
    int col;
    int speed;
    int dir;
    int size;
    int Row;
    int Col;
    Shark()
    {
    }
    Shark(int r, int c, int s, int d, int z, int R, int C)
    {
        row = r;
        col = c;
        dir = d;
        size = z;
        Row = R;
        Col = C;
        if (dir == 1 || dir == 2)
        {
            speed = s % (2 * R - 2);
        }
        else
        {
            speed = s % (2 * C - 2);
        }
    }
    void ChangeDir()
    {
        if (row == 0 && dir == 1)
            dir = 2;
        else if (row == (Row - 1) && dir == 2)
            dir = 1;
        else if (col == 0 && dir == 4)
            dir = 3;
        else if (col == (Col - 1) && dir == 4)
            dir = 4;
    }
    void Move()
    {
        ChangeDir();
        int remain;
        int now;
        int max;
        int to_move;
        bool is_turn;

        if (dir == 1 || dir == 2)
        {
            now = row;
            max = Row - 1;
            if (dir == 1)
                remain = row;
            else
                remain = max - now;
        }
        else
        {
            now = col;
            max = Col - 1;
            if (dir == 4)
                remain = col;
            else
                remain = max - now;
        }

        if (speed <= remain)
        {
            to_move = speed;
            is_turn = false;

            switch (dir)
            {
            case 1:
                row -= to_move;
                break;
            case 2:
                row += to_move;
                break;
            case 3:
                col += to_move;
                break;
            case 4:
                col -= to_move;
                break;
            default:
                break;
            }
        }
        else if (speed <= remain + max)
        {
            to_move = speed - remain;
            is_turn = true;

            switch (dir)
            {
            case 1:
                row = to_move;
                break;
            case 2:
                row = max - to_move;
                break;
            case 3:
                col = max - to_move;
                break;
            case 4:
                col = to_move;
                break;
            default:
                break;
            }
        }
        else
        {
            to_move = (2 * max - speed) * (-1);
            is_turn = false;

            switch (dir)
            {
            case 1:
                row -= to_move;
                break;
            case 2:
                row += to_move;
                break;
            case 3:
                col += to_move;
                break;
            case 4:
                col -= to_move;
                break;
            default:
                break;
            }
        }

        if (is_turn)
        {
            switch (dir)
            {
            case 1:
                dir = 2;
                break;
            case 2:
                dir = 1;
                break;
            case 3:
                dir = 4;
                break;
            case 4:
                dir = 3;
                break;
            default:
                break;
            }
        }
    }
};

bool cmp(const Shark &a, const Shark &b)
{
    return a.size > b.size; // 내림차순 ,  < 를 사용하면 오름차순
}

vector<Shark> sharks;

int main()
{
    ifstream input("input.txt");

    int answer = 0;

    int R;
    int C;
    int M;

    // input >> R >> C >> M;
    cin >> R >> C >> M;

    if(M == 0)
    {
        cout<<answer<<endl;
        return 0;
    }
    vector<Shark>::iterator ptr;

    int r, c, s, d, z;
    vector<vector<int>> grid(R, vector<int>(C, 0));

    for (int i = 0; i < M; i++)
    {
        // input >> r >> c >> s >> d >> z;
        cin >> r >> c >> s >> d >> z;
        r--;
        c--;

        if (d == 1 || d == 2)
            s = s % (2 * R - 2);
        else
            s = s % (2 * C - 2);

        Shark temp(r, c, s, d, z, R, C);
        sharks.push_back(temp);

        grid[r][c] = z;
    }
    sort(sharks.begin(), sharks.end(), cmp);

    for (int i = 0; i < C; i++) // 1. 낚시왕 이동
    {
        // 2. 상어 잡기
        for (int j = 0; j < R; j++)
        {
            if (grid[j][i] != 0)
            {
                answer += grid[j][i]; // 잡은 상어 크기 합산

                // sharks 중에서 잡힌 상어 제거
                for (ptr = sharks.begin(); ptr != sharks.end(); ptr++)
                {
                    if ((*ptr).size == grid[j][i])
                    {
                        sharks.erase(ptr);
                        break;
                    }
                }
                grid[j][i] = 0; // 격자판에서 상어 삭제 <- 격자판을 초기화하기 때문에 필요없는 라인
                break;
            }
        }

        for (int o = 0; o < R; o++)
            for (int k = 0; k < C; k++)
                grid[o][k] = 0;

        // 3. 상어 이동
        for (ptr = sharks.begin(); ptr != sharks.end(); ++ptr)
        {
            (*ptr).Move();
            if ((*ptr).size > grid[(*ptr).row][(*ptr).col])
            {
                grid[(*ptr).row][(*ptr).col] = (*ptr).size;
            }
            else
            {
                sharks.erase(ptr--);  // *** erase를 사용하면 현재 반복자가 가리키는 원소가 삭제되므로, 반복자의 위치를 한 칸 앞으로 이동시켜주지 않으면 다음 원소를 건너뛰게 된다.
            }
        }
    }
    cout << answer << endl;

    return 0;
}
