#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
  int n,i,k,sum=0;
  cin>>n>>k;
  k=k-1;
  int c,b;
  int j=k;
  int a[n+1];
  for(i=0;i<n;i++)
  cin>>a[i];
  if(n>=3)
  {
  
  while(j<n-2)
  {
  	b=j+1,c=j+2;
  	if(a[b]>0)
  	{
  		sum=sum+a[b];
  		j++;
	  }
	  else if(a[b]<0&&a[c]>0)
  	{
  		sum=sum+a[c];
  		j=j+2;
	  }
	   else if(a[b]<0&&a[c]<0)
  	{
  		sum=sum+max(a[b],a[c]);
  		if(max(a[b],a[c])==a[c])
  		j=j+2;
  		else
  		j++;
	  }
	  
  }
  if(j=n-2)
  {
  	    if(a[j]<0&&a[j]<a[j-1])
  		sum=sum+a[n-1]-a[j];
  		else
  		sum=sum+a[n-1];
  		j++;
	  
  }
  while(j>=2)
  {
  	b=j-1,c=j-2;
  	if(a[b]>0)
  	{
  		sum=sum+a[b];
  		j--;
	  }
	  else if(a[b]<0&&a[c]>0)
  	{
  		sum=sum+a[c];
  		j=j-2;
	  }
	   else if(a[b]<0&&a[c]<0)
  	{
  		sum=sum+max(a[b],a[c]);
  		if(max(a[b],a[c])==a[c])
  		j=j-2;
  		else
  		j--;
	  }
}
if(j==1)
  {
  	if(a[j]<0&&a[j]<a[j-1])
  		sum=sum+a[0]-a[j];
  	else
  	    sum=sum+a[0];
  		j--;
	  
  }
  cout<<sum;
}
else if(n==2)
{
	if(k==2)
	cout<<a[0]+a[1];
	else
	cout<<a[0];
}
  else
  cout<<0;
  
	getch();
}
