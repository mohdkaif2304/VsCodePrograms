#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    unordered_map<int, int> prefixSum; // prefix sum as key, index as value
    int maxLength = 0;
    int sum = 0;
    int maxi = 0 ;
    int n = 8 ;
    int arr[n] = {15,-2,2,-8,1,7,10,23};
     
for( int i = 0; i < n ; i++){

    
prefixSum[sum] = i;
cout << prefixSum[sum] ;
}

    // for( int i = 0; i < n ; i++){
        
    //     sum += arr[i] ;
    //     if ( sum == 0){
    //         maxi = i + 1 ;
    //     }
        
    //     if (prefixSum.find(sum) != prefixSum.end()){
    //         maxi = max  (maxi , i -  prefixSum[sum] )  ;
    //     }
        
    //     else {
    //         prefixSum[sum] = i ;
    //     }
    // }
    
 return 0;
}