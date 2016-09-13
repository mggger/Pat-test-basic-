/*

令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27

输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/
#include<iostream>
using namespace std;

bool isPrime(int a)
{
  if(a<2)
  {
    return false;
  }
  if(a%2==0&&a!=2)
    return false;
  for(int i=3;i*i<=a;i++)
  {
    if(a%i==0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int m,n;
  cin>>m>>n;
  int prim[10000];
  int count=0;
  for(int i=0;i<=10000;i++)
  {   
    if(isPrime(i))
    {
      prim[count++]=i;
    }
  }
  int count1=0;
  for(int i = m; i <= n; ++i)
  {
    cout << prim[i-1];
    if ((i-m+1) % 10 == 0 || i == n)
    {
      cout << endl;
    }
    else
    {
      cout << ' ';
    }

  }

  return 0;
}
