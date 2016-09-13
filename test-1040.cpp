/*



字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
输入样例：

APPAPT

输出样例：

2

*/

#include<iostream>
#include<string>
using namespace std;



int main()
{
  string str;
  cin>>str;
       
  int len=str.length();
  int count_T=0,count_AT=0,count_PAT=0;
  while(len--)
  {
    if(str[len]=='T')
    {
     count_T++;
    }
    else if(str[len]=='A')
    {
     count_AT+=count_T;
    }
    else 
    {
     count_PAT+=count_AT;
       if(count_PAT>=1000000007) count_PAT%=1000000007;   
    }
  }

  cout<<count_PAT;
}
