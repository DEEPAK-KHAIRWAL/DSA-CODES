#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	char a[20],b[20],c[20],d[20];
	int i,j=0,n1,n2,k=0;
	cout<<"enter no. of character in 1 and 2 string\n";
	cin>>n1>>n2;
    cout<<"enter string 1:";
	cin>>a;
	cout<<"\nenter string 2:";
	cin>>b;
	int n=n1+n2;
	i=0;
		while(i<n && j<n1 && k<n2)
	{
		c[i]=a[j];
		i++;
		j++;
		c[i]=b[k];
		i++;
		k++;
	}
	while(j<n1)
	{
		c[i]=a[j];
		i++;
		j++;
	}
	while(k<n2)
	{
		c[i]=b[k];
		i++;
		k++;
	}
	cout<<"merged string:  ";
	for(i=0;i<n;i++)
	cout<<c[i];
	int n3=n/2;
	for(i=n3;i<n;i++)
	d[i-n3]=c[i];
	for(i=0;i<n3;i++)
	d[i+n3]=c[i];
	cout<<"\nreversed string:  ";
	for(i=0;i<n;i++)
	cout<<d[i];
	getch();
}
