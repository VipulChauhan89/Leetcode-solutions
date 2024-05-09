class Solution {
public:
    long long maximumHappinessSum(vector<int> &happiness,int k) 
    {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long ans=0;
        int i=0;
        while(k--)
        {
            ans+=max(happiness[i]-i,0);
            i++;
        }
        return ans;
    }
};
