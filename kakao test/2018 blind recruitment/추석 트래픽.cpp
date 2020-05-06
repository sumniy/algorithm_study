#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

vector<string> finish;
vector<string> start;

double S_to_db(string time)
{
  for(auto& chr : time)
  {
    if(chr == '.') continue;
    if(chr < '0' || chr > '9') chr = ' ';
  }
  stringstream ss(time);

  double h, m, s;
  ss>>h>>m>>s;
  h *= 3600;
  m *= 60;

  return h + m + s;
}

double T_to_db(string time)
{
  time[time.size()-1] = ' ';
  stringstream ss(time);

  double ret;
  ss>>ret;
  return ret;
}

string db_to_time(double time)
{
  double intgr, ms;
  int intpart, h,m,s;

  ms = modf(time, &intgr);

  intpart = (int) intgr;

  h = intpart / 3600;
  intpart = intpart%3600;
  m = intpart/60;
  intpart = intpart%60;
  s = intpart;

  string ret = "";
  ret = h + ':' + m + ':' + s + '.' + ms;
  return ret;
}

int solution(vector<string> lines) {
    int answer = 0;

    string start_time;
    string finish_time;
    for(auto& log : lines)
    {
      start_time = log.substr(11,12);
      finish_time = log.substr(24);
      finish.push_back(start_time);
      double temp = S_to_db(start_time) - T_to_db(finish_time);
      start.push_back(db_to_time(temp));
    }

    for(auto& begin : finish)
    {
      double temp = S_to_db(begin) + T_to_db("0.999s");
      string end = db_to_time(temp);

      int cnt = 0;

      double start_ = S_to_db(begin);
      double finish_ = temp;

      for(int i=0;i<lines.size();i++)
      {
        double start__ = S_to_db(start[i]);
        double finish__ = S_to_db(finish[i]);

        if(start__ <= finish_ && finish__ >= start_) cnt++
        else if(start__ <= start_ && finish__ >= finish_) cnt++;
        else if(start__<=finish_ && finish__ >= start_) cnt++;


      }
      if(answer < cnt) answer = cnt;
    }

    return answer;
}