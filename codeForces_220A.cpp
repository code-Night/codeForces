#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long int> vOriginal (n);
    vector <long long int> vSorted (n);
    for(int i=0 ; i<n ; i++){
        cin >> vOriginal[i];
        vSorted[i] = vOriginal[i];
    }
    sort(vSorted.begin() , vSorted.end());
    int ans =0 ;
    for(int i=0 ; i<n ; i++){
        if(vOriginal[i]!=vSorted[i])
            ans++;
    }
    if(ans > 2)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
