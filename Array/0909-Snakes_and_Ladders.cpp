class Solution {
public:
    pair<int,int> cordinate(int x,int n)
    {
        int r=n-1-(x-1)/n;
        int c=(x-1)%n;
        return (r%2==n%2)?make_pair(r,n-c-1):make_pair(r,c);
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size(),step=0;
        queue<int> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push(1);
        visited[n-1][0]=true;
        while(q.size()!=0)
        {
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                int y=q.front();
                if(y==n*n)
                {
                    return step;
                }
                q.pop();
                for(int j=1;j<=6;j++)
                {
                    if(j+y>n*n)
                    {
                        break;
                    }
                    pair<int,int> p=cordinate(y+j,n);
                    if(visited[p.first][p.second])
                    {
                        continue;
                    }
                    visited[p.first][p.second]=true;
                    if(board[p.first][p.second]!=-1)
                    {
                        q.push(board[p.first][p.second]);
                    }
                    else
                    {
                        q.push(j+y);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
