#include<iostream>
using namespace std;
#include<string.h>
	
int found(int x,int l,char *s1,char *s2)
{
	static int d;
	d=0;
	
	for(int j=0;j<x;j++)
	{
		if(s1[l]==s2[j])
		{
			
			for(int k=j;k<x-1;k++)
			{
				s2[k]=s2[k+1];
			}
				x--;
			    
				l++;
				d=found(x,l, s1,s2);
			if(x==0)
			d=1;
			
			break;
		}
	}
	
	return d;
}
int main()
{
string s2,s1;
cout<<"enter a string : ";
cin>>s2;
cout<<"enter a sample string : ";
cin>>s1;
char b[1024];
	strcpy(b,s1.c_str());
char a[1024];
	strcpy(a,s2.c_str());
int i,count=0;
for(i=0;i<=strlen(b)-strlen(a);i++)
{
	char v[1024];
	strcpy(v,s2.c_str());
if(found(strlen(a),i,b,v)==1)
{
	
	count++;
	i=i+strlen(a)-1;
	
	}	
}
cout<<count;

	return 0;  }

