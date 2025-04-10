class Solution {
public:
    long long solve(long long value,int limit,string s)
    {
        string s1=to_string(value);
        int prefix=s1.length()-s.length();
        if(prefix<0)
        {
            return 0;
        }
        vector<vector<long long>> v(prefix+1,vector<long long>(2,0));
        v[prefix][0]=1;
        v[prefix][1]=((s1.substr(prefix)>=s)?1:0);
        for(int i=prefix-1;i>=0;i--)
        {
            int current=s1[i]-'0';
            v[i][0]=(limit+1)*v[i+1][0];
            if(current<=limit)
            {
                v[i][1]=(long long)current*v[i+1][0]+v[i+1][1];
            }
            else
            {
                v[i][1]=(long long)(limit+1)*v[i+1][0];
            }
        }
        return v[0][1];
    }
    long long numberOfPowerfulInt(long long start,long long finish,int limit,string s) 
    {
        return solve(finish,limit,s)-solve(start-1,limit,s);
    }
};
