#include<iostream>
#include<math.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
using namespace std;
int main()
{
    int i,x,v=0,a=0,b,j;
    cin>>x;
    int d[x][x];
    b=x-1;
    while(a<=x/2 )   // if a<x/2 then not works for 7
    {
            for(j=a;j<=b;j++)
            d[a][j]=++v;
            for(i=a+1;i<=b;i++)
            d[i][b]=++v;
            for(j=b-1;j>=a;j--)
            d[b][j]=++v;
            for(i=b-1;i>a;i--)
            d[i][a]=++v;
              a++;
            b--;
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
            cout<<d[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
