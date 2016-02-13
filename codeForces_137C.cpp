#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int

using namespace std;

struct node {
    lli l;
    lli r;
    bool operator < (node s)const {
        return l < s.l;
    }
};

vector<node> intervals;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n ;
    for(int i=0 ; i<n ; i++){
        node d;
        cin >> d.l >> d.r;
        intervals.push_back(d);
    }
    sort(intervals.begin(),intervals.end());
    int ans = 0 ;
    int maxR = -1;
    for(int i=0 ; i<n ; i++){
        if(intervals[i].r > maxR)
            maxR = intervals[i].r;
        else
            ans++;
    }
    cout << ans;
    return 0;
}
