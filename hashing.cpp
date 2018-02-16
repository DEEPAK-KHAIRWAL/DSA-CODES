#include<iostream>
using namespace std;
#include<conio.h>
int hash(int a[],int b,int n)
{
	int s,i,x;
	s=b%n;
	if(a[s]==NULL)
	{
		return s;
	}
	else
	if(a[s]!=NULL)
	{
		i=0;
		 x=s;
		while(a[x]!=NULL)
		{
			i++;
			x=s+i;       //linear probing
			if(x>n-1)
			{
				x=x%n;   //wrapping around
			}
		}
		return x;
	}
}
int main()
{
	int n,i,v,z;
	int l;
	cout<<"enter no.of elements";
	cin>>n;
	int a[n+2];
	for(i=0;i<n;i++)
	{
		cout<<"enter element";
		cin>>v;
		z=hash(a,v,n);
		a[z]=v;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"enter element to search";
	cin>>l;
	if(a[hash(a,l,n)]==l)  // we can use this also
	{
	cout<<"found";
    }
	else
	{
	cout<<"not found";
    }
	getch();
}
