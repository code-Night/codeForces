#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int M;
vector<int> a;
vector <int> ans;
void solve(int m,int l,int r,int last){

    int curr = -1;

    if(m > M){
        return  ;
    }
    for(int i=0 ; i<(int)a.size() ; i++){
        if(l+a[i] > r && a[i]!= last){
            curr = a[i];
            ans.push_back(curr);
            solve(m+1,r,l+curr,curr);
            if(ans.size() == M)
                return ;
            ans.pop_back();
        }
    }
    return  ;
}
int main()
{
    string mask;
    cin >> mask;
    cin >> M ;
    for(int i=0 ; i<(int)mask.size() ; i++){
        if(mask.at(i)-'0' == 1)
            a.push_back(i+1);
    }
    solve(1,0,0,0);
    if((int)ans.size() >= M){
        cout << "YES" << endl ;
        for(int i=0 ; i<ans.size() ; i++)
            cout << ans[i] << " ";
    }
    else{
        cout << "NO" << endl ;
    }
    return 0;
}
