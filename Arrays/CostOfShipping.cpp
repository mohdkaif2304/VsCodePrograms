#include<bits/stdc++.h>
using namespace std ; 

int main (){
 int N ; 
 cin >> N ; 
 vector<string> arr(N) ;
 unordered_map<string , int > mpp ;
 for ( int i = 0 ; i < N ; i++ ){
    string ss ;
    cin >> ss;
    mpp[ss]++ ;// incrementing the count at the same time 
 }
   int mini = 0 ;
   for ( auto itr : mpp ) {
   string key = itr.first ; 
   int value = itr.second ; 

   string temp = key.substr(0, key.size() - 1 );// Number 
   string opposite ;
   if ( key[key.size() - 1] == 'L')opposite = temp + 'R' ;
   if ( key[key.size() - 1] == 'R')opposite = temp + 'L' ;  
    if ( mpp.find(opposite) != mpp.end()){ 
    mini += min ( value , mpp[key] ); // store the min of the both string and you are counting from both the sides so divide it by 2
   }
   
  }
  cout << mini / 2  << endl ;
  return  0 ; // Final answer 
}