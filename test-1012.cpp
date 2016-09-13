/*

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：

13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出样例1：

30 11 2 9.7 9

输入样例2：

8 1 2 4 5 6 7 9 16

输出样例2：

N 11 2 N 9

*/

#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
  int A1=0,A2=0,A3=0,A5=0;
  double A4=0;
  int N;
  int a[1000];
  cin>>N;
  for(int i=0;i<N;i++)
  {
    cin>>a[i];
  }
  bool flag1=false;
  bool flag2=false;
  bool flag3=false;
  bool flag4=false;
  bool flag5=false;
  int tmp=1;
  int count=0;
  for(int i=0;i<N;i++)
  {
    if(a[i]%10==0) 
    {
      flag1=true;
      A1+=a[i];
    }
    if(a[i]%5==1)
    {
      flag2=true;
      A2+=a[i]*tmp;
      tmp*=-1;
    }
    if(a[i]%5==2)
    {    
      flag3=true;
      A3++;
    }
    if(a[i]%5==3)
    {
      flag4=true;
      count++;
      A4+=a[i];
    }
    if(a[i]%5==4)
    {
      flag5=true;
      if(A5<=a[i])
      {
        A5=a[i];
      }
    }
  }
  if(flag1)
  {
   cout<<A1<<" ";
  }
  else
  {
    cout<<"N"<<" ";
  }
  if(flag2)
  {
   cout<<A2<<" ";
  }
  else
  {
    cout<<"N"<<" ";
  }
  if(flag3)
  {
   cout<<A3<<" ";
  }
  else
  {
    cout<<"N"<<" ";
  }
  if(flag4)
  {
   cout<<fixed<<setprecision(1)<<A4/count<<" ";
  }
  else
  {
    cout<<"N"<<" ";
  }
  if(flag5)
  {
   cout<<A5;
  }
  else
  {
    cout<<"N";
  }
  system("pause");
}
