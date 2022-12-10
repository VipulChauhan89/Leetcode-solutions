class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    string r="row"+to_string(i)+board[i][j];
                    string c="col"+to_string(j)+board[i][j];
                    string b="block"+to_string((i/3)*3+j/3)+board[i][j];
                    if(s.find(r)!=s.end() || s.find(c)!=s.end())
                    {
                        return false;
                    }
                    if(s.find(b)!=s.end())
                    {
                        return false;
                    }
                    s.insert(r);
                    s.insert(c);
                    s.insert(b);
                }
                
            }
        }
        return true;
    }
};
