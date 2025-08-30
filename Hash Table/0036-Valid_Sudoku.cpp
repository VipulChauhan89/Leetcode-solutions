class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n=9;
        vector<unordered_set<int>> r(n),c(n),b(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0';
                    int bindex=floor(i/3)*3+floor(j/3);
                    if(r[i].count(num))
                    {
                        return false;
                    }
                    if(c[j].count(num))
                    {
                        return false;
                    }
                    if(b[bindex].count(num))
                    {
                        return false;
                    }
                    r[i].insert(num);
                    c[j].insert(num);
                    b[bindex].insert(num);
                }
            }
        }
        return true;
    }
};
