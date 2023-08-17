class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) 
    {
        if(mat.empty() || mat[0].empty())
        {
            return {};
        }
        int m=mat.size(),n=mat[0].size();
        queue<pair<int,int>> queue;
        int MAX_VALUE=m*n;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(mat[i][j]==0) 
                {
                    queue.push({i,j});
                } 
                else 
                {
                    mat[i][j]=MAX_VALUE;
                }
            }
        }
        vector<pair<int, int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!queue.empty()) 
        {
            auto [row,col]=queue.front();
            queue.pop();
            for(auto [dr,dc]:directions) 
            {
                int r=row+dr,c=col+dc;
                if(r>=0 && r<m && c>=0 && c<n && mat[r][c]>mat[row][col]+1) 
                {
                    queue.push({r,c});
                    mat[r][c]=mat[row][col]+1;
                }
            }
        }
        return mat;
    }
};
