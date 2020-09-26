#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define endl "\n"


string get_max_num(int match_num) {
  int cnt = match_num / 2;
  string temp = "";
  for(int i=0;i<cnt;i++) {
    temp += "1";
  }
  if(match_num%2 == 1) temp[0] = '7';
  return temp;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int tc;
  cin >> tc;

  vector<int> match_nums;
  int max_match_num = -1;

  for(int i=0;i<tc;i++) {
    int match_num = 0;
    cin >> match_num;
    match_nums.push_back(match_num);
    if(match_num > max_match_num) max_match_num = match_num;
  }

  vector<string> min_dp(101);

  min_dp[2] = "1";
  min_dp[3] = "7";
  min_dp[4] = "4";
  min_dp[5] = "2";
  min_dp[6] = "6";
  min_dp[7] = "8";

  int n = 8;

  for(int n=8;n<=max_match_num;n++) {
    long long min = 9223372036854775807;
    for(int left=2;left<n;left++) {
      for(int right=2;right<n;right++) {
        if(left+right == n) {
          long long temp;
          if(right == 6) {
            temp = stoll(min_dp[left]+"0");
          } else {
            temp = stoll(min_dp[left]+min_dp[right]);
          }

          if(min > temp) {
            min = temp;
          }
        }
      }
    }
    min_dp[n] = to_string(min);
  }

  for(auto match_num : match_nums) {
    cout<<min_dp[match_num]<<" "<<get_max_num(match_num)<<endl;
  }

  // for(int i=2;i<=100;i++) {
  //   cout<<min_dp[i]<<" "<<get_max_num(i)<<endl;
  // }

  return 0;
}