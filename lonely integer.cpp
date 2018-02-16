#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,a[100],i,j,k,l;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        {
        k=0;
       for(j=i+1;j<n;j++)
           {
           if(a[j]==a[i])
               {
               k=1;
               break;
           }
       }
       for(l=0;l<i;l++)
       {
       	if(a[l]==a[i])
               {
               k=1;
               break;
           }
	   }
        if(k==0)
            {
            cout<<a[i];
            break;
        }
    }
    return 0;
}

