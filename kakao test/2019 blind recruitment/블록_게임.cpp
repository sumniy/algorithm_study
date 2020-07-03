#include <vector>

using namespace std;

int N;

pair<int, int> erasable_shapes[5][3] =
    {
        {{1, 0}, {1, 1}, {1, 2}},
        {{1, 0}, {2, 0}, {2, -1}},
        {{1, 0}, {2, 0}, {2, 1}},
        {{1, -2}, {1, -1}, {1, 0}},
        {{1, -1}, {1, 0}, {1, 1}}};

pair<int, int> empty_space[5][2] =
    {
        {{0, 1}, {0, 2}},
        {{0, -1}, {1, -1}},
        {{0, 1}, {1, 1}},
        {{0, -2}, {0, -1}},
        {{0, -1}, {0, 1}}};

int FindShape(vector<vector<int>> &board, int num, int y, int x)
{
    for (int i = 0; i < 5; i++)
    {
        bool is_matched = true;
        for (int j = 0; j < 3; j++)
        {
            int next_y = y + erasable_shapes[i][j].first;
            int next_x = x + erasable_shapes[i][j].second;
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N || board[next_y][next_x] != num)
            {
                is_matched = false;
                break;
            }
        }
        if (is_matched)
        {
            return i;
        }
    }
    return -1;
}

bool EraseBlock(vector<vector<int>> &board, int shape, int y, int x)
{
    for (int i = 0; i < 2; i++)
    {
        int next_y = y + empty_space[shape][i].first;
        int next_x = x + empty_space[shape][i].second;
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N || board[next_y][next_x] != 0)
            return false;

        while (next_y > 0)
        {
            if (board[--next_y][next_x] != 0)
                return false;
        }
    }

    board[y][x] = 0;
    for (int i = 0; i < 3; i++)
    {
        int next_y = y + erasable_shapes[shape][i].first;
        int next_x = x + erasable_shapes[shape][i].second;
        board[next_y][next_x] = 0;
    }

    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;

    N = board.size();

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (board[y][x] > 0)
            {
                int shape = FindShape(board, board[y][x], y, x);
                if (shape >= 0)
                {
                    if (EraseBlock(board, shape, y, x))
                    {
                        answer += 1;
                        x = -1;
                        continue;
                    }
                }
            }
        }
    }
    return answer;
}