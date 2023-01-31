class Solution {
public:
    int bestTeamScore(vector<int> &score,vector<int> &ages) 
    {
       int n=score.size(),age=0;
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       {
           v.push_back({ages[i],score[i]});
       }
       sort(v.begin(),v.end());
       vector<int>dp(n+1);
       for(int i=0;i<n;i++)
       {
           dp[i]=v[i].second;
           for(int j=0;j<i;j++)
           {
               if(v[i].second>=v[j].second)
               {
                   dp[i]=max(dp[j]+v[i].second,dp[i]);
               }
           }
           age=max(age,dp[i]);
       }
       return age;
    }
};
