#include <iostream>
#include <vector>
using namespace std;

vector < vector<int> > graph (5+1) ;

int main()
{
    int k;
    cin >> k ;
    for(int i=0 ; i<k ; i++){
        int x,y;cin >> x >> y ;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool win = false ;
    for(int i=1 ; i<6 ; i++){
        if(graph[i].size() >=3 || graph[i].size()<=1){
            win = true ;
            break ;
        }
    }
    if(win)
        cout << "WIN" ;
    else
        cout << "FAIL" ;
    return 0;
}
