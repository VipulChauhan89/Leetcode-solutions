class Solution {
public:
    int maxDifference(string s,int k) 
    {
        int n=s.size(),ans=INT_MIN;
        for(int a=0;a<=4;a++) 
        {
            for(int b=0;b<=4;b++) 
            {
                if(a==b)
                {
                    continue;
                }
                vector<int> s1(n+1),s2(n+1);
                vector<vector<int>>g={{INT_MIN,INT_MIN},{INT_MIN,INT_MIN}};
                for(int i=1;i<=n;i++) 
                {
                    s1[i]=s1[i-1]+(s[i-1]-'0'==a);
                    s2[i]=s2[i-1]+(s[i-1]-'0'==b);
                }
                int j=0;
                for(int i=k;i<=n;i++) 
                {
                    while(i-j>=k && s1[i]>s1[j] && s2[i]>s2[j]) 
                    {
                        int pa=s1[j]%2,pb=s2[j]%2;
                        g[pa][pb]=max(g[pa][pb],s2[j]-s1[j]);
                        j++;
                    }
                    int pa=s1[i]%2,pb=s2[i]%2,need=g[1-pa][pb];
                    if(need!=INT_MIN) 
                    {
                        ans=max(ans,(s1[i]-s2[i])+need);
                    }
                }
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};
