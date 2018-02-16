#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct list
{
	char word [20];
	char meaning[20];
};
int f=0;
void binary(struct list a[],char key[20],int n)
{
	int low=0,high=n-1,mid,temp,i;
	while(strcmp(a[low].word,a[high].word)<0||strcmp(a[low].word,a[high].word)==0)
	{
		mid=(low+high)/2;
		if(strcmp(a[mid].word,key)==0)
		{
			f=1;
			cout<<"meaning : "<<a[mid].meaning<<endl;
		    
			break;
		}
		if(strcmp(key,a[mid].word)<0)
		high=mid-1;
		else if(strcmp(key,a[mid].word)>0)
		low=mid+1;
	}
}
int main()
{
	struct list l[20];
	int i,n;
	char x[20];
	cout<<"enter no. of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter word "<<i+1<<" : ";
		cin>>l[i].word;
		cout<<"enter meaning "<<i+1<<" : ";
		cin>>l[i].meaning;
	}
	cout<<"enter element to search ";
	cin>>x;
	binary(l,x,n);
	if(f==0)
	cout<<"word not found"<<endl;
    getch();
	
}
