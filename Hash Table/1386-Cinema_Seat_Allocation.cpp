class Solution {
public:
    bool check(vector<bool> &reserved,int l,int r)
    {
        for(int i=l;i<=r;i++)
        {
            if(reserved[i])
            {
                return false;
            }
        }
        return true;
    }
    int maxNumberOfFamilies(int n,vector<vector<int>> &reservedSeats)
    {
        sort(reservedSeats.begin(),reservedSeats.end());
        int m=reservedSeats.size(),ans=0,l=0,r=0,prev=0;
        vector<bool> reserved(11,false);
        while(r<m)
        {
            ans+=2*(reservedSeats[r][0]-prev-1);
            prev=reservedSeats[r][0];
            while(r<m && reservedSeats[r][0]==reservedSeats[l][0])
            {
                reserved[reservedSeats[r][1]]=true;
                r++;
            }
            bool twoToFive=check(reserved,2,5);
            bool fourToSeven=check(reserved,4,7);
            bool sixToNine=check(reserved,6,9);
            if(twoToFive && sixToNine)
            {
                ans+=2;
            }
            else if(twoToFive || fourToSeven || sixToNine)
            {
                ans++;
            }
            l=r;
            fill(reserved.begin(),reserved.end(),false);
        }
        ans+=2*(n-prev);
        return ans;
    }
};
