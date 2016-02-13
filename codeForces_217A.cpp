#include <iostream>
#include <vector>
using namespace std;
int n;
vector < vector<int> >graph ;
vector <bool> visited;
int ans = 0 ;

void dfs(int curr){
    visited[curr]=true ;
    for(int i=0 ; i<(int)graph[curr].size() ; i++){
        int nxt = graph[curr][i] ;
        if(!visited[nxt])
            dfs(nxt);
    }
}

int main()
{
    cin >> n ;
    graph.resize(n);
    visited.resize(n);
    visited.assign(n,false);
    vector <pair<int,int> > points ;
    for(int i=0 ; i<n ; i++){
        int x,y ;
        cin >> x >> y ;
        points.push_back(make_pair(x,y));
    }
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(points[i].first == points[j].first || points[i].second==points[j].second){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans-1 ;
    return 0;
}
