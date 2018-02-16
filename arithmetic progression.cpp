#include<iostream>
using namespace std;
int main()
{
int a[]={2,4,6,7,8,10,12,13},i,j,k,n=sizeof(a)/4,max=2,x,y,v,d=2;
/*int d[n],g[n];
for(i=0;i<n;i++)
d[i]=2;
for(i=0;i<n;i++)
g[i]=2;*/
for(i=0;i<n-2;i++)
{
for(j=i+1;j<n-1;j++)
{
	v=j;
	x=a[j]-a[i];
	for(k=j+1;k<n;k++)
	{
		y=a[k]-a[j];
		if(y==x)
		{
		d++;
		j=k;
		
		
	}
	}
	if(d>max)
	max=d;
	d=0;
}

}
/*for(i=0;i<n;i++)
{
	cout<<d[i]<<" ";
}*/
cout<<max;
	return 0;  }

