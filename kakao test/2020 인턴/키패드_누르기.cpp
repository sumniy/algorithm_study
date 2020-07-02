#include <string>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> keypad[10] =
{
  {3,1}, // 0
  {0,0}, {0,1}, {0,2},
  {1,0}, {1,1}, {1,2},
  {2,0}, {2,1}, {2,2}
};

int left_y = 3;
int left_x = 0;
int rigth_y = 3;
int right_x = 2; 

char TouchKeypad(int number, string hand)
{
    int next_y = keypad[number].first;
    int next_x = keypad[number].second;
    if(number == 1 || number == 4 || number == 7)
    {
        left_y = next_y;
        left_x = next_x;
        return 'L';
    }
    else if(number == 3 || number == 6 || number ==9)
    {
        rigth_y = next_y;
        right_x = next_x;
        return 'R';
    }
    else if(number == 2 || number ==5 || number == 8 ||number == 0)
    {        
        int left_distance = abs(left_y - next_y) + abs(left_x - next_x);
        int right_distance = abs(rigth_y - next_y) + abs(right_x - next_x);
        
        if(left_distance < right_distance)
        {
            left_y = next_y;
            left_x = next_x;
            return 'L';
        }
        else if(right_distance < left_distance)
        {
            rigth_y = next_y;
            right_x = next_x;
            return 'R';
        }
        else
        {
            // 같을 때
            if(hand == "left")
            {
                left_y = next_y;
                left_x = next_x;
                return 'L';
            }
            else
            {
                rigth_y = next_y;
                right_x = next_x;
                return 'R';
            }
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int i=0;i<numbers.size();++i)
    {
        answer += TouchKeypad(numbers[i], hand);
    }
    return answer;
}