#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n ;
    vector <long long> p ;
    vector <long long> cost ;
    vector <long long> cnt(5,0) ;
    for(int i=0 ; i<n ; i++){
        long long x;cin >> x;
        p.push_back(x);
    }
    for(int i=0 ; i<5 ; i++){
        long long x;cin >> x;
        cost.push_back(x);
    }
    long long rem = 0;
    for(int i=0 ; i < n; i++){
        rem += p[i];
        for(int j=4 ; j >= 0 ; j--){
            if(rem >= cost[j]){
                //cout << cost[j] << endl ;
                cnt[j] += rem/cost[j];
                rem = rem%cost[j];
                if(rem == 0)
                    break;
            }
        }
    }
    for(int i=0 ; i<5 ; i++){
        cout << cnt[i] << " ";
    }
    cout << endl << rem;
    return 0;
}
