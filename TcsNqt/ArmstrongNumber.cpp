#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int calculateArmstrongNumber(vector<string> &v ){
 // 123
 // keep in mind converting into int 

 
}

void input_with_bracket(){

  string s ; 
  getline ( cin , s ) ;
  stringstream ss (s) ;
  vector<string> v ; 
  string temp ; 
  s.erase( remove (s.begin() , s.end() , '[' ), s.end()) ;
  s.erase( remove (s.begin() , s.end() , ']' ), s.end()) ;
  while ( getline(ss , temp , ',')){
    v.push_back(temp) ;
  }
 int num = calculateArmstrongNumber(v) ;
 cout << num << " " << endl ;

}
int main() {
  
// Take the input in two forms with bracket and without bracket 
input_with_bracket();

  return 0;
}

/** 10. Write a program to make the largest number from the digits of the array.
Sample Input
{1, 34, 3, 98, 9, 76, 45, 4}
 */