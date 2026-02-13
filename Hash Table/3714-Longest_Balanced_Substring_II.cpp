class Solution {
public:
    int longestBalanced(string s)
    {
        int n=s.size();
        int ans=0,a=0,b=0,c=0,run=1;
        map<pair<int,int>,int> mp;
        map<int,int> mpab,mpac,mpbc;
        mp[{0,0}]=-1;
        mpab[0]=-1;
        mpac[0]=-1;
        mpbc[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                mpbc.clear();
                a++;
            }
            else if(s[i]=='b')
            {
                mpac.clear();
                b++;
            }
            else
            {
                mpab.clear();
                c++;
            }
            if(mpab.count(a-b))
            {
                ans=max(ans,i-mpab[a-b]);
            }
            else
            {
                mpab[a-b]=i;
            }
            if(mpac.count(a-c))
            {
                ans=max(ans,i-mpac[a-c]);
            }
            else
            {
                mpac[a-c]=i;
            }
            if(mpbc.count(b-c))
            {
                ans=max(ans,i-mpbc[b-c]);
            }
            else
            {
                mpbc[b-c]=i;
            }
            if(mp.count({a-b,a-c}))
            {
                ans=max(ans,i-mp[{a-b,a-c}]);
            }
            else
            {
                mp[{a-b,a-c}]=i;
            }
            if(i!=0 && s[i]==s[i-1])
            {
                run++;
            }
            else
            {
                run=1;
            }
            ans=max(ans,run);
        }
        return ans;
    }
};
