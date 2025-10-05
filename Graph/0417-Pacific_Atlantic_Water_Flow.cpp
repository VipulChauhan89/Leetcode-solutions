class Solution {
public:
    int rows,cols;
    vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,vector<vector<int>> &heights,vector<vector<bool>> &visited,int prevHt)
    {
        if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c] || heights[r][c]<prevHt)
        {
            return;
        }
        visited[r][c]=true;
        for(auto &i:direction)
        {
            dfs(r+i[0],c+i[1],heights,visited,heights[r][c]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<bool>> pacific(rows,vector<bool>(cols,false)),atlantic(rows,vector<bool>(cols,false));
        vector<vector<int>> ans;
        for(int c=0;c<cols;c++)
        {
            dfs(0,c,heights,pacific,heights[0][c]);
            dfs(rows-1,c,heights,atlantic,heights[rows-1][c]);
        }
        for(int r=0;r<rows;r++)
        {
            dfs(r,0,heights,pacific,heights[r][0]);
            dfs(r,cols-1,heights,atlantic,heights[r][cols-1]);
        }
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(pacific[r][c] && atlantic[r][c])
                {
                    ans.push_back({r,c});
                }
            } 
        }
        return ans;
    }
};
