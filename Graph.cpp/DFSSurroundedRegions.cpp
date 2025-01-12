#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>> &visited)
    {
        visited[row][col] = 1; // lets traverse in all the 4  directions
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int n = mat.size() ; 
        int m = mat[0].size() ;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow, ncol, mat, visited);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){// traversing first col and last col
           if (!visited[i][0] &&  mat[i][0] == 'O'){
             dfs (i ,0 , mat , visited ) ;
           }
           if ( !visited[i][m -1 ] && mat[i][m - 1] == 'O'){
                dfs (i ,m -1  , mat , visited ) ;
           }
        } 
         for (int j = 0; j < m; j++){// traversing first row and last row 
           if (!visited[0][j] && mat[0][j] == 'O'){
             dfs (0 ,j , mat , visited ) ;
           }
           if (!visited[n-1][j] && mat[n- 1 ][j] == 'O'){
              dfs (n - 1  , j , mat , visited ) ;
           }
        }
        
        // And at last the O  which are visited are the ones which cna not change as they are on the boudary or connected with the element which is present in the boundary
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
            {   if ( !visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

int main()
{
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

