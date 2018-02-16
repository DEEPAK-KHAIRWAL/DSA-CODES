#include<iostream>
using namespace std;
#include<conio.h>
class stack
{
	public:
	int a[30],top=-1;
	void push(int x)
{
	top++;
	a[top]=x;
}
void pop()
{
	if(top!=-1)
	top--;
}

};
int main()
{
	int i,n,x,fl,k,f,t,j;
	stack sr,sp,st;
	cout<<"enter no. of elements ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter element ";
		cin>>x;
		sr.push(x);
	}
	
	for(i=sr.top;i>=0;i--)
	{
		fl=0;
		for(j=i-1;j>=0;j--)
		{
			if(sr.a[i]==sr.a[j])
			{
				fl=1;
				break;
			}
		}
		for(k=0;k<=st.top;k++)
		{
			if(sr.a[i]==st.a[k])
			{
				fl=1;
				break;
			}
		}
		if(fl==1)
		{
		st.push(sr.a[i]);
		sr.pop();
		}
		else
		{
		   sp.push(sr.a[i]);
		   sr.pop();
		}
	}
	for(i=sp.top;i>=0;i--)
	{
		cout<<sp.a[i]<<" ";
	}
	getch();
}

