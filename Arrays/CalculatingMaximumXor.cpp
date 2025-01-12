// Calculating the max XOR of all the elements ...

#include<bits/stdc++.h>
using namespace std; 

int findingSubset ( vector<int> & arr , int N  ){

int length = pow ( 2 , N );
vector<int> ans ; 
int maxi = INT_MIN ;
int res = 0 ;
int count = 0 ;
for (  int num = 0 ; num < length ; num++) {
res = 0 ; //  resetting ans  always 
count = 0 ;
for ( int i = 0 ; i < N ; i ++ ){
  if (num & 1 << i  && count < N / 2 ) {
    res  =  res ^ arr[i];
    count ++ ;
   }
}
maxi = max(maxi , res) ;
}

return maxi ;

}

int main (){

int N ; 
cin >> N ; 
vector<int> arr(N) ;
for ( int i = 0 ; i < N ;i++){
cin >> arr[i] ; 
}

int ans =  findingSubset( arr , N ) ;
cout << ans << endl ;

return 0 ;
}


/**
string s ; 
getline(cin, s ) ;
vector<int> ans ; 
int temp ; 

s.erase (s.remove( s.begin() , s.end() , '[') , s.end());
s.erase (s.remove( s.begin() , s.end() , ']') , s.end());
stringstream ss(s);

while ( getline (ss , temp , ',') ){
ans.push_back(stoi(temp));
}
**/