/*读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu*/

#include<map>
#include<string>
#include<iostream>
#include<list>
using namespace std;
void show(int a)
 {
list<string>slist;
map<int,string> Smap;
Smap.insert(make_pair(0,"ling"));
Smap.insert(make_pair(1,"yi"));
Smap.insert(make_pair(2,"er"));
Smap.insert(make_pair(3,"san"));
Smap.insert(make_pair(4,"si"));
Smap.insert(make_pair(5,"wu"));
Smap.insert(make_pair(6,"liu"));
Smap.insert(make_pair(7,"qi"));
Smap.insert(make_pair(8,"ba"));
Smap.insert(make_pair(9,"jiu"));
while(a>0)
{
int tmp=a-a/10*10;
slist.push_front(Smap[tmp]);
slist.push_front(" ");
a/=10;
}
slist.pop_front();   
list<string>::iterator pos;
for(pos=slist.begin();pos!=slist.end();++pos)
{
cout<<*pos;
}
cout<<endl;
 };

int main()
{
int sum=0;
string str;
cin>>str;
for(int i=0;i!=str.size();++i)
{
sum+=str[i]-48;
}
show(sum);
return 0;
}
