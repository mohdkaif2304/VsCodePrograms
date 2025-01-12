#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int  maxfreq(int * a , int size ){

  unordered_map<int , int > ans ; 

   int max = 0 , maxElement = 0; 
  for (int i = 0; i < size; i++)
  {
    ans[a[i]] ++ ;

    if ( ans[a[i]] > max ){
         max = ans[a[i]] ;
    }
  }

for (int i = 0; i < size; i++)
{
  /* code */
  if ( ans[a[i]] == max){
   maxElement = a[i];
    break ;
  }

}

  return maxElement;
  
}

int main()
{
  int a [] = { 2 , 12 , 2 , 11 , 12 , 2 , 1 , 2 , 2 , 11 ,  12 , 2  , 6 };
  int ans = maxfreq( a , 13 ); 

  cout << ans << endl ;

 return 0;
}




//   You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
// Input Format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.

// Output Format :
// The first and only line of output contains most frequent element in the given array.

// Constraints:
// 0 <= N <= 10^8
// Time Limit: 1 sec

// Sample Input 1 :
// 13
// 2 12 2 11 12 2 1 2 2 11 12 2 6

// Sample Output 1 :
// 2
