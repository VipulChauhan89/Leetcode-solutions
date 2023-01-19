class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n=nums.size(),count=0,sum=0,rem;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
            {
                rem+=k;
            } 
            if(m.find(rem)!=m.end())
            {
                count+=m[rem];
            }
            m[rem]++;
        }  
        return count; 
    }
};
