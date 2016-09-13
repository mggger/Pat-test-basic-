/*

拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

    每排人数为N/K（向下取整），多出来的人全部站在最后一排；
    后排所有人的个子都不比前排任何人矮；
    每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
    每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
    若多人身高相同，则按名字的字典序升序排列。这里保证无重名。 

现给定一组拍照人，请编写程序输出他们的队形。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
输入样例：

10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

输出样例：

Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;


struct info
{
string name;
int height;
} info1;

bool camp(info i1,info i2)
{
  if(i1.height==i2.height)
    return i1.name>i2.name;
  return i1.height<i2.height;
}

int main()
{
  vector<info>vec;
  int N,K;
  cin>>N>>K;
  for(int i=0;i<N;i++)
  {
  cin>>info1.name>>info1.height;
  vec.push_back(info1);
  }
  sort(vec.begin(),vec.end(),camp);
  string result="";
   int w=N/K;   
    for(int i=0;i<K;i++){  
        int begin=i*w;  
        int end=i*w+w;  
        if(end+w>N)  
            end=N;  
        string line="";  
        line=vec[end-1].name;  
        for(int j=end-2;j>=begin;j--){  
            if(j%2!=end%2){  
                line=line+" "+vec[j].name;//放到后边   
            }else{  
                line=vec[j].name+" "+line;//放到前面   
            }  
        }  
        //cout<<line<<endl;  
        result=line+"\n"+result;//精华！！！   
    }  
    cout<<result;  
      system("pause");
}  
