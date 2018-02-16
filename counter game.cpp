#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long int pr(unsigned long long int base,unsigned long long int exponent)
{
	unsigned long long int result = 1;
	while (exponent != 0) {
        result *= base;
        --exponent;
    }

    
    return result;
}
unsigned long long int pm(unsigned long long int n)
{
	int i;
	for(i=1;i<=63;i++)
	{
		if(n<pr(2,i))
		{
		
		return n-pr(2,i-1);
	}
	}
}
unsigned long long int p(unsigned long long int n)
{
	int i;
	for(i=1;i<=63;i++)
	{
		if(n==pr(2,i))
		return n/2;
		
	}
	return pm(n);
}
int main() {
       int t,i;
       cin>>t;
       unsigned long long int n[t],c[t];
       for(i=0;i<t;i++)
       cin>>n[i];
       for(i=0;i<t;i++)
       {
       	c[i]=0;
       	while(n[i]>1)
       	{
       		n[i]=p(n[i]);
       		c[i]++;
		   }
       	if(c[i]%2==0)
       	cout<<"Richard"<<endl;
       	else
       	cout<<"Louise"<<endl;
   }
   
   
   
    return 0;
}

