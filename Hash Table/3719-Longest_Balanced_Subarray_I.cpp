class Solution {
public:
    int longestBalanced(vector<int> &nums)
    {
        int n=nums.size(),ans=0;
        unordered_map<int, short> freq;
        freq.reserve(n);
        for(int l=0;l<n;l++)
        {
            int cnt[2]={0};
            freq.clear();
            for(int r=l;r<n;r++)
            {
                int x=nums[r];
                if(++freq[x]==1)
                {
                    cnt[x&1]++;
                }
                if(cnt[0]==cnt[1])
                {
                    ans=max(ans,r-l+1);
                }
            }
        }
        return ans;
    }
};
