#include <iostream>
#include <vector>
#include <set>
#define  MOD 1000000007
using namespace std;

typedef  vector < set<char> > vmc ;
typedef long long int lli ;
int main()
{
    int n,m ;
    cin >> n >> m ;
    vmc ans (m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            char tmp; cin >> tmp ;
            ans[j].insert(tmp);
        }
    }
    lli x = 1 ;
    for(int i=0 ; i<m ; i++){
        x *= ((lli)ans[i].size())%MOD;
        x %= MOD ;
    }
    cout << x ;
    return 0;
}
