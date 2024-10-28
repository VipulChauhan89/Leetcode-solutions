class Solution {
public:
    int longestSquareStreak(vector<int> &nums) 
    {
        unordered_map<int,int>m;
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(auto i:nums) 
        {
            int sq=sqrt(i);
            if(sq*sq==i && m.find(sq)!=m.end()) 
            {
                m[i]=m[sq]+1;
                ans=max(ans,m[i]);
            } 
            else
            {
                m[i]=1;
            } 
        }
        return ans;
    }
};
