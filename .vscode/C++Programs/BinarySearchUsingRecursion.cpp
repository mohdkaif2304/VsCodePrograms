#include <iostream>
using namespace std;

int binarySearch(int arr[] , int start ,int end , int key  ){
if ( start > end ) {
    return -1 ;
}
int mid = start + (end - start  ) /2 ;
 if ( arr[mid] == key ){
     return mid ;
}
 if ( arr[mid ] < key ){
 return binarySearch ( arr , mid + 1 , end , key );
}
else {
return binarySearch ( arr , start  , mid -1  , key );
}
}
int main()
{
    int arr[6] = { 1, 2, 3, 44 , 55  , 66};
    int key = 44 ;
    int start =  0 ;
    int end = 6 ;
    int ans = binarySearch(arr , start , end  , key ) ;
    cout << " Element Found at index " << ans  << endl ;
    return 0 ;
}