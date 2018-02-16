#include<iostream>
using namespace std;
int main()
{
int n,i=0,a[100],s[100],len,flag=1,f=0,l,count=0;
cout<<"enter a number : ";
cin>>n;
	while(n>=2)
	{
		a[i]=n%2;
		n=n/2;
		i++;
	}
	a[i]=n;
	len=i+1;

for(int i=len-1;i>=0;i--)
s[i]=a[len-i-1];
l=len;
while(f<l)
{
if(s[f]!=s[l])
flag=0;
f++;
l--;
}
for(i=0;i<len;i++)
if(s[i]==1)
count++;
if(flag=1)
cout<<count;
	return 0;  }

