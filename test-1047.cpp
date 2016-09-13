/*

编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：

输入第一行给出一个正整数N（<=10000），即所有参赛队员总数。随后N行，每行给出一位队员的成绩，格式为：“队伍编号-队员编号 成绩”，其中“队伍编号”为1到1000的正整数，“队员编号”为1到10的正整数，“成绩”为0到100的整数。

输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。
输入样例：

6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61

输出样例：

11 176

*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef map<int,int>::iterator iter;
int func(string str)
{   
    string str1;
  int tmp_=str.find('-');
  for(int i=0;i<tmp_;i++)
  {
  str1.push_back(str[i]);
  }
  int m=atoi(str1.c_str());
  return m;
}
void insert(map<int,int> &p,int m,int n)
{
  iter iter1;
  iter1=p.find(m);
  if(iter1==p.end())
  {
  p.insert(pair<int,int>(m,n));
  //cout<<"insert number successed"<<endl;
  }
  else{
  p[m]+=n;
  //cout<<"insert the same number successed"<<endl;
  }
}

int main()
{
  int n;
  map<int,int>a;
  cin>>n;
  
  for(int i=0;i<n;i++)
  {
  string str;
  int count;
  cin>>str>>count;
  int m=func(str);
  insert(a,m,count);
  }
  iter pos=a.begin();
  int sum=0,position=0;
  for(pos;pos!=a.end();pos++)
  {    
    if(sum<=pos->second)
    {
    sum=pos->second;
    position=pos->first;
    }
     
  }
  cout<<position<<" "<<sum;
  return 0;
}
