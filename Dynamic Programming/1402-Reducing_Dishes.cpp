class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n=satisfaction.size();
        int prefixSum=0,maxSum=0;
        for(int i=n-1;i>=0 && satisfaction[i]>-prefixSum;i--) 
        {
            prefixSum+=satisfaction[i];
            maxSum+=prefixSum;
        }
        return maxSum;
    }
};
