#include<iostream>
using namespace std;
int main()
{
int a;
int target=0;
cin>>a;
while(a!=1)
{
if(a%2!=0)
 {
 a=3*a+1;
 }
 a/=2;
 target++;
}
cout<<target<<endl;
}

