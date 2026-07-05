class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size(),MOD=1e9+7;
        vector<pair<int,int>> below(n,{-1,0});
        vector<pair<int,int>> cur(n,{-1,0});
        for(int i=n-1;i>=0;i--)
        {
            fill(cur.begin(),cur.end(),make_pair(-1,0));
            for(int j=n-1;j>=0;j--)
            {
                if(i==n-1 && j==n-1)
                {
                    cur[j]={0,1};
                    continue;
                }
                if(board[i][j]=='X')
                {
                    continue;
                }
                int best=-1;
                if(i+1<n)
                {
                    best=max(best,below[j].first);
                }
                if(j+1<n)
                {
                    best=max(best,cur[j+1].first);
                }
                if(i+1<n && j+1<n)
                {
                    best=max(best,below[j+1].first);
                }
                if(best==-1)
                {
                    continue;
                }
                long long count=0;
                if(i+1<n && below[j].first==best)
                {
                    count+=below[j].second;
                }
                if(j+1<n && cur[j+1].first==best)
                {
                    count+=cur[j+1].second;
                }
                if(i+1<n && j+1<n && below[j+1].first==best)
                {
                    count+=below[j+1].second;
                }
                count%=MOD;
                int val=(board[i][j]=='E')?0:board[i][j]-'0';
                cur[j]={best+val,(int)count};
            }
            below=cur;
        }
        if(below[0].first==-1)
        {
            return {0,0};
        }
        return {below[0].first,below[0].second};
    }
};
