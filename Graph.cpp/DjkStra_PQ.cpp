#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/* <<<<<<<<<<<<<<<--------------IMPLEMENTATION USING  PRIORITY QUEUE --------------------------->>>>>>>>>>>>>>>*/
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // we will print all the shortest path with the help of Priority Queue
        priority_queue< pair<int, int> , vector<pair<int , int>> , greater<pair<int , int >> > pq ;// distance-> node
        vector<int> distance(V , 1e9) ; // V Nodes and assign each of them with kind of  infinity
        
        pq.push({0 , S}) ;
        distance[S] = 0 ;
        while (!pq.empty()){
            int node = pq.top().second ; 
            int dt = pq.top().first ;
            pq.pop() ;
            for ( auto itr : adj[node]){ // traversing particular node as per the adjacency list 
                int edgeWt = itr[1] ;
                int adjNode = itr[0] ;
                
                if ( dt + edgeWt <  distance[adjNode]){
                    distance[adjNode] = dt + edgeWt ;
                    pq.push({distance[adjNode] , adjNode });
                }
            }
        }
        return distance ;
    }
};
/* THE BASIC DIFFERENCE BETWEEN THE PRIORITY QUEUE AND SET IS , SET CHANGES THE DISTANCE OF THE NODE IF THE DISTANCE IS NOT 1E9 
MEANS NOT THE MAXIMUM IT MEANS IT IS NOT THE FIRST TIME WE ARE UPDATING THE DISTANCE SO IT WILL UPDATE THE DISTANCE ASAP 
WITHOUT CALCULATING FOR IT LIKE IN PRIOIRITY QUEUE IT WILL CALCULATE FOR THE PARTICULAR NODE AND WILL SEE THAT THE DISTANCE IS LESS OR NOT 
AND IT WILL NOT CALCULATE FOR THAT NODE AS IT CONTAINS THE UNIQUE ELEMENTS AND ELEMENTS ARE IN INCREASING ORDER 
*/
int main() {
    int t;
    cin >> t;
    return 0;
}