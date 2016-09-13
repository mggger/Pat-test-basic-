/*“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/

#include<string>
#include<list>
#include<iostream>
using namespace std;

int main()
{
int n=0;
list<string>slist;
string str1("NO");
string str2("YES");
cin>>n;
while(n>0)
{
string str;
cin>>str;
int str_len=str.size();
int count_p=0;int  count_t=0;int count_a=0;int p_pos;int t_pos;
for(int i=0;i<str.size();i++)
{

if(str[i]=='A')
{count_a++; };
if(str[i]=='P')
{
 count_p++;
 p_pos=i;
}
if(str[i]=='T')
{
count_t++;
t_pos=i;
}
}
if(count_a+count_p+count_t!=str_len||count_p>1||count_t>1||t_pos-p_pos<=1||p_pos*(t_pos-p_pos-1)!=str_len-t_pos-1)
slist.push_back(str1);
else slist.push_back(str2);
n--;
}
list<string>::iterator pos;
for(pos=slist.begin();pos!=slist.end();++pos)
{
cout<<*pos<<endl;
}
return 0;
}
