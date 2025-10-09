class Solution {
public:
    long long minTime(vector<int> &skill,vector<int> &mana)
    {
        int n=skill.size();
        vector<long long> time(n,0);
        for(auto &i:mana)
        {
            time[0]=time[0]+skill[0]*1LL*i;
            for(int j=1;j<n;j++)
            {
                time[j]=max(time[j],time[j-1])+skill[j]*1LL*i;
            }
            for(int j=n-2;j>=0;j--)
            {
                time[j]=time[j+1]-skill[j+1]*1LL*i;
            }
        }
        return time[n-1];
    }
};
