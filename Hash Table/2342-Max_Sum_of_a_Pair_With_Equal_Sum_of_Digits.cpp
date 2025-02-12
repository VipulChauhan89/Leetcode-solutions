class Solution {
public:
    int maximumSum(vector<int> &nums) 
    {
        unordered_map<int,int> m;
        int ans=-1;
        for(auto &i:nums)
        {
            int sum=0,temp=i;
            while(temp!=0)
            {
                sum+=temp%10;
                temp/=10;
            }
            if(m[sum]!=0)
            {
                ans=max(ans,i+m[sum]);
            }
            m[sum]=max(m[sum],i);
        }
        return ans;
    }
};
