#include<iostream>
#include<math.h>
using namespace std;
int count(int n)
{
	int c=0;
	while(n>0)
	{
		n=n/10;
		c++;
	}
	return c;
}
int shift(int n)
{
	return (n%10)*pow(10,count(n)-1)+n/10;
}
int rev(int n)
{
	int k=pow(10,count(n)-1),s=0;
	while(n>0)
	{
		s=(n%10)*k+s;
		k=k/10;
		n=n/10;
	}
	return s;
}
int main()
{
	cout<<rev(1234567)<<endl<<shift(1234);
	return 0;
}

