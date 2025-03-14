class Solution {
public:
    int maximumCandies(vector<int> &candies,long long k) 
    {
        int ans=0;    
        long long l=1,r=*max_element(candies.begin(),candies.end());
        while(l<=r)
        {
            long long mid=l+(r-l)/2,count=0;
            for(auto i:candies)
            {
                count+=i/mid;
            }
            if(count>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
