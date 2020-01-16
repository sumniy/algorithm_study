#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void DiffusionEachSpace(vector<vector<int>> &g, vector<vector<int>> &temp_g, int row, int col, int i, int j)
{
    int amonut_of_dust = temp_g[i][j] / 5;

    int enable_dir = 0;

    if (i > 0 && temp_g[i - 1][j] != -1)
    {
        enable_dir++;
        g[i - 1][j] += amonut_of_dust;
    }

    if (j < col - 1)
    {
        enable_dir++;
        g[i][j + 1] += amonut_of_dust;
    }

    if (i < row - 1 && temp_g[i + 1][j] != -1)
    {
        enable_dir++;
        g[i + 1][j] += amonut_of_dust;
    }

    if (j > 0 && temp_g[i][j - 1] != -1)
    {
        enable_dir++;
        g[i][j - 1] += amonut_of_dust;
    }

    g[i][j] -= amonut_of_dust * enable_dir;
}

void FineDustDiffusion(vector<vector<int>> &g, int row, int col)
{

    // vector<vector<int>> temp_grid(row, vector<int>(col,0));
    // temp_grid = g;

    vector<vector<int>> temp_grid(g);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (temp_grid[i][j] > 0)
                DiffusionEachSpace(g, temp_grid, row, col, i, j);
        }
    }
}

void ActivateAirCleaner(vector<vector<int>> &g, int row, int col, int pos)
{
    int R1 = pos;
    int R2 = pos + 1;

    // *** i의 범위에서 -- 일때와 ++ 일 때 조건식을 잘못대입해서 틀림

    // 공기청정기 위쪽 순환
    for (int i = R1 - 1; i >= 1; i--)
    {
        g[i][0] = g[i - 1][0];
    }

    for (int i = 0; i <= col - 2; i++)
    {
        g[0][i] = g[0][i + 1];
    }

    for (int i = 0; i <= R1 - 1; i++)
    {
        g[i][col - 1] = g[i + 1][col - 1];
    }

    for (int i = col - 1; i >= 1; i--)
    {
        g[R1][i] = g[R1][i - 1];
    }
    g[R1][1] = 0;

    // 공기청정기 아래쪽 순환
    for (int i = R2 + 1; i <= row - 2; i++)
    {
        g[i][0] = g[i + 1][0];
    }

    for (int i = 0; i <= col - 2; i++)
    {
        g[row - 1][i] = g[row - 1][i + 1];
    }

    for (int i = row - 1; i >= R2 + 1; i--)
    {
        g[i][col - 1] = g[i - 1][col - 1];
    }

    for (int i = col - 1; i >= 1; i--)
    {
        g[R2][i] = g[R2][i - 1];
    }
    g[R2][1] = 0;
}

int main()
{

    ifstream inStream("input.txt");

    int R, C, T;

    inStream >> R >> C >> T;

    vector<vector<int>> grid;
    vector<int> temp;
    int fine_dust;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            inStream >> fine_dust;
            temp.push_back(fine_dust);
        }
        grid.push_back(temp);
        temp.clear();
    }

    int air_cleaner_pos;
    for (int i = 0; i < R; i++)
    {
        if (grid[i][0] == -1)
        {
            air_cleaner_pos = i;
            break;
        }
    }
    
    for (int i = 0; i < T; i++)
    {
        FineDustDiffusion(grid, R, C);
        ActivateAirCleaner(grid, R, C, air_cleaner_pos);
    }

    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            answer += grid[i][j];
        }
    }
    answer += 2;

    cout << answer << endl;

    return 0;
}