class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum=0,curSum=0;
        long long max=INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i] > max) max=arr[i];
            curSum+=arr[i];
            if(sum<curSum) sum=curSum;
            if(curSum<0) curSum=0;
        }
        if(sum==0) return max;
        return sum;
    }
};