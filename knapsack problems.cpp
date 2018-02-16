#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
	int W,n,i,j,x;
	cout<<"enter no.of items and knapsack weight";
	cin>>n>>W;
	int w[n+5],v[n+5],V[n+5][W+5],w1[W+5];
	for(i=1;i<=n;i++)
	{
		cout<<"enter weight of element "<<i+1<<endl;
		cin>>w[i];
		cout<<"enter value of element "<<i+1<<endl;
		cin>>v[i];
	}
	for(i=0;i<=n;i++)
	{
	V[i][0]=0;
    }
	for(i=0;i<=W;i++)
	{
	w1[i]=i;
	V[0][i]=0;
    }
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(w1[j]<w[i])
			{
			V[i][j]=V[i-1][j];
		    }
			else
			{
				x=v[i]+V[i-1][w1[j]-w[i]];
				if(x>V[i-1][j])
				{
				V[i][j]=x;
			    }
				else
				{
				V[i][j]=V[i-1][j];
			    }
		}
		}
	}
/*	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			cout<<V[i][j]<<endl;
		}
	}*/
	cout<<V[n][W];
	int m;
	int b[n+5],s=0;
	i=n;
	j=W;
	m=V[n][W];
	while(m!=0)
	{
		m=V[i][j];
		if(m!=V[i-1][j])
		{
		b[s]=i;
		i--;
		j=w1[j]-w[i];
	    }
		else
		{
			i--;
		}
		s++;
	}
	for(i=0;i<n;i++)
	{
	cout<<"items ="<<b[i];
    }
	getch();
}
