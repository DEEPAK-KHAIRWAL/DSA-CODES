#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct name
{
	char n[20];
};
int partition(struct name [],int,int);
void quicksort(struct name a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q);
		quicksort(a,q+1,r);
	}
}
int partition(struct name a[],int p,int r)

{
	int i,j;
	struct name  x;
	struct name temp;
	x=a[p];
	i=p-1;
	j=r+1;
	while(1)
	{
		do
		{
			j--;
		}while(strcmp(a[j].n,x.n)>0);
		do
		{
			i++;
		}while(strcmp(a[i].n,x.n)<0);
		if(i<j)
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
		else
		return j;
	}
}
int main()
{
	struct name a[20];
	int n,i;
	cout<<"enter no.";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter element";
		cin>>a[i].n;
	}
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		
		cout<<a[i].n<<endl;
	}
	getch();
}
