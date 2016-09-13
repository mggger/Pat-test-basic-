/*

大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
输入样例：

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出样例：

THU 14:04

*/
#include<iostream>  
#include<string>  
using namespace std;  
int main(){  
  string s1;  
  string s2;  
  string s3;  
  string s4;  
  cin>>s1>>s2>>s3>>s4;  
  int mark=0;  
  for(int i=0;i<s1.size()&&i<s2.size();i++){  
    if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='G')){  
      switch(s1[i]){  
      case 'A':  cout<<"MON ";break;  
      case 'B':  cout<<"TUE ";break;                
      case 'C':  cout<<"WED ";break;           
      case 'D':  cout<<"THU ";break;         
      case 'E':  cout<<"FRI ";break;           
      case 'F':  cout<<"SAT ";break;           
      case 'G':  cout<<"SUN ";break;           
      }   
      mark=i;  
      break;        
    }  

  }  
  for(int j=mark+1;j<s1.size()&&j<s2.size();j++){  
    if(s1[j]==s2[j]&&(s1[j]>='A' &&s1[j]<='N' || s1[j]>='0'&&s1[j]<='9')){  
      if(s1[j]>='A'&&s1[j]<='N'){  
        int x=s1[j]-'A'+10;  
        cout<<x/10<<x%10<<":";  
      }  
      else{   
        int y=s1[j]-'0';  
        cout<<y/10<<y%10<<":";  
      }  
      break;     
    }  

  }   

  for(int k=0;k<s3.size()&&k<s4.size();k++){  
    if(s3[k]==s4[k]&&(s3[k]>='A'&&s3[k]<='Z'||s3[k]>='a'&&s3[k]<='z')){  
      cout<<k/10<<k%10<<endl;  


    }   
  }  

  system("pause");  
  return 0;  
}  
