#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() { 
   long long n , i , total , attack ;
   cin >> n ;
   for ( i = 1 ; i <= n ; i++ ){
    total = ((i*i )* ((i*i) - 1)) / 2 ;
    attack = 4*(i-1)*(i-2) ; 
    cout << total - attack << endl;
   }
    return 0;
}