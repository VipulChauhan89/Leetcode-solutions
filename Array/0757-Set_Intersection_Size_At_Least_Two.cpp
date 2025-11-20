class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]!=b[1])
        {
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(),intervals.end(),comp);
        int s1=-1,s2=-1,ans=0;
        for(auto &v:intervals)
        {
            int l=v[0],r=v[1];
            if(l<=s1 && s2<=r)
            {
                continue;
            }
            if(l<=s2) 
            {
                ans+=1;
                s1=s2;
                s2=r;
            }
            else 
            {
                ans+=2;
                s1=r-1;
                s2=r;
            }
        }
        return ans;
    }
};
