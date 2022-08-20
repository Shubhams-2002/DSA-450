#include <bits/stdc++.h>
void topo_dfs(int node, vector<bool>& vis, vector< pair<int,int> > adj[], stack<int>& st) 
{
    vis[node] = true;
    
    for(auto it : adj[node]) {
        if( !vis[it.first] ) {
            topo_dfs(it.first, vis, adj, st);
        }
    }
    st.push(node);
}
vector<int> findMaxDistances(int v, int src, vector<vector<int>> &edges) {
	/*
        Parameters of this function are -:
        'n': Number of nodes in given directed graph.
        'src': Source node.
        'edges': list of all edges, such that the 'ith edge is a 
                 directed edge from 'edges[i][0]' to 'edges[i][1]' and have weight 'edges[i][2]'. 
    */

    vector<int> dist(v, INT_MIN);
    dist[src] = 0;
    stack<int> st;
    
    vector< pair<int,int> > adj[v];
    for(int i=0; i<edges.size(); i++) {
        adj[ edges[i][0] ].push_back( {edges[i][1], edges[i][2]} );
    }
    
    vector<bool> vis(v, false);
    for(int i=0; i<v; i++) {
        if( !vis[i] ) {
            topo_dfs(i, vis, adj, st);
        }
    }
    
    while( !st.empty() ) {
        int u = st.top();
        st.pop();

        if(dist[u] == INT_MIN) continue;
        //if u is INT_MIN, then its not reachable and 
        //hence no need to relax its adj nodes
        for(auto it : adj[u]) {
            int v = it.first;
            int wt= it.second;
            
            if( dist[v] < dist[u] + wt ) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    for(int i=0; i<v; i++) {
        if( dist[i] == INT_MIN ) dist[i] = -1;
    }
    
    return dist;
}