#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

enum Operator {
    PLUS,
    MINUS,
    MULTI
};

long long Calculation(long long a, long long b, Operator op)
{
    if(op == PLUS){
        return a + b;
    }
    else if(op == MINUS){
        return a - b;
    }
    else //(op == MULTI)
    {
        return a*b;
    }
}

long long getResult(vector<long long> numbers, vector<Operator> Ops, vector<Operator> priority)
{
    for(auto& priority_operator : priority)
        {
            for(int j=0;j<Ops.size();j++)
            {
                if(Ops[j] == priority_operator)
                {
                    numbers[j+1] = Calculation(numbers[j], numbers[j+1], Ops[j]);
                    
                    auto Ops_it = Ops.begin();
                    auto numbers_it = numbers.begin();
                    Ops_it += j;
                    numbers_it += j;
                    Ops.erase(Ops_it);
                    numbers.erase(numbers_it);
                    j--;
                }
            }
        }
    
    return abs(numbers[0]);
}



long long solution(string expression) {
    long long answer = 0;
    
    vector<Operator> Ops;
    
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i] == '+')
        {
            expression[i] = ' ';
            Ops.push_back(PLUS);
        }
        else if(expression[i] == '-')
        {
            expression[i] = ' ';
            Ops.push_back(MINUS);
        }
        else if(expression[i] == '*')
        {
            expression[i] = ' ';
            Ops.push_back(MULTI);
        }
    }
    
    stringstream ss(expression);
    
    vector<long long> numbers;
    int num;
    while(ss >> num)
    {
        numbers.push_back(num);
    }
    
    vector<Operator> priority = {PLUS, MINUS, MULTI};
    long long max = -1;
    do
    {
        long long result = getResult(numbers, Ops, priority);
        if(max < result) max = result;
    } while(next_permutation(priority.begin(), priority.end()));
    
    answer = max;
    return answer;
}