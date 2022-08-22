#include<bits/stdc++.h>
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int di[8] = {1, -1, 2, -2,  1, -1, 2, -2};
	    int dj[8] = {2,  2, 1, -1, -2, -2, -1, 1};
	    
	    pair<int, int> start = { KnightPos[0], KnightPos[1] };
	    pair<int, int> tar = { TargetPos[0], TargetPos[1] };
	    
	    queue < pair<int, int> > q;
	    q.push(start);
	    
	    vector<vector<bool>> vis(N+1, vector<bool>(N+1, 0));
	    vis[start.first][start.second] = true;
	    
	    int steps = 0;
	    while( !q.empty() ) {
	        int k = q.size();
    	    while(k){
    	        pair<int, int> curr = q.front();
    	        q.pop();
    	        
    	        if(curr == tar) return steps;
    	        
    	        for(int i=0; i<8; i++) {
    	            int ni = curr.first + di[i];
    	            int nj = curr.second + dj[i];
    	            if( ni>=1 && ni<=N && nj>=1 && nj<=N && !vis[ni][nj] ) {
    	                vis[ni][nj] = 1;
    	                q.push({ni,nj});
    	            }
    	        }
    	        k--;
    	    }
    	    
    	    steps++;
	    }
	    
	    return 3;
	}
};