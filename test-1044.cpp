/*

火星人是以13进制计数的：

    地球人的0被火星人称为tret。
    地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
    火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。 

例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：

4
29
5
elo nov
tam

输出样例：

hel mar
may
115
13

*/
#include <iostream>  
#include <stdio.h>  
#include <map>  
#include <sstream>  
#include <string>  
using namespace std;  
  
int main()  
{  
    map<int , string > m;  
    map<int , string >::iterator it;  
    m.insert(pair<int, string > (0,"tret"));  
    m.insert(pair<int, string > (1,"jan" ));  
    m.insert(pair<int, string > (2,"feb" ));  
    m.insert(pair<int, string > (3,"mar" ));  
    m.insert(pair<int, string > (4,"apr" ));  
    m.insert(pair<int, string > (5,"may" ));  
    m.insert(pair<int, string > (6,"jun" ));  
    m.insert(pair<int, string > (7,"jly" ));  
    m.insert(pair<int, string > (8,"aug" ));  
    m.insert(pair<int, string > (9,"sep" ));  
    m.insert(pair<int, string > (10,"oct"));  
    m.insert(pair<int, string > (11,"nov"));  
    m.insert(pair<int, string > (12,"dec"));  
    map<int , string > _m;  
    map<int , string >::iterator _it;  
    _m.insert(pair<int, string > (1,"tam" ));  
    _m.insert(pair<int, string > (2,"hel" ));  
    _m.insert(pair<int, string > (3,"maa" ));  
    _m.insert(pair<int, string > (4,"huh" ));  
    _m.insert(pair<int, string > (5,"tou" ));  
    _m.insert(pair<int, string > (6,"kes" ));  
    _m.insert(pair<int, string > (7,"hei" ));  
    _m.insert(pair<int, string > (8,"elo" ));  
    _m.insert(pair<int, string > (9,"syy" ));  
    _m.insert(pair<int, string > (10,"lok"));  
    _m.insert(pair<int, string > (11,"mer"));  
    _m.insert(pair<int, string > (12,"jou"));  
  
  
    map<string , int  > p;  
    map<string , int  >::iterator ip;  
    p.insert(pair<string,int  > ("tret",0));  
    p.insert(pair<string,int  > ("jan", 1));  
    p.insert(pair<string,int  > ("feb", 2));  
    p.insert(pair<string,int  > ("mar", 3));  
    p.insert(pair<string,int  > ("apr", 4));  
    p.insert(pair<string,int  > ("may", 5));  
    p.insert(pair<string,int  > ("jun", 6));  
    p.insert(pair<string,int  > ("jly", 7));  
    p.insert(pair<string,int  > ("aug", 8));  
    p.insert(pair<string,int  > ("sep", 9));  
    p.insert(pair<string,int  > ("oct",10));  
    p.insert(pair<string,int  > ("nov",11));  
    p.insert(pair<string,int  > ("dec",12));  
    map<string, int  > _p;  
    map<string, int  >::iterator _ip;  
    _p.insert(pair<string,int  > ("tam",1 ));  
    _p.insert(pair<string,int  > ("hel",2 ));  
    _p.insert(pair<string,int  > ("maa",3 ));  
    _p.insert(pair<string,int  > ("huh",4 ));  
    _p.insert(pair<string,int  > ("tou",5 ));  
    _p.insert(pair<string,int  > ("kes",6 ));  
    _p.insert(pair<string,int  > ("hei",7 ));  
    _p.insert(pair<string,int  > ("elo",8 ));  
    _p.insert(pair<string,int  > ("syy",9 ));  
    _p.insert(pair<string,int  > ("lok",10));  
    _p.insert(pair<string,int  > ("mer",11));  
    _p.insert(pair<string,int  > ("jou",12));  
  
    int n;  
    cin>>n;  
    //cin.sync();  
    //getchar();  
    cin.ignore(255,'\n');  
  
    string *st=new string [n];  
    for(int i=0;i<n;i++)  
    {  
        getline(cin,st[i]);  
    }  
  
    for(int i=0;i<n;i++)  
    {  
        bool flag=0;  
        if(st[i][0]>='0' && st[i][0]<='9')     //如果字符串第一个字符是数字，则输入的是个数字  
            flag=1;  
        if(flag==1)  
        {  
            int temp,t1,t2;  
            stringstream ss(st[i]);  
            //ss<<st;  
            ss>>temp;  
            t1=temp / 13;  
            t2=temp % 13;  
  
             if(t1>0 &&t2==0)  
            {  
                _it=_m.find(t1);  
                cout<<_it->second;  
                //flag=0;  
            }  
            else if(t1>0 && t2>0)  
            {  
                _it=_m.find(t1);  
                cout<<_it->second<<" ";  
                it=m.find(t2);  
                cout<<it->second;  
                //flag=0;  
            }  
            else              //t1=0,t2>0  
            {  
                it=m.find(t2);  
                cout<<it->second;  
                //flag=0;  
            }  
        }  
        else   //flag=0,说明输入的是火星文  
        {  
            string st1,st2;  
            stringstream ss(st[i]);  
            getline(ss,st1,' ');  
            getline(ss,st2,' ');  
             if(st2.empty())  
            {  
                ip=p.find(st1);  
                _ip=_p.find(st1);  
                if(_ip!=_p.end())  
                    cout<<_ip->second*13;  
                else  
                    cout<<ip->second;  
            }  
            else  
            {  
                _ip=_p.find(st1);  
                ip=p.find(st2);  
                cout<<_ip->second*13+ip->second;  
            }  
        }  
        if(i!=n-1)  
            cout<<endl;  
    }  
    return 0;  
} 
