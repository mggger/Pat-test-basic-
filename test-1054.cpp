/*


本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个正整数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。
输入样例1：

7
5 -3.2 aaa 9999 2.3.4 7.123 2.35

输出样例1：

ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

输入样例2：

2
aaa -9999

输出样例2：

ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline bool check(string & s)
{
    string s1;
    unsigned i;
    if (s[0] == '-')
    {
        i = 1;
    }
    else
    {
        i = 0;
    }
    if (s[i] == '.') return false;
    for (; s[i] != '.'&&i<s.size(); i++)
    {
        if (s[i]<'0' || s[i]>'9')
            return false;
        else
        {
            s1 += s[i];
        }
    }
    if(i==s.size())
    { 
        if (stod(s) > 1000 || stod(s) < -1000)
        {
            return false;
        }
        else {
            return true;
        }
    }
    
    string s2;
    s2 += s[i++];
    //if (i >= s.length()) return false;
    string s3;
    int cnt = 0;
    for (; i< s.length(); i++)
    {
        if (s[i]    < '0' || s[i] > '9')
            return false;
        else {
            s3 += s[i];
            ++cnt;
            if (cnt > 2)
                return false;
        }
    }
    if (stod(s) > 1000 || stod(s) < -1000)
    {
        return false;
    }
    return true;
}


int main()
{
    int N;
    cin >> N;
    vector<string> rnum(N);
    vector<string> rese;
    vector<string> res;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> rnum[i];
        if (!check(rnum[i]))
        {
            rese.push_back(rnum[i]);
        }
        else
        {
            res.push_back(rnum[i]);
            cnt++;
        }
    }
    for (unsigned i = 0; i < rese.size(); i++)
    {
        cout << "ERROR: " << rese[i] << " is not a legal number" << endl;
    }
    double sum = 0;
    for (unsigned i = 0; i < res.size(); i++)
    {
        sum += stod(res[i]);
    }
    double avg = sum / res.size();
    if (res.size() == 0)
    {
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (res.size()==1)
    {
        printf("The average of %d number is %.2f",res.size(),avg);
    }
    else{
        
        printf("The average of %d numbers is %.2f",res.size(),avg);
    }
    return 0;
}
