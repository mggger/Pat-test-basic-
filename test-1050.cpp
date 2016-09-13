/*

本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
输入样例：

12
37 76 20 98 76 42 53 95 60 81 58 93

输出样例：

98 95 93
42 37 81
53 20 76
58 60 76

#include<iostream>
#include<algorithm>
using namespace std; 
int a[10000][10000]={0},s[10000]; 
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,i,j,x,y,r,c,tot,minn=9999;
   
    cin>>n;
    for(int i=0;i<n;i++)
  {
  cin>>s[i];
  }
  
    sort(s,s+n,cmp);
    for(i=1;i<=sqrt(n*1);i++)
    {
        if(n%i==0)
        {
            if(n/i-i<minn){
                minn=n/i-i;
                r=i;
            }
        }        
    }
    c=n/r;//c>r c行r列 
    a[0][0]=s[0];
    tot=x=y=0;
    while(tot < r * c-1)
    {
        while(y + 1 < r && ! a[x][y + 1])
            a[x][++y] = s[++tot];
        while(x + 1 < c && !a[x + 1][y])
            a[++x][y] = s[++tot];
        while(y - 1 >= 0 && !a[x][y - 1])
            a[x][--y] = s[++tot];
        while(x - 1 >= 0 && !a[x - 1][y])
            a[--x][y] = s[++tot];   
    }
    for(i=0;i<c;i++){
            cout<<a[i][0];
        for(j=1;j<r;j++){
                cout<<" "<<a[i][j];
        } 
       cout<<endl;
    }
    return 0;
}
