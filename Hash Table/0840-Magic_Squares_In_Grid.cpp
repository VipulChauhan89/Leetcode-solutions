class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int rows=grid.size(),cols=grid[0].size(),count=0;
        if(rows<3 || cols<3)
        {
            return 0;
        }
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                bool isDistinct=true;
                vector<int> check(10,0);
                for(int k=i-1;k<=i+1;k++)
                {
                    for(int l=j-1;l<=j+1;l++)
                    {
                        int val=grid[k][l];
                        if(val<1 || val>9 || check[val]>0)
                        {
                            isDistinct=false;
                            break;
                        }
                        check[val]++;
                    }
                }
                if(!isDistinct)
                {
                    continue;
                }
                int r1=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1],r2=grid[i][j-1]+grid[i][j]+grid[i][j+1],r3=grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                int c1=grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1],c2=grid[i-1][j]+grid[i][j]+grid[i+1][j],c3=grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1];
                int d1=grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1],d2=grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1];
                unordered_map<int,int> mp;
                mp[r1]++;
                mp[r2]++;
                mp[r3]++;
                mp[c1]++;
                mp[c2]++;
                mp[c3]++;
                mp[d1]++;
                mp[d2]++;
                if(mp.size()==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
