#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m ;
    cin >> n >> m ;
    bool r[n];
    memset(r,true,sizeof (r));
    bool c[n];
    memset(c,true,sizeof (c));
    r[n-1] = r[0] = false ;
    c[0] = c[n-1] = false ;
    for(int i=0 ; i<m ; i++){
        int rr,cc;
        cin >> rr >> cc ;
        r[rr-1]=false;
        c[cc-1]=false;
    }
    int ans = 0 ;
    for(int i=0 ; i<n ; i++){
        if(r[i])
            ans++;
        if(c[i])
            ans++;
        if(n%2==1 && r[i] && c[i] && (i+1) == n/2+1)
            ans--;
    }
    cout << ans ;
    return 0;
}
