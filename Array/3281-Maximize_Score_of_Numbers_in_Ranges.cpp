class Solution {
public:
    bool canAchieve(vector<int> &start,int d,int score) 
    {
        long long lastPosition=start[0];
        for(int i=1;i<start.size();i++) 
        {
            if(lastPosition+score<=start[i]+d) 
            {
                lastPosition=max(lastPosition+score,static_cast<long long>(start[i]));
            } 
            else 
            {
                return false;
            }
        }
        return true;
    }
    int maxPossibleScore(vector<int> &start,int d) 
    {
        sort(start.begin(), start.end());
        int l=1,r=start.back()+d-start[0],maxScore=0;
        while(l<=r) 
        {
            int mid=l+(r-l)/2;
            if(canAchieve(start,d,mid)) 
            {
                maxScore=mid;
                l=mid+1;
            } 
            else 
            {
                r=mid-1;
            }
        }
        return maxScore;
    }
};
