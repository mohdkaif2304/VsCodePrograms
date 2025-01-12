#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
   long long  n = 0   ; 
   cin >> n ; 
   long long total = 0  ;
   total =  (n * ( n + 1 ) )/ 2 ;
   if ( total % 2 == 1 ){
    cout << "NO" << endl ;
   }
   else { // proceed if even 
   cout << "YES" << endl ;
    vector<long long> arr1 , arr2 ; 
    long long target = total / 2 ;
    while( n > 0){
        if ( target >= n){
          target -=  n ;
          arr1.push_back(n) ;
        }else { 
            arr2.push_back(n) ;
        }
        n --;
    }
    cout << arr1.size() << endl ;
    for ( auto itr : arr1){
        cout << itr << " " ;
    }
    cout << endl ;
    cout << arr2.size() << endl ;
    for( auto itr : arr2){
        cout << itr << " " ;
    }
   }


    return 0;
}