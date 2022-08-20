#include<bits/stdc++.h>
class Solution {
    bool dfs(int node, vector<bool>& currDFSvis, vector<bool>& vis, vector<int> adj[]) 
    {
        vis[node] = true;
        currDFSvis[node] = true;
        for(auto it : adj[node]) {
            if( !vis[it] ) {
                if( dfs(it, currDFSvis, vis, adj) ) return true;
            }
            else if(currDFSvis[it]) {
                return true;
            }
        }
        currDFSvis[node] = false;
        
        return false;
    }
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[n+1];
        for(int i=0; i<prerequisites.size(); i++) {
            //check for self loops also, self loops are also cycles and hence return false
            if( prerequisites[i].second == prerequisites[i].first ) return false;
            else adj[ prerequisites[i].second ].push_back( prerequisites[i].first );
        }
        
        vector<bool> vis(n+1, false);
        vector<bool> currDFSvis(n+1, false);
        for(int i=1; i<=n; i++) {
            if( !vis[i] ) {
                if( dfs(i, currDFSvis, vis, adj) ) {
                    return false;
                }
            }
        }
        
        return true;
	}
};