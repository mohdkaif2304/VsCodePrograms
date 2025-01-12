#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main() {
   int V , E ; 
   cin >> V >>  E ; 
   vector<vector<int>> adj[V] ;// Contains array of vector of vector --  (2, 3) -> t1 vector
   int i = 0 ;                 //                    {1->(2,3)} vector of vector as it is stored in array of vector 
   while (i++ < E ){
    int u , v , wt ;
    vector<int> t1 , t2 ; 
    cin >> u >> v >> wt;
    t1.push_back(u);
    t1.push_back(wt) ;
    adj[v].push_back(t2);

    t2.push_back(v);
    t2.push_back(wt);
    adj[u].push_back(t2);
   }

    return 0;
}