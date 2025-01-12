#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/** <<<<<--------This is the Solution of the bipartite graph using dfs and bfs ------------>>>>> */

class Solution { //  Try to make a slght recursion tree and try to visulaize that why there is  a need of paasing the color in the paramter 
// as you neeed to assign the alternate color to the nodes 
public:
bool dfs (int node, int col ,  vector<int>adj[] , int color[] ){
    
    color[node] = col ;
	        for (auto itr : adj[node]){
	            if (color[itr] == -1 ){ // Not visited
	                if (dfs(itr ,!col , adj , color ) ==  false ) return false  ;
	            }else if (color[itr] == col){
	                    return false ;
	            }
	        }
	    return true ;
}
	bool isBipartite(int V, vector<int>adj[]){
	    
	    int color[V] ; // Make the color array for keeping track of 
	    for ( int i = 0 ; i < V ; i++)color[i] = -1 ; // Mark everybody as - 1
	    
	    for ( int i = 0 ; i < V ; i++){ // checking for all the components 
	        if ( color[i] == -1){// if not visited 
	           if(dfs(i , 0,  adj , color ) == false ) return false ;
	        }
	    }
	    
	    return true ;
	}

};
 class Solution1 {
public:

bool bfs (int start ,  vector<int>adj[] , int color[] , queue<int> q ){
    
    q.push(start) ; 
    color[start] = 0 ;
    while ( !q.empty()){
	        int node = q.front() ; 
	        q.pop() ; 
	        
	        for (auto itr : adj[node]){
	            if (color[itr] == -1 ){ // not visited 
	                color[itr] = !color[node];
	                q.push(itr) ;
	            }else {
	                // visited so check if the color is equal if yes then return false 
	                if ( color[itr] == color[node]){
	                    return false ;
	                }
	            }
	        }
	        
	    }
	    return true ;
}
	bool isBipartite(int V, vector<int>adj[]){
	    
	    int color[V] ; // Make the color array for keeping track of 
	    for ( int i = 0 ; i < V ; i++)color[i] = -1 ; // Mark everybody as - 1 
	    queue<int> q ; 
	   
	    for ( int i = 0 ; i < V ; i++){
	        if ( color[i] == -1){
	           if(bfs(i , adj , color , q) == false ) return false ;
	        }
	    }
	    
	    return true ;
	}

};
int main() {
    int t;
    cin >> t;
    return 0;
}