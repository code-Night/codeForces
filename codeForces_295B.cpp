#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
#include <stack>
#define oo 1e9
using namespace std;

vector <vector <long long> >adj_mat ;
stack <long long>  ans ;
vector <long long> rankList ;
int n;
void floyd (int x){
    for(int k=0 ; k<x ; k++){
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++){
                int intermediate = rankList[x-k-1] ;
                adj_mat[i][j] = min(adj_mat[i][j],adj_mat[i][intermediate]+adj_mat[intermediate][j]);
            }
        long long sum = 0 ;
        int last = x-1 ;
        int first = x-k-1 ;
        for(int i=first ; i < x ; i++){
            for(int j=first ; j < x ; j++)
               sum += adj_mat[rankList[i]][rankList[j]]  ;

        }

       ans.push(sum);
    }
}
void init(){
    adj_mat.resize(n+1);
    for(int i=1 ; i<=n ; i++){
        adj_mat[i].resize(n+1);
    }
}

int main()
{
    freopen("input.txt","r",stdin);

    cin >> n ;
    init();
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n  ; j++){
            int temp ;
            cin >> temp ;
            adj_mat[i][j]  = temp ;
        }
    }
    for(int i=0 ; i<n ; i++){
        int y;cin >> y;
        rankList.push_back(y);
    }
    floyd(n);
    while(!ans.empty())
        cout << ans.top() << " " , ans.pop() ;

    return 0;
}
