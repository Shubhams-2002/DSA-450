class Solution {
public:
    bool binarySearch(vector<int> a, int low, int high, int target){
        int mid=(low+high)/2;
        if(low>high) return false;
        else{
            if(a[mid]==target) return true;
            else if(a[mid]<target) return binarySearch(a,0,mid-1, target);
            else return binarySearch(a,mid+1,high, target);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans=false;
        int n=matrix.size();
        int m=matrix[0].size();
        // int i;
        // if(n==1){return binarySearch(matrix[0],0,m-1, target);}
        // for(i=0; i<n-1; i++){
        //     if(target<matrix[i+1][0]) break;
        // }
        // ans=binarySearch(matrix[i],0,m-1, target);
        // return ans;
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid/m][mid%m]==target){
                ans=true;
                break;
            }
            else if(matrix[mid/m][mid%m]<target) low=mid+1;
            else  high=mid-1;
        }
        return ans;
    }
};