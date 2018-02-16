#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int l,r,i,j,max=0,k;
	cin>>l>>r; 
	for(i=l;i<=r;i++)
	{
		for(j=i;j<=r;j++)
		{
			k=i^j;
			if(k>max)
			max=i^j;
		}
	}
	cout<<max;
    return 0;
}

