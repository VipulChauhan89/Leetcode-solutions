class Solution {
public:
    static constexpr int mod=1e9+7;
    unordered_set<int> seen;
    int maxL=0;
    void findLen(vector<int> &fences,int sz,bool calM)
    {
        sort(fences.begin(),fences.end());
        for(int l=0;l<sz-1;l++)
        {
            int L=fences[l];
            for(int r=l+1;r<sz;r++)
            {
                int Len=fences[r]-L;
                if(calM)
                {
                    if(Len>maxL && seen.count(Len))
                    {
                        maxL=Len;
                    }
                }
                else
                {
                    seen.insert(Len);
                }
            }
        }
    }
    int maximizeSquareArea(int m,int n, vector<int> &hFences,vector<int> &vFences)
    {
        int hz=hFences.size()+2,
        vz=vFences.size()+2;
        if(hz>vz)
        {
           return maximizeSquareArea(n,m,vFences,hFences);
        }
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        seen.reserve(hz*(hz-1));
        findLen(hFences,hz,0);
        findLen(vFences,vz,1);
        return (maxL==0)?-1:(long long)maxL*maxL%mod;
    }
};
