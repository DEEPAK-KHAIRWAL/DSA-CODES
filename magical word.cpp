#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
bool prime(int n)
{
    if(n==1|| n==0)
    return 0;
    if(n==2)
    return 1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
char np(int a)
{
    int i=a-1,j=a+1;
    while(i>=2 &&j<2*a)
    {
        if(prime(i)&&isalpha(i))
        return i;
        if(prime(j)&&isalpha(j))
        return j;
        i--;
        j++;
    }
    while(i>=2)
    {
        if(prime(i)&&isalpha(i))
        return i;
        i--;
    }
    while(j<2*a)
    {
        if(prime(j)&&isalpha(j))
        return j;
        j++;
    }
}
main()
{
    int z;
    cin>>z;
    int n[z+1];char s[z+1][501];
    for(int i=0;i<z;i++)
    cin>>n[i]>>s[i];
     for(int i=0;i<z;i++)
     {
         for(int j=0;j<n[i];j++)
         {
             if(!prime(s[i][j])||!isalpha(s[i][j]))
            
             s[i][j]=np(s[i][j]);
         }
     }
     for(int i=0;i<z;i++)
     cout<<s[i]<<endl;
   
}
