class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size();
        unordered_map<int,int> freq;
        int minVal=INT_MAX;
        for(int i=0;i<n;i++)
        {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
            minVal=min({minVal,basket1[i],basket2[i]});
        }
        vector<int> extras;
        for(auto &[val,count]:freq)
        {
            if(count%2!=0)
            {
                return -1;
            } 
            for(int i=0;i<abs(count)/2;i++)
            {
                extras.push_back(val);
            }
        }
        sort(extras.begin(),extras.end());
        long long cost=0;
        int m=extras.size();
        for(int i=0;i<m/2;i++)
        {
            cost+=min(extras[i],2*minVal);
        }
        return cost;
    }
};
