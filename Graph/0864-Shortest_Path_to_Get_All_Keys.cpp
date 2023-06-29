class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) 
    {
        int m=grid.size(),n=grid[0].size(),bitStartIndex=0;
        unordered_map<char,int> keyBitMap;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(islower(grid[i][j]))
                {
                    keyBitMap[grid[i][j]]=bitStartIndex++;
                }
            }
        }
        int finalFormEnd=(1<<bitStartIndex)-1,finalFormSize=(1<<bitStartIndex);
        vector<vector<vector<bool>>> visitedMemo(m,vector<vector<bool>>(n,vector<bool>(finalFormSize,false)));

        vector<int> startingPoint;
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(grid[i][j]=='@')
                {
                    startingPoint={i,j,0};
                }
            }
        }
        queue<vector<int>> bfsQueue;
        bfsQueue.push(startingPoint);
        int stepCount=0;
        while(!bfsQueue.empty()) 
        {
            int levelSize=bfsQueue.size();
            for(int k=0;k<levelSize;k++) 
            {
                int currRow=bfsQueue.front()[0];
                int currCol=bfsQueue.front()[1];
                int currForm=bfsQueue.front()[2];
                bfsQueue.pop();
                if(currRow<0||currRow>=m||currCol<0||currCol>=n)
                {
                    continue;
                }
                if(grid[currRow][currCol]=='#')
                {
                    continue;
                }
                if(isupper(grid[currRow][currCol])) 
                {
                    if((currForm&(1<<keyBitMap[tolower(grid[currRow][currCol])]))==0)
                    {
                        continue;
                    }    
                }
                if(islower(grid[currRow][currCol])) 
                {
                    currForm=currForm|(1<<keyBitMap[grid[currRow][currCol]]);
                }
                if(currForm==finalFormEnd)
                {
                    return stepCount;
                }
                if(visitedMemo[currRow][currCol][currForm])
                {
                    continue;
                }
                visitedMemo[currRow][currCol][currForm]=true;
                bfsQueue.push({currRow+1,currCol,currForm});
                bfsQueue.push({currRow-1,currCol,currForm});
                bfsQueue.push({currRow,currCol+1,currForm});
                bfsQueue.push({currRow,currCol-1,currForm});
            }
            stepCount++;
        }
        return -1;
    }
};
