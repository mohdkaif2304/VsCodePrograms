#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//<<<<<<<<<<<<<----------- Prerequisites Task -------------->>>>>>>
class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(N, 0);
        vector<int> adj[N]; // Declaration of array of vectors
        for (auto& pre : prerequisites) {
            adj[pre.first].push_back(pre.second); // as we have given only two values so we can easily access by doing .first and .second as it is vector of pair  
            indegree[pre.second]++; // how we can also calculate the indegree lets see 
        }
        
       // Calculate indegrees manually
        // for (int i = 0; i < P; i++) {
        //     adj[prerequisites[i].first].push_back(prerequisites[i].second);
        //     indegree[prerequisites[i].second]++;
        // }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int i = 0 ; i < adj[node].size() ; i++) {
                int curr = adj[node][i] ; // storing the elements which are present in the particular vector 
                indegree[curr]--;
                if (indegree[curr] == 0) {
                    q.push(curr);
                }
            }
        }
        
        return count == N; // if the total vertices are equal this means that the cycle is not there so we return true 
    }
};

/*


class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(N, 0);
        vector<vector<int>> adj(N);
        
        for (auto& pre : prerequisites) {
            adj[pre.first].push_back(pre.second);
            indegree[pre.second]++;
        }
        
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        return count == N;
    }
};


*/
/** <<<<<<<<<<<---------------- DETECT A CYCLE IN A DIRECTED GRAPH --------------->>>>>>>>>*/
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V] = {0} ; 
	   // for ( int i = 0 ; i < V ; i++){// For calculating the indegree of the nodes 
	   //     for ( auto itr : adj[i]){// taversing in the list 
	   //         indegree[itr]++ ;
	   //     }
	   // }
	    for (int i = 0 ; i < V ; i++){
	        for ( int itr = 0 ; itr < adj[i].size() ; itr++){
	            indegree[itr]++ ;
	        }
	    }
	    queue<int> q ; 
	    for (int i = 0 ; i < V ; i++){
	        if ( indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int count = 0 ; 
	    while ( !q.empty()){
	        int node = q.front() ;
	        count++ ;
	        q.pop() ; 
	        
	        for ( auto itr : adj[node]){
	            indegree[itr]-- ;
	            if (indegree[itr] == 0 )q.push(itr) ;
	        }
	    }
	    
	    return count != V ;
    }
};
int main() {
    int t;
    cin >> t;
    return 0;
}