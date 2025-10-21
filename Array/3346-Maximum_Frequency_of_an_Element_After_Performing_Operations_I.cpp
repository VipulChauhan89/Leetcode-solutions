class Solution {
public:
    int maxFrequency(vector<int> &nums,int k,int numOperations)
    {
        int mx=*max_element(nums.begin(),nums.end()),mxx=1;
        vector<int> m(mx+1,0),prefix(mx+2,0);
        for(auto &i:nums)
        {
            m[i]++;
        }
        for(int i=1;i<mx+2;i++)
        {
            prefix[i]=m[i-1]+prefix[i-1];
        }
        for(int i=0;i<mx+1;i++)
        {
            int l=max(i-k,0),r=min(i+k,mx),ne=prefix[r+1]-prefix[l],no=m[i],nv=min(numOperations,ne-no);
            mxx=max(mxx,nv+no);
        }
        return mxx;
    }
};
