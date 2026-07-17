class Solution {
public:
    vector<int> gcdValues(vector<int> &nums,vector<long long> &queries)
    {
        int m=*max_element(nums.begin(),nums.end());
        vector<long long> count(m+1);
        for(auto num:nums)
        {
            count[num]++;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=i*2;j<=m;j+=i)
            {
                count[i]+=count[j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            count[i]=count[i]*(count[i]-1)/2;
        }
        for(int i=m;i>=1;i--)
        {
            for(int j=i*2;j<=m;j+=i)
            {
                count[i]-=count[j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            count[i]+=count[i-1];
        }
        vector<int> ans;
        for(auto q:queries)
        {
            q++;
            int pos=lower_bound(count.begin(),count.end(),q)-count.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};
