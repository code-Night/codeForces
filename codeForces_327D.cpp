#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;
int factor = 0;
struct Event{
    char type;
    int x;
    int y;
};
int n,m ;
vector<Event>sequence ;
vector< Event > B ;
vector< Event > DR ;
char grid [505][505] ;

bool visited[505][505] ;
int dx[] = {1,-1,0,0} ;
int dy[] = {0,0,1,-1} ;

bool valid(int x,int y){
    if(x<1 || x>n)
        return false ;
    if(y<1 || y>m)
        return false ;
    return true ;
}
void build_component(){



}
void dfs(int x,int y){
    stack< pair<int,int> > srch ;
    srch.push(make_pair(x,y));
    while(!srch.empty()){
        pair<int,int> curr = srch.top();srch.pop();
        int x = curr.first,y = curr.second ;
        if(!visited[x][y]){
            Event e;
            e.type = 'B' ;
            e.x = x;
            e.y = y;
            B.push_back(e);
            e.type='R';
            DR.push_back(e);
            e.type='D';
            DR.push_back(e);

            visited[x][y]=true ;
            for(int i=0 ; i<4 ; i++){
                int nxtX = x+dx[i],nxtY = y+dy[i];
                if( !visited[nxtX][nxtY] && valid(nxtX,nxtY) && grid[nxtX][nxtY]=='.'){
                    srch.push(make_pair(nxtX,nxtY));
                }
            }
        }
    }
}
void connected_component(){
    int first = 0;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                dfs(i,j);
                if((int)DR.size ()> first){
                    DR[first].type = 'f';
                    DR[first+1].type = 'f';
                    factor -= 2 ;
                    first = DR.size() ;
                }
            }
        }
    }
}


int main()
{
    cin >> n >> m ;
    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<m+1 ; j++){
            visited[i][j] = false ;
            char x;cin >> x;
            grid[i][j] = x ;
        }
    }
    connected_component() ;
    cout << (int)(B.size()+DR.size())+factor << endl;
    for(int i=0 ; i<(int)B.size() ; i++)
        printf("%c %d %d\n",B[i].type ,B[i].x ,B[i].y);
       // cout << B[i].type << " " << B[i].x << " " << B[i].y << endl ;
    for(int i=(int)DR.size()-1 ; i>=0 ; i--){
        if(DR[i].type!='f')
            printf("%c %d %d\n",DR[i].type ,DR[i].x ,DR[i].y );
           // cout << DR[i].type << " " << DR[i].x << " " << DR[i].y << endl ;

    }
    return 0;
}
