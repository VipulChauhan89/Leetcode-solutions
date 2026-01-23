class Solution {
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int n=nums.size(),ans=0,inversionsCount=0;
        vector<int> nextIndices(n),prevIndices(n);
        vector<long> values(nums.begin(),nums.end());
        auto comp=[](const pair<long,int> &a,const pair<long,int> &b)
        {
            return a.first<b.first || (a.first==b.first && a.second<b.second);
        };
        set<pair<long,int>, decltype(comp)> pairSums(comp);
        for(int i=0;i<n;i++)
        {
            nextIndices[i]=i+1;
            prevIndices[i]=i-1;
        }
        for(int i=0;i<n-1;i++)
        {
            pairSums.insert({(long)nums[i]+nums[i+1],i});
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                inversionsCount++;
            }
        }
        while(inversionsCount>0)
        {
            ans++;
            auto smallestPair=*pairSums.begin();
            pairSums.erase(pairSums.begin());
            long pairSum=smallestPair.first;
            int currIndex=smallestPair.second,nextIndex=nextIndices[currIndex],prevIndex=prevIndices[currIndex];
            if(prevIndex>=0)
            {
                long oldPairSum=values[prevIndex]+values[currIndex],newPairSum=values[prevIndex]+pairSum;
                pairSums.erase({oldPairSum,prevIndex});
                pairSums.insert({newPairSum,prevIndex});
                if(values[prevIndex]>values[currIndex])
                {
                    inversionsCount--;
                }
                if(values[prevIndex]>pairSum)
                {
                    inversionsCount++;
                }
            }
            if(values[nextIndex]<values[currIndex])
            {
                inversionsCount--;
            }
            int nextNextIndex=(nextIndex<n)?nextIndices[nextIndex]:n;
            if(nextNextIndex<n)
            {
                long oldPairSum=values[nextIndex]+values[nextNextIndex],newPairSum=pairSum+values[nextNextIndex];
                pairSums.erase({oldPairSum,nextIndex});
                pairSums.insert({newPairSum,currIndex});
                if(values[nextNextIndex]<values[nextIndex])
                {
                    inversionsCount--;
                }
                if(values[nextNextIndex]<pairSum)
                {
                    inversionsCount++;
                }
                prevIndices[nextNextIndex]=currIndex;
            }
            nextIndices[currIndex]=nextNextIndex;
            values[currIndex]=pairSum;
        }
        return ans;
    }
};

