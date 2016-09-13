/*


复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式(R(cos(P) + isin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

输入格式：

输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。

输出格式：

在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。
输入样例：

2.3 3.5 5.2 0.4

输出样例：

-8.68-8.23i

*/
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main()
{
double r1,p1,r2,p2;
cin>>r1>>p1>>r2>>p2;
double a1,b1,a2,b2;
a1=r1*cos(p1);
b1=r1*sin(p1);
a2=r2*cos(p2);
b2=r2*sin(p2);
double A=a1*a2-b1*b2;
double B=b1*a2+a1*b2;
 if(-0.005<A&&A<0){  
        cout<<"0.00";  
    }else{  
        cout<<fixed<<setprecision(2)<<A;  
    }  
    if(B>=0){  
        cout<<fixed<<setprecision(2)<<"+"<<B<<"i";  
    }else if(-0.005<B&&B<0){  
        cout<<"+0.00i";  
    }else{  
        cout<<fixed<<setprecision(2)<<B<<"i";  
    }     

}
