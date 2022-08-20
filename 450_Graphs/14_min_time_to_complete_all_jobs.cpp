#include<bits/stdc++.h>
class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int> adj[n+1];
            vector<int> indeg(n+1, 0);
            for(int i=0; i<edges.size(); i++) {
                adj[ edges[i][0] ].push_back( edges[i][1] );
                indeg[ edges[i][1] ]++;
            }
            
            queue<int> q;
            for(int i=1; i<=n; i++) {
                if(indeg[i]==0) {
                    q.push(i);
                }
            }
            
            vector<int> ans(n);
            int timer=1;
            while( !q.empty() ) {
                int k = q.size();
                while(k) {
                    k--;
                    
                    int u = q.front();
                    q.pop();
                    ans[u-1] = timer;
                    
                    
                    for(int v : adj[u]) {
                        indeg[v]--;
                        if(indeg[v]==0) {
                            q.push(v);
                        }
                    }
                }
                
                timer++;
            }
            
            return ans;
        }
};