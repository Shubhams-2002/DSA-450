class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int up=0,down=r-1,left=0,right=c-1;
        vector<int> ans;
        while(up<=down && left<=right){
            for(int j=left; j<=right; j++){
                ans.push_back(matrix[up][j]);
            }
            up++;
            for(int i=up; i<=down; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(up<=down){ //you need to recheck this condition or else you will be printing inner no.s again
                for(int j=right; j>=left; j--){
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }
            if(left<=right){
                for(int i=down; i>=up; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};