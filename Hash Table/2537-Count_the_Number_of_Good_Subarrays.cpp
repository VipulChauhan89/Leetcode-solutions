class Solution {
public:
    long long countGood(vector<int> &nums,int k) 
    {
        long long count=0;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0,j=0;i<n;i++)
        {
            k-=m[nums[i]]++;
            while(k<=0)
            {
                k+=--m[nums[j++]];
            }
            count+=j;
        }
        return count;
    }
};
