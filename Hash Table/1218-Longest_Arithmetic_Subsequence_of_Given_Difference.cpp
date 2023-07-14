class Solution {
public:
    int longestSubsequence(vector<int> &arr,int difference) 
    {
        unordered_map<int,int> m;
        int mx=0;
        for(auto i:arr)
        {
            m[i]=m[i-difference]+1;
            mx=max(mx,m[i]);
        }
        return mx;
    }
};
