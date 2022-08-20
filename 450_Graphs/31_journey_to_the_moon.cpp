#include <bits/stdc++.h>

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
int find(int i, vector<int> &parent) {
    if(parent[i]==i)  return  i;
    
    return parent[i]=find( parent[i] , parent);
}

void union_set(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        rank[u]++;
        parent[v] = u;
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> parent(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    vector<int> rank(n, 0);
    
    for(int i=0; i<astronaut.size(); i++) {
        union_set( astronaut[i][0], astronaut[i][1], parent, rank);
    }
    
    unordered_map<int, long long> set_cnt;
    for(int i=0; i<n; i++) {
       int p = find(i, parent);
       set_cnt[p]++;
    }
    
    long long ans=n*(n-1)/2;
    for(auto it : set_cnt) {
        ans=ans-it.second*(it.second-1)/2;
    }
    
    return ans;
}