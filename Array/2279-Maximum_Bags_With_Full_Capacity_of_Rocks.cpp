class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n=capacity.size();
        for(int i=0;i<n;i++)
        {
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(capacity[i]==0)
            { 
                count++;
                continue;
            }
            additionalRocks-=capacity[i];
            if(additionalRocks>=0)
            {
                count++;
            } 
            else
            {
                break;
            } 
        }
        return count;
    }
};
