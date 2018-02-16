#include<iostream>
//#include<iomanip>
using namespace std;
/* PRESTIGE
1. static k=0; - important
2. continue;
3. k--;
4. else
5. d[]=0; (everytime) - important
6. memcpy
*/
int found(int b[],int x,int n)
{
	int j=0,i;
	for(i=1;i<=n;i++)
	if(b[i]==x)
	{
		j=1;
		break;
	}
	return j;
}

int find(int m[][3], int n,int k,int min)
{
	static int d[3],a[3],dmin[3],dist;
	d[0]=0;
	a[0]=0;
	int i,f=1;
	if(k==n)
	{
		dist=dist+m[a[k-1]][0];
		if(dist<min)
		{
		min=dist;
		memcpy(dmin, d, sizeof(d));
     	}
        
     	
     	//	cout<<dmin[k-2];
     		
		 dist=dist-m[a[k-1]][0];
		 
	}
	else
	for(a[k]=1;a[k]<n;a[k]++)
	{
		if(found(d,a[k],k-1))
		{
		continue;
	}
		dist=dist+m[a[k-1]][a[k]];
		d[k]=a[k];
		
		k++;
		
		min=find(m,n,k,min);
		k--;
	}
	dist=dist-m[a[k-2]][a[k-1]];
	return min;
	
}

int main()
{
int n,z[10],c[7],i;
n=3;
int m[n][3]={{0,1000,5000},{5000,0,1000},{1000,5000,0}};
cout<<find(m,n,1,1000000);
/*for(i=0;i<5;i++)
z[i]=i*i;
memcpy(c,z,sizeof(z));
for(i=0;i<5;i++)
cout<<c[i]<<" ";*/

return 0; 
}


