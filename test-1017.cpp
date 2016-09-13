/*

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。
输入样例：

123456789050987654321 7

输出样例：

17636684150141093474 3

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  string a;
  int b;
  vector<int>vec;
  cin >> a >> b;
  int num=0;
  int tmp1=0;
  int tmp =0;

  for (int i = 0; i < a.length(); i++)
  {
    num = a[i]-48+tmp*10;
    if (a[i] < b)
    {
      num = a[i]*10 + (a[i + 1] -48);
      i++;
      tmp = num % b;
      tmp1 = num / b ;
      vec.push_back(tmp1);
    }
    else
    {
      tmp = num % b;
      tmp1 = num / b ;
      vec.push_back(tmp1);
    }
  }
  int j=0;
  for(int i=0;i<vec.size();i++)
  {
      if(vec[i]>0)
    {
         j=i;
       break;
    }
  }
  for(int i=j;i<vec.size();i++)
  {
    cout<<vec[i];
  }
  cout  << " " << tmp;
  system("pause");
}
