/*

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
输入样例1：

10.16.27 14.1.28

输出样例1：

3.2.1

输入样例2：

14.1.28 10.16.27

输出样例2：

-3.2.1

*/
#include<iostream>
#include<string>
using namespace std;

void deal(string str, int &a, int &b, int &c)
{
  int tmp = 0;
  int tmp1 = 0;
  tmp = str.find('.');
  string strtmp = str.substr(0, tmp);
  a = atoi(strtmp.c_str());
  for (int i = tmp + 1; i < str.length(); i++)
  {
    if (str[i] == '.')
    {
      tmp1 = i;
    }
  }
  strtmp = str.substr(tmp + 1, tmp1 + 1);
  b = atoi(strtmp.c_str());
  strtmp = str.substr(tmp1 + 1, str.length());
  c = atoi(strtmp.c_str());
}

int main()
{
  string str1;
  string str2;
  cin >> str1 >> str2;
  int a1 = 0, b1 = 0, c1 = 0;
  int a2 = 0, b2 = 0, c2 = 0;
  deal(str1, a1, b1, c1);
  deal(str2, a2, b2, c2);
  int a3, b3, c3;

  if (a1 < a2)
  {
    if (c1 > c2)
    {
      c3 = c2 + 29 - c1;
      if (b1 >= b2)
      {
        b3 = b2 + 17 - b1 - 1;
        a3 = a2 - a1 - 1;
      }
      else
      {
        b3 = b2 - b1 - 1;
        a3 = a2 - a1;
      }
    }
    else
    {
      c3 = c2 - c1;
      if (b1 > b2)
      {
        b3 = b2 + 17 - b1;
        a3 = a2 - a1 - 1;
      }
      else
      {
        b3 = b2 - b1;
        a3 = a2 - a1;
      }
    }
    if (a3 == 0 && b3 == 0 && c3 == 0)
    {
      cout << 0;
    }
    else
      cout << a3 << "." << b3 << "." << c3;
  }
  else
  {
    if (c1 >= c2)
    {
      c3 = c1 - c2;
      if (b1 >= b2)
      {
        b3 = b1 - b2;
        a3 = a2 - b2;
      }
      else
      {
        b3 = b1 + 17 - b2;
        a3 = a2 - a1 + 1;
      }
    }
    else
    {
      c3 = c1 + 29 - c2;
      if (b1 > b2)
      {
        b3 = b1 - b2 - 1;
        a3 = a2 - a1;
      }
      else
      {
        b3 = b1 + 17 - 1 - b2;
        a3 = a2 - a1 + 1;
      }

    }
    
      cout << a3 << "." << b3 << "." << c3;
  }
  system("pause");
}
