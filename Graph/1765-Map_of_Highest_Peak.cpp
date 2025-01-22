class Solution {
public:
    bool isValid(int i,int j,int n,int m) 
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) 
    {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        vector<int> direction={-1,0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                if(isWater[i][j]==1) 
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()) 
        {
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++) 
            {
                int newX=x+direction[d];
                int newY=y+direction[d+1];
                if(isValid(newX,newY,n,m) && ans[newX][newY]==-1) 
                {
                    ans[newX][newY]=ans[x][y]+1;
                    q.push({newX,newY});
                }
            }
        }
        return ans;
    }
};
