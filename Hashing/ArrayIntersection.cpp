// User function template for C++
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        
        unordered_set<int> s ;
        
        for (int i = 0 ; i<n ; i++){
            s.insert(a[i]) ;
        }
        int count = 0;
        for (int i = 0 ; i< m ; i++){
            if (s.find(b[i]) != s.end()){
                count ++ ;
                s.erase(b[i]);
    
            } 
        }
      return count ;
    }
};
int main()
{
    int t; 
    cin >> t; 
    while (t--){
int n , m ;
cin>> n >> m  ; 
int a[n] , b[m] ;

for (int i = 0; i < n; i++)
{
    /* code */
    cin >> a[i] ;
}

for (int i = 0; i < m; i++)
{
    /* code */
    cin >> b[i] ;
}
Solution ob;
cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl ;
    }

 return 0;
}