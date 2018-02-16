#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c, int l){
    static long count;
    long x;
    int i;
    static vector <long> a;
x = accumulate(a.begin(), a.end(), 0);

     if(x==n)
     {
         count++;
         a.pop_back();
         return count;
         
     }
    else if(x>n)
     {
        a.pop_back();
        return count;
     }
    for(i=l; i < c.size(); i++)
    {
        a.push_back(c[i]);
    getWays( n,  c, i);
     
    }
     a.pop_back();
    return count;
}

int main() {
    long n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
     cout<<getWays(n, c, 0);
    return 0;
}
