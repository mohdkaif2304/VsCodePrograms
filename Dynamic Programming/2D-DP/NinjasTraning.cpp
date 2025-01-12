#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// Function for Memoization
int solve(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
{
  if (n == 0)
  {
    int maxi = 0;
    for (int tasks = 0; tasks < 3; tasks++)
    {
      if (tasks != last)
      {
        maxi = max(maxi, points[0][tasks]);
      }
    }
    return maxi;
  }
  if (dp[n][last] != -1)
  {
    return dp[n][last];
  }
  int maxi = 0;
  for (int tasks = 0; tasks < 3; tasks++)
  {
    if (tasks != last)
    { // firstly last is 3 it means we can take any elements from the 3 elements and then we past last as 0 , 1 , 2 in first
      // iteration it will become 0 it means in n-1 row we can't take the 0th coloumn element so we have to skip that column and move on to next column
      int point = points[n][tasks] + solve(n - 1, points, tasks, dp);
      maxi = max(maxi, point);
    }
  }
  return dp[n][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, -1)); // in 4th coloumn we are putting that wchich row or col is we have chosen and we are placing that in col 4 so that
                                                 // we will not go in that upper index because same col we cant take that's why what row or col we are chosing we are taking care of that
  return solve(n - 1, points, 3, dp);
}

// This is using Tabulation method
int ninjaTrainingUsingTabulation(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, 0));
  // Base case
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(dp[0][0], max(dp[0][1], (dp[0][2]))); // This is for the first case you will start choosing from that col which is the maximum of all the three
// this last case will might be the case for a single day then you have to return the max of all those  three cases.
  for (int i = 1; i < n; i++)
  { // now  the loop wil run from 1 till n describing the row
    for (int last = 0; last < 4; last++)
    {
      for (int tasks = 0; tasks < 3; tasks++)
      { // for coloumn as in the first iteration the last and the col will be equal so it will
        // go in the second or third col and whichever is the maximum it will take that
        if (tasks != last)
        {
          int point = points[i][tasks] + dp[i - 1][tasks]; // here we are storing in the dp itself that's why not making any recursive call .. rule of tabulaation
          dp[i][last] = max(dp[i][last], point);           // as tabullation is a bottom up approach  so we start with base case.
        }
      }
    }
  }
  return dp[n - 1][3]; // we will return the last row and last col because our maximum get stored in that  cell.
}
int main()
{
  return 0;
}

/*----------------------------------------------- MOST IMPORTANT -------------------------------------------------------------*/

//// We will pass motly in dp(n+ 1) n is for the size and 0 is for the base case if ou include the base case then you can pass as dp(n)  this is just simple thing 
// don' think about it more it is simple 



// ------------------------------GOLDEN RULE ---------------------------------// 
// IF THERE IS PREVIOUS ROW AND PREVIOUS COLOUMN THEN WE CAN DEFINITELY SPACE OPTIMIZE IT 

/// SPACE OPTIMIZATION 
// the general idea is as we know we dont need to store the entire table we just need the max of two row and then if we are going to calculate for the third row 
// then we dont need the first row hence we can optimize the space by taking this into consideration 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev (4 , 0) ;
    // Base case 
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0] , max(points[0][1] ,(points[0][2]))) ;// this col is used for storing the max of those 3 

    for (int i = 1 ; i < n ; i++){ // now  the loop wil run from 1 till n 
    vector<int> temp(4, 0) ;
      for (int last = 0 ; last < 4 ; last++){
        temp[last] = 0 ;
        for (int tasks = 0 ; tasks < 3 ; tasks++){
           if (tasks != last ){
              temp[last] = max (temp[last] ,  points[i][tasks] + prev[tasks] ) ; 
            }
        }
      }
      prev = temp ; // here you are just replacing so that you can use that vector for calculting the remaining rows  
    }
    return prev[3] ;
}