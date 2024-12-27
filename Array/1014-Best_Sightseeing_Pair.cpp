class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) 
    {
        int n=values.size(),current_mx=values[0]-1,ans=0;
        for(int i=1;i<n;i++)
        {
            ans=max(ans,values[i]+current_mx);
            current_mx=max(current_mx-1,values[i]-1);
        }
        return ans;
    }
};
