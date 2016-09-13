/*
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPrime(int a)
{   
  if(a==1)
  {
   return false;
  }
  if(a%2==0&&a!=2)
  {
    return false;
  }
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
  int N;
  cin>>N;
  vector<int>vec;
  int prim[10000];
  int count1=0;
  for(int i=1;i<=N;i++)
  {
    if(isPrime(i))
    {
      prim[count1++]=i;
    }
  }
  int count=0;
  for(int i=0;i<count1;i++)
  {
    int j=i+1;
    if(prim[j]-prim[i]==2)
    {
      count++;
    }
  }
  cout<<count;
  return 0;
}
