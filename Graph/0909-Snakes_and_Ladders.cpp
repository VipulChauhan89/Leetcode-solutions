class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) 
    {
        int n=board.size();
        vector<int> mn(n*n+1,-1);
        queue<int> q;
        mn[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=1;i<=6 && x+i<=n*n;i++)
            {
                int t=x+i,r=(t-1)/n,c=(t-1)%n,v=board[n-1-r][r%2?n-1-c:c],y=v>0?v:t;
                if(y==n*n)
                {
                    return mn[x]+1;
                }
                if(mn[y]==-1)
                {
                    mn[y]=mn[x]+1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};
