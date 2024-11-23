class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) 
    {
        int r=box.size(),c=box[0].size();
        vector<vector<char>> ans(c,vector<char>(r,'.'));
        for(int i=0;i<r;i++)
        {
            int k=c-1;
            for (int j=c-1;j>=0;j--)
            {
                if(box[i][j]=='#')
                {
                    ans[k][r-i-1]='#';
                    k--;
                }
                else if(box[i][j]=='*')
                {
                    ans[j][r-i-1]='*';
                    k=j-1;
                }
            }
        }
        return ans;
    }
};
