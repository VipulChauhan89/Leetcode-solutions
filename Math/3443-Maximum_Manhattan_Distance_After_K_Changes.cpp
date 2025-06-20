class Solution {
public:
    int maxDistance(string s,int k)
    {
        int ans=0;
        unordered_map<char,int> m;
        for(auto &i:s)
        {
            m[i]++;
            int horizontal=abs(m['W']-m['E']),vertical=abs(m['N']-m['S']),dist=horizontal+vertical;
            int mn=min(m['W'],m['E'])+min(m['N'],m['S']),mxDis=(min(k,mn)*2)+dist;
            ans=max(ans,mxDis);
        }
        return ans;
    }
};
