class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> a;
        sort(intervals.begin(), intervals.end());
        if(n==0) return a;
        a.push_back(intervals[0]);
        int j=0;
        for(int i=1; i<n; i++){
            if(a[j][1] >= intervals[i][0]) {
                a[j][1] = max(a[j][1], intervals[i][1]);
            }
            else{
                a.push_back( intervals[i]);
                j++;
            }
        }
        return a;
    }
};