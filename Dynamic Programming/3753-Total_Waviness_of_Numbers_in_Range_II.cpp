class Solution {
public:
    string s;
    long long dp[18][11][11][2][2][2];
    bool vis[18][11][11][2][2];
    pair<long long,long long> solve(int idx,int pp,int p,bool tight,bool lead)
    {
        if(idx==s.size())
        {
            return {1,0};
        }
        if(vis[idx][pp][p][tight][lead])
        {
            return {dp[idx][pp][p][tight][lead][0],dp[idx][pp][p][tight][lead][1]};
        }
        vis[idx][pp][p][tight][lead]=true;
        long long cnt=0,wave=0;
        int lim=tight?s[idx]-'0':9;
        for(int d=0;d<=lim;d++)
        {
            bool ntight=tight && (d==lim),nlead=lead && (d==0),wavy=false;
            int np=nlead?10:d,npp=nlead?10:(lead?10:p);
            if(pp!=10 && p!=10)
            {
                if((pp<p && p>d) || (pp>p && p<d))
                {
                    wavy=true;
                }
            }
            auto [c,w]=solve(idx+1,npp,np,ntight,nlead);
            cnt+=c;
            wave+=w+(wavy?c:0);
        }
        dp[idx][pp][p][tight][lead][0]=cnt;
        dp[idx][pp][p][tight][lead][1]=wave;
        return {cnt,wave};
    }
    long long calc(long long num)
    {
        if(num<100) 
        {
            return 0;
        }
        s=to_string(num);
        memset(vis,0,sizeof(vis));
        return solve(0,10,10,1,1).second;
    }
    long long totalWaviness(long long num1,long long num2)
    {
        return calc(num2)-calc(num1-1);
    }
};
