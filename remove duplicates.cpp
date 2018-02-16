#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct app
{
	char name[20],add[50];
	int age,ph,yoe;
}a[20],*ptr[20];
int duplicate(struct app *ptr[],int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
		if(strcmp(ptr[j]->name,ptr[i]->name)==0 && ptr[i]->ph==ptr[j]->ph)
		{
			for(k=j;k<n-1;k++)
			ptr[k]=ptr[k+1];
			n--;
			j--;
		}
	    }
	}
	return n;
}
int main()
{
	int i,j,n,n1;
	cout<<"enter no. of applicants\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter name,age,address,pnone no.,years of experience\n";
		cin>>a[i].name>>a[i].age>>a[i].add>>a[i].ph>>a[i].yoe;
	}
	for(i=0;i<n;i++)
	ptr[i]=&a[i];
	n1=duplicate(ptr,n);
	cout<<"after removing duplicates\n";
	for(i=0;i<n1;i++)
	{
		cout<<"name :"<<ptr[i]->name<<endl;
		cout<<"age :"<<ptr[i]->age<<endl;
		cout<<"address :"<<ptr[i]->add<<endl;
		cout<<"phone no. :"<<ptr[i]->ph<<endl;
		cout<<"years of experience :"<<ptr[i]->yoe<<endl;
	}
}
