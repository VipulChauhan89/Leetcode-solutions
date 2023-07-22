class Solution {
public:
    unordered_map<string,double> m;
    int move[8][2]={{-2,-1},{-1,-2},{1,-2},{-1,2},{1,2},{2,1},{2,-1},{-2,1}};
    double find(int n,int moves,int r,int c)
    {
        if(r<0 || r>=n || c<0 || c>=n)
        {
            return 0;
        }
        if(moves==0)
        {
            return 1;
        }
        string k=to_string(r)+"0"+to_string(c)+"0"+to_string(moves);
        if(m.find(k)!=m.end())
        {
            return m[k];
        }
        double probability=0;
        for(int i=0;i<8;i++)
        {
            probability+=find(n,moves-1,r+move[i][0],c+move[i][1])/8.0;
        }
        m[k]=probability;
        return m[k];
    }
    double knightProbability(int n,int k,int row,int column) 
    {
        return find(n,k,row,column);
    }
};
