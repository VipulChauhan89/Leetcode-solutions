class Solution {
public:
    int countPartitions(vector<int> &nums,int k)
    {
        int MOD=1e9+7,n=nums.size(),l=0,r=0;;
        multiset<int> currNums;
        vector<int> ways(n+1);
        ways[0]=1;
        long long currWays=1;
        while(r<n)
        {
            currNums.insert(nums[r]); 
            while((*currNums.rbegin())-(*currNums.begin())>k)
            {
                currNums.erase(currNums.find(nums[l]));
                currWays-=ways[l];
                l++;
                if(currWays<0)
                {
                    currWays+=MOD;
                }
            }
            ways[r+1]=currWays; 
            currWays+=ways[r+1];
            ways[r+1]%=MOD;
            currWays%=MOD;
            r++;                
        }
        return ways[n];
    }
};
