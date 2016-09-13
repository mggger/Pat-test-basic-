/*


本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。
输入样例：

1234567 368782971

输出样例：

3695Q8118

*/
#include<iostream>
#include<string>
using namespace std;

char translate(char m,char n,bool tmp)
{
  char result;
  int k;
  if(tmp)    //奇数位
  {
    k=(m-'0'+n-'0')%13;
    if(k==10)
    {
      result='J';
    }
    else if(k==11)
    {
      result='Q';
    }
    else if(k==12)
    {
      result='K';

    }
    else 
      result=k+'0';
  }
  else
  {
    k=n-m;
    if(k<0)
    {
      result=(k+10)+'0';
    }
    else 
      result=k+'0';
  }
  return result;
}



int main()
{
  string A;
  string B;
  bool tmp;
  cin>>A>>B;
  int a=A.length();
  int b=B.length();
  int ab=b-a;
  int j=0;
  if(ab>0)
  {
    for(int i=ab;i<b;i++)
    {    
      if(b%2)
      {
        tmp=(i+1)%2;
      }
      else tmp=i%2;
      B[i]=translate(A[j++],B[i],tmp);
    }
  }
  else
  {
    ab=a-b;
    string Btmp(ab,'0');
    Btmp+=B;
    B=Btmp;
      b=B.length();
    {
      for(int i=0;i<a;i++)
      {    
        if(b%2)
        {
          tmp=(i+1)%2;
        }
        else tmp=i%2;
        B[i]=translate(A[i],B[i],tmp);
      }
    }
    


  }


  cout<<B;
  return 0;
}
