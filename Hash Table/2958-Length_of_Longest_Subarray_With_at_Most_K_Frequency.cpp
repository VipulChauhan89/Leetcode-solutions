class Solution {
public:
    int maxSubarrayLength(vector<int> &nums,int k)
    {
        int n=nums.size(),count=0;
        unordered_map<int,int> freq;
        freq.reserve(n);
        for(int l=0,r=0;r<n;r++)
        {
            int x=nums[r];
            auto it=freq.find(x);
            int &f=(it==freq.end())?freq[x]=1:++(it->second);
            while(f>k)
            {
                freq[nums[l++]]--;
            }
            count=max(count,r-l+1);
        }
        return count;
    }
};
