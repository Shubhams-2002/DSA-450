#include <bits/stdc++.h>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector< pair<int, int> > adj[n];
        for(int i=0; i<flights.size(); i++) {
            adj[ flights[i][0] ].push_back( {flights[i][1], flights[i][2]} );
        }
        
        queue< pair<int, int> > q;
        //using dist array just to avoid getting into cycles as 
        //if node is repeated with higher cost, then it is a waste of time and cycle
        vector<int> dist(n, INT_MAX);
        
        q.push( {src, 0} );
        dist[src] = 0;
        
        int stops = 0;
        while( !q.empty() && stops<=k ) {
            int s = q.size();
            
            while(s) {
                s--;
                
                int u = q.front().first;
                int cost = q.front().second;
                q.pop();
                
                for(auto it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    //use "cost", to compare because nodes in bfs traversal ahead of some 
                    //previously stored node, might get relaxed by another node in 
                    //same level but ahead of it, which means you used an extra stop
                    if(dist[v] > cost + wt ) {
                        dist[v] = cost + wt;
                        q.push( {v, cost+wt} );
                    }
                }
            }
            
            stops++;
        }
        
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};