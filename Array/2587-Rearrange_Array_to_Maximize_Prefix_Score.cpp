class Solution {
public:
    int maxScore(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        int score=0;
        long long int prefix_sum=0;
        for(int num:nums) 
        {
            prefix_sum+=num;
            if(prefix_sum>0) 
            {
                score++;
            }
        }
        return score;
    }
};
