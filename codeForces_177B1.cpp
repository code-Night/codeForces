#include <iostream>
#include <vector>

using namespace std;

vector <bool> isPrime;
vector <long long>primes ;

void sieve (long long limit){
    isPrime.resize(limit+1);
    fill(isPrime.begin(),isPrime.end(),true);
    isPrime[0]=false ;
    isPrime[1]=false ;
    for(int i=0 ; i*i<=limit ; i++){
        if(isPrime[i]){
            long long j = i*i ;
            while(j <= limit){
                isPrime[j] = false ;
                j += i ;
            }
        }
    }
    for(int i=0 ; i<=limit ; i++){
        if(isPrime[i]){
            primes.push_back(i);

        }
    }
}


int main()
{
    int n;
    cin >> n ;
    int ans = n;
    sieve(n);

    while(!isPrime[n]){

        for(int i=0 ; i<(int)primes.size() ; i++){
            if(n%primes[i] == 0){
                n /= primes[i] ;
                ans += n;
                break ;
            }

        }
    }
    cout << ++ans ;
    return 0;
}
