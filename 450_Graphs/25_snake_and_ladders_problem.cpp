#include<bits/stdc++.h>

typedef pair<int, int> p;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int target = rows*cols;
        int next, x, y;
        
        priority_queue< p, vector<p>, greater<p> > pq;
        vector<bool> vis(target+1, false);
        pq.push( {0,1} );
        vis[1] = true;
        
        while( !pq.empty() ) {
            int steps = pq.top().first/1000 + 1; //increase 1 step
            int curr = pq.top().second;
            pq.pop();
            
            for(int i=1; i<=6; i++) {
                next = curr + i;
                if( vis[next] ) continue;
                vis[next] = true;
                
                x = rows - ((next-1)/cols) -1;
                y = (next-1)%cols;
                if( ((next-1)/cols)%2 ) y = cols - ((next-1)%cols) -1;
                
                if( board[x][y]>0 && board[x][y]<=target ) {
                    next = board[x][y];
                }
                
                if(next==target) return steps;
                pq.push( {steps*1000 + 500-next, next} );
            }
        }
        
        return -1;
    }
};