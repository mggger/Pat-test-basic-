/*

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。
输入样例1：

3862767 6 13530293 3

输出样例1：

399

输入样例2：

3862767 1 13530293 8

输出样例2：

0

*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
  string A, B;
  char a, b;
  cin >> A >> a >> B >> b;
  int pa = 0; 
  int pb = 0;
  string tmp="";
  string tmp1 = "";
  for (int i = 0; i < A.length(); i++)
  {
    if (A[i] == a)
    {
      tmp += a;
    }

  }
  if (A.length())
  {
    pa = atoi(tmp.c_str());
  }
  else
  {
    pa = 0;
  }
  for (int i = 0; i < B.length(); i++)
  {
    if (B[i] == b)
    {
      tmp1 += b;
    }

  }
  if (B.length())
  {
    pb = atoi(tmp1.c_str());

  }
  else
  {
    pb = 0;
  }
  cout << pa + pb;
  system("pause");
}
