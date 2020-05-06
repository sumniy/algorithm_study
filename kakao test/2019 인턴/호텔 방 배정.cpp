#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> hotel;

int find(int number)
{
  if(hotel[number] == 0) return number;
  else
  {
    return hotel[number] = find(hotel[number+1]);
  }
}


    
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    int size = room_number.size();
    int number;
    int empty_room;
    for(int i=0;i<size;i++)
    {
      number = room_number[i];
      empty_room = find(number);
      answer.push_back(empty_room);
    }
    
    
    return answer;
}