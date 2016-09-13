/*

给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：

redlesPayBestPATTopTeePHPereatitAPPT

输出样例：

PATestPATestPTetPTePePee

*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int s[6]={0,0,0,0,0,0};

  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='P')
    {
      s[0]++;
    }
    if(str[i]=='A')
    {
      s[1]++;
    }
    if(str[i]=='T')
    {
      s[2]++;
    }
    if(str[i]=='e')
    {
      s[3]++;
    }
    if(str[i]=='s')
    {
      s[4]++;
    }
    if(str[i]=='t')
    {
      s[5]++;
    }
  }
  int max=0;
  for(int i=0;i<6;i++)
  {
    if(max<=s[i])
    {
      max=s[i];
    }
    
  }
  

  int i=0;
  while(max>0)
  {

    if(s[0]-i>0)
    {
      cout<<"P";
    }
    if(s[1]-i>0)
    {
      cout<<"A";
    }
    if(s[2]-i>0)
    {
      cout<<"T";
    }
    if(s[3]-i>0)
    {
      cout<<"e";
    }
    if(s[4]-i>0)
    {
      cout<<"s";
    }
    if(s[5]-i>0)
    {
      cout<<"t";
    }
    i++;
    max--;
  }
  system("pause");
}

