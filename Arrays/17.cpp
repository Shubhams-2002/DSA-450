class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int diff[n-1];
        vector<int> dec;
        if(n>1 && prices[0]<prices[1]) dec.push_back(0);
        vector<int> inc;
        
        for(int i=0; i<n-1; i++){
            diff[i]=prices[i+1]-prices[i];
            if(diff[i]<0) dec.push_back(i+1);
            else inc.push_back(i+1);
        }
        if(inc.size()==0) return 0;
        int max1=0;
        int i=0,j=0;
        while(dec[i]!=n-1 || inc[j]!=n-1){
            max
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                max1=max(max1, (prices[j]-prices[i]));
            }
        }
        return max1;
    }
};