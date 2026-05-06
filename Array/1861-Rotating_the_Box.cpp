class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int rows=boxGrid.size(),cols=boxGrid[0].size();
        for(int r=0;r<rows;r++)
        {
            int p=0;
            for(int c=0;c<cols;c++)
            {
                if(boxGrid[r][c]=='.')
                {
                    swap(boxGrid[r][c],boxGrid[r][p]);
                    p++;
                }
                else if(boxGrid[r][c]=='*')
                {
                    p=c+1;
                }
            }
        }
        vector<vector<char>> res(cols,vector<char>(rows));
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                res[c][rows-1-r]=boxGrid[r][c];
            }
        }    
        return res;
    }
};
