#include<iostream>
#include<conio.h>
using namespace std;
int  c=0;
void mergesort(int [],int i,int);
void merge(int [],int,int,int);
int main()
{
	int a[10],i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<c;
	getch();
}
void mergesort(int a[],int p,int r)
{
	c++;
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)
{
	int b[10],l1,r1,i;
	l1=p;
	r1=q+1;
	i=p;
	while((l1<=q)&&(r1<=r))
	{
		if(a[l1]<a[r1])
		{
			b[i]=a[l1];
			l1=l1+1;
			i=i+1;
		}
		else
		{
			b[i]=a[r1];
			r1=r1+1;
			i++;
			
		}
	}
	while(l1<=q)
	{
		b[i]=a[l1];
		l1++;
		i++;
	}
	while(r1<=r)
	{
		b[i]=a[r1];
		r1++;
		i++;
	}
	for(i=p;i<=r;i++)
	{
		a[i]=b[i];
	}
}
