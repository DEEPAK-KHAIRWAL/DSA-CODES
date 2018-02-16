#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int prime(int a)
{
	int n;
	if(a==1)
	 return 0;
	 else
	 {
	for(n=2;n<=a/2;n++)
	{
		if(a%n==0)
			return 0;
	}
	return 1;
}
}
int primeb(int a,int b)
{
	int m;
	for(m=a+1;m<b;m++)
	{
		if(prime(m)==1)
		  return 0;
	}
	return 1;
}
int main()
{
	int a[10][6],w,j,k,l[10],count,b,c,i,t;
	t=1;//cin>>t;
	for(i=0;i<t;i++)
	{
		//cin>>l[i];
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	}
	for(i=0;i<t;i++)
	{
		w=0;
		for(j=10;j<40;j++)
		{ 
		    count=0;
			c=pow(j,2)+a[i][0];
			for(k=1;k<6;k++)
			{
			if(prime(c)==1)
			{
				b=pow(j,2)+a[i][k];
				if(primeb(c,b)==1)
				{
					c=b;
					count++;
				}
			}
			else
			break;
		}
		if(prime(c)==1)
		count++;
		if(count==6)
		cout<<j;
		}
	}
	cout<<"f";
getch();
return 0;
}
