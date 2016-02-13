#include <iostream>

using namespace std;
int n,m;

int main()
{

    cin >> n >> m ;
    cout << min(n,m)+1 << endl ;
    int x=min(n,m) , y=0 ;
    for(int i=0 ; i<min(n,m)+1 ; i++){
        cout << x-- << " " << y++ << endl ;
    }
    return 0;
}
