class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums) 
    {
        unordered_set<int> distinct(nums.begin(),nums.end());
        int total=distinct.size(),count=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            unordered_set<int> s;
            for(int j=i;j<n;j++)
            {
                s.insert(nums[j]);
                if(s.size()==total)
                {
                    count+=(n-j);
                    break;
                }
            }
        }
        return count;
    }
};
