class Solution {
public:
    bool isValid(vector<vector<char>> &board,int row,int col,char digit)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==digit)
            {
                return false;
            }
            if(board[i][col]==digit)
            {
                return false;
            }
        }
        int sr=(row/3)*3,sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++)
        {
            for(int j=sc;j<sc+3;j++)
            {
                if(board[i][j]==digit)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board,int row,int col)
    {
        if(row==9)
        {
            return true;
        }
        int nr=row,nc=col+1;
        if(nc==9)
        {
            nr=row+1;
            nc=0;
        }
        if(board[row][col]!='.')
        {
            return helper(board,nr,nc);
        }
        for(char digit='1';digit<='9';digit++)
        {
            if(isValid(board,row,col,digit))
            {
                board[row][col]=digit;
                if(helper(board,nr,nc)==true)
                {
                    return true;
                }
                else
                {
                    board[row][col]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board,0,0);
    }
};
