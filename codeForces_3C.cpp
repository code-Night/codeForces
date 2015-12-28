#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int countX = 0 , count0 = 0;
    char grid [3][3]  ;
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> grid[i][j] ;
            if(grid[i][j] == 'X')
                countX++;
            else if(grid[i][j] == '0')
                count0++;
        }
    }
    if(fabs(countX-count0) >= 2)
        cout << "illegal" << endl ;
    else{

    }
    return 0;
}
