class Solution {
public:
    int dist(vector<vector<int>> &pos,int a,int b)
    {
        return abs(pos[a][0]-pos[b][0])+abs(pos[a][1]-pos[b][1]);
    }
    int minimumDistance(string word)
    {
        int n=word.size();
        vector<vector<int>> pos(26,vector<int>(2));
        for(int i=0;i<26;i++)
        {
            pos[i][0]=i/6;
            pos[i][1]=i%6;
        }
        int total=0;
        vector<int> dp(26,0);
        for(int i=1;i<n;i++)
        {
            int prev=word[i-1]-'A',curr=word[i]-'A';
            int d=dist(pos,prev,curr);
            total+=d;
            vector<int> next(26,0);
            for(int c=0;c<26;c++)
            {
                next[c]=max(next[c],dp[c]);
                int saving=d-dist(pos,c,curr);
                next[prev]=max(next[prev],dp[c]+saving);
            }
            dp=next;
        }
        int maxSave=0;
        for(int val:dp)
        {
            maxSave=max(maxSave,val);
        }
        return total-maxSave;
    }
};
