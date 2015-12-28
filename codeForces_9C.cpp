#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int pow10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000} ;
int main()
{
    long long int n;
    int ans = 0;
    cin >> n ;
    for(int i=1 ; i<(i<<10) ; i++){
        int mask = i;
        int dec = 0 ;
        int pow = 0 ;
        while(mask > 0){
            int dig = mask%2 ;
            mask /=2 ;
            dec = dig*pow10[pow]+dec;
            pow++;
        }
        if(dec > n)
            break ;
        else
            ans++;
    }
    cout << ans;
    return 0;
}
