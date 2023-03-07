class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,r=1e14;
        while(l<=r) 
        {
            long long minTimeForTotalTrips=0;
            long long mid=l+(r-l)/2;
            for(int t:time)
            {
                minTimeForTotalTrips+=mid/t;
            }
            if(minTimeForTotalTrips>=totalTrips)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};