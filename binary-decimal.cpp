#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i,n,a[10],s=0;
	cout<<"enter no. of digits in binary no.";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter digit";
		cin>>a[i];
		s=s+(a[i]*pow(2,n-1-i));
	}
	cout<<"decimal equivalent :"<<s;
	getch();
}
