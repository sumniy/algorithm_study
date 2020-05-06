#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{ // stringstream에 문자열 넣는 망법 1 (문자열로 입력)
  std::stringstream ss1("test 1 2 3 4 5");
  std::string str;
  while (ss1 >> str)
  {
    std::cout << str << std::endl;
  } // stringstream에 문자열 넣는 망법 2 (문자열 format 사용하여 입력)
  std::stringstream ss2;
  ss2 << "1" << ' ' << -1 << ' ' << 2 << 3;
  while (ss2 >> str)
  {
    std::cout << str << std::endl;
  }
  return 0;
}
